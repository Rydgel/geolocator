#include "SocketServer.h"

SocketServer::SocketServer(asio::io_service& io_service, const std::string& file)
: acceptor_(io_service, asio::local::stream_protocol::endpoint(file))
, socket_(io_service)
, protocol_(cs_, rs_)
{
    printf("Init socket server\n");
    currentLimit = 0;
    doAccept();
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"
void SocketServer::doAccept()
{
    // std::cout << "start accepting connection" << std::endl;
    acceptor_.async_accept(socket_, [this](std::error_code ec) {
        if (!ec) {
            currentLimit ++;
            // printf("Current session count: %d\n", currentLimit.load());
            auto movedSession = std::make_shared<SocketSession>(std::move(socket_), protocol_, currentLimit);
            movedSession->start();
        }
        doAccept();
    });
}

#pragma clang diagnostic pop
