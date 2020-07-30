#include "mod.h"
#include "assembly.h"

#include <gc/OSModule.h>
#include <smb/global.h>

namespace mod {

bool Mod::performRelPatches(gc::OSModule::OSModuleInfo *newModule, void *bss)
{
	// Call the original function immediately, as the REL file should be linked before applying patches
	const bool result = mPFN_OSLink_trampoline(newModule, bss);
	
	// Make sure a REL file is currently loaded
	if (!result)
	{
		return result;
	}
	
	// uint32_t NewModuleRaw = reinterpret_cast<uint32_t>(newModule);
	switch (newModule->id)
	{
		default:
		{
			return result;
		}
	}
}

void enableDebugMode()
{
	/* Should check to see if this value ever gets cleared. 
		If not, then the value should only be set once */
	if (smb::global::debugBitfield == 0)
	{
		smb::global::debugBitfield |= (1 << 0); // Set the 0 bit
	}
}

void runMain()
{
	// Make sure debug mode is enabled
	enableDebugMode();
}

}