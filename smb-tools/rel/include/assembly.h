#pragma once

#include <cstdint>

namespace mod {

extern "C" {

// Assembly overwrite functions
// main.cpp
void startMainLoopAssembly();

// Functions accessed by assembly overwrites
// main.cpp
void runMain();

}

}