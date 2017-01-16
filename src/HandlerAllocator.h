#ifndef GEOLOCATOR_HANDLERALLOCATOR_H
#define GEOLOCATOR_HANDLERALLOCATOR_H

#include <array>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>
#include <asio.hpp>


class HandlerAllocator
{
private:
    // Storage space used for handler-based custom memory allocation.
    typename std::aligned_storage<1024>::type storage_;
    // Whether the handler-based custom allocation storage has been used.
    bool in_use_;
public:
    HandlerAllocator();
    HandlerAllocator(const HandlerAllocator&) = delete;
    HandlerAllocator& operator=(const HandlerAllocator&) = delete;
    void* allocate(std::size_t size);
    void deallocate(void* pointer);
};


#endif //GEOLOCATOR_HANDLERALLOCATOR_H
