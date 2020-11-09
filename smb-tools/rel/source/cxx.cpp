#include <gc/OSAlloc.h>
#include <gc/OSCache.h>
#include <smb/global.h>

#include <cstring>

void *operator new(std::size_t size)
{
    int32_t heapHandle = smb::global::mainHeapHandle;
    void *newPtr = gc::OSAlloc::OSAllocFromHeap(heapHandle, size);
    memset(newPtr, 0, size);
    gc::OSCache::DCFlushRange(newPtr, size);
    return newPtr;
}
void *operator new[](std::size_t size)
{
    int32_t heapHandle = smb::global::mainHeapHandle;
    void *newPtr = gc::OSAlloc::OSAllocFromHeap(heapHandle, size);
    memset(newPtr, 0, size);
    gc::OSCache::DCFlushRange(newPtr, size);
    return newPtr;
}
void operator delete(void *ptr)
{
    int32_t heapHandle = smb::global::mainHeapHandle;
    gc::OSAlloc::OSFreeToHeap(heapHandle, ptr);
}
void operator delete[](void *ptr)
{
    int32_t heapHandle = smb::global::mainHeapHandle;
    gc::OSAlloc::OSFreeToHeap(heapHandle, ptr);
}
void operator delete(void *ptr, std::size_t size)
{
    int32_t heapHandle = smb::global::mainHeapHandle;
    gc::OSAlloc::OSFreeToHeap(heapHandle, ptr);
}
void operator delete[](void *ptr, std::size_t size)
{
    int32_t heapHandle = smb::global::mainHeapHandle;
    gc::OSAlloc::OSFreeToHeap(heapHandle, ptr);
}
