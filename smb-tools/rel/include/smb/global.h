#pragma once

#include <cstdint>

namespace smb::global {

extern "C" {

extern int32_t charaHeapHandle;
extern int32_t backgroundHeapHandle;
extern int32_t stageHeapHandle;
extern int32_t subHeapHandle;
extern int32_t mainHeapHandle;

extern uint32_t debugBitfield;

}

}