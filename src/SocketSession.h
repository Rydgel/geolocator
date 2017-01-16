#ifndef GEOLOCATOR_SOCKETSESSION_H
#define GEOLOCATOR_SOCKETSESSION_H

#include <array>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>
#include <asio.hpp>
#include <future>
#include "HandlerAllocator.h"
#include "Protocol.h"
#include "SocketServer.h"

// Wrapper class template for handler objects to allow handler memory
// allocation to be customised. Calls to operator() are forwarded to the
// encapsulated handler.
template <typename Handler>
class custom_alloc_handler
{
public:
    custom_alloc_handler(HandlerAllocator& a, Handler h)
            : allocator_(a),
              handler_(h)
    {
    }

    template <typename ...Args>
    void operator()(Args&&... args)
    {
        handler_(std::forward<Args>(args)...);
    }

    friend void* asio_handler_allocate(std::size_t size,
                                       custom_alloc_handler<Handler>* this_handler)
    {
        return this_handler->allocator_.allocate(size);
    }

    friend void asio_handler_deallocate(void* pointer, std::size_t /*size*/,
                                        custom_alloc_handler<Handler>* this_handler)
    {
        this_handler->allocator_.deallocate(pointer);
    }

private:
    HandlerAllocator& allocator_;
    Handler handler_;
};

// Helper function to wrap a handler object to add custom allocation.
template <typename Handler>
inline custom_alloc_handler<Handler> make_custom_alloc_handler(
        HandlerAllocator& a, Handler h)
{
    return custom_alloc_handler<Handler>(a, h);
}

class SocketSession : public std::enable_shared_from_this<SocketSession>
{
private:
    // The socket used to communicate with the client.
    asio::local::stream_protocol::socket socket_;
    // Buffer used to store data received from the client.
    std::array<char, 1024> data_;
    // The allocator to use for handler-based custom memory allocation.
    HandlerAllocator allocator_;
    Protocol &protocol_;
    std::atomic<int> &currentLimit_;
    asio::steady_timer timer_;
    const int connectionLimit_ = 250;

    void doRead();
    void doWrite(std::string response);
public:
    SocketSession(asio::local::stream_protocol::socket socket, Protocol &protocol, std::atomic<int> &currentLimit);
    ~SocketSession();
    void start();
    void close();
};


#endif //GEOLOCATOR_SOCKETSESSION_H
