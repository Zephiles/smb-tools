#pragma once

#include <gc/OSModule.h>

#include <cstdint>

namespace mod {

class Mod
{
public:
	Mod();
	void init();

private:
	void runMain();
	bool performRelPatches(gc::OSModule::OSModuleInfo *, void *);
	
private:
	void (*mPFN_runMain_trampoline)() = nullptr;
	bool (*mPFN_OSLink_trampoline)(gc::OSModule::OSModuleInfo *, void *) = nullptr;
};

}