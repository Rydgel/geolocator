#include "SocketSession.h"

SocketSession::SocketSession(
        asio::local::stream_protocol::socket socket,
        Protocol &protocol,
        std::atomic<int> &currentLimit)
: socket_(std::move(socket))
, protocol_(protocol)
, currentLimit_(currentLimit)
, timer_(socket_.get_io_service())
{

}

void SocketSession::start()
{
    if (currentLimit_.load() > connectionLimit_) {
        printf("Too many clients connected. Connection refused\n");
    } else {
        doRead();
    }
}

void SocketSession::doRead()
{
    auto self(shared_from_this());
    // empty the buffer
    data_ = std::array<char, 1024>();
    // after read callback
    auto readSomeCallback = [this, self](std::error_code ec, std::size_t length) {
        if (!ec) {
            auto response = protocol_.getResponse(std::string(data_.data()));
            doWrite(response);
        }
    };

    // read timeout
    timer_.expires_from_now(std::chrono::seconds(5));
    timer_.async_wait([this](asio::error_code error) {
        if (!error) {
            close();
        }
    });

    socket_.async_read_some(asio::buffer(data_), make_custom_alloc_handler(allocator_, readSomeCallback));
}

void SocketSession::doWrite(std::string response)
{
    auto self(shared_from_this());
    auto writeCallback = [this, self](std::error_code ec, std::size_t _l) {
        if (!ec) {
            timer_.cancel();
            // doRead();
            // I am able to keep the connection open
        }
    };

    asio::async_write(socket_, asio::buffer(response), make_custom_alloc_handler(allocator_, writeCallback));
}

void SocketSession::close()
{
    try {
        if (socket_.is_open()) {
            socket_.close();
        }
    } catch (asio::system_error e) {
        // socket is already closed by the client
    }
}

SocketSession::~SocketSession()
{
    printf("Session closed \n");
    currentLimit_ --;
}
