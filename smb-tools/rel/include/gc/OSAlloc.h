#pragma once

#include <cstdint>

namespace gc::OSAlloc {

extern "C" {

void *OSAllocFromHeap(int32_t heapHandle, uint32_t size);
void OSFreeToHeap(int32_t heapHandle, void *ptr);

}

}