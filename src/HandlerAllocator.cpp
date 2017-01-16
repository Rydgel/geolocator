#include "HandlerAllocator.h"

HandlerAllocator::HandlerAllocator()
: in_use_(false)
{

}

void *HandlerAllocator::allocate(std::size_t size)
{
    if (!in_use_ && size < sizeof(storage_)) {
        in_use_ = true;
        return &storage_;
    } else {
        return ::operator new(size);
    }
}

void HandlerAllocator::deallocate(void *pointer)
{
    if (pointer == &storage_) {
        in_use_ = false;
    } else {
        ::operator delete(pointer);
    }
}
