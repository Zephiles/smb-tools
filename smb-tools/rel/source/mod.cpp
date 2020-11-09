#include "mod.h"
#include "patch.h"
#include "assembly.h"

#include <gc/OSModule.h>

namespace mod {

Mod *gMod = nullptr;

void main()
{
    Mod *mod = new Mod();
    mod->init();
}

Mod::Mod()
{
    
}

void Mod::init()
{
    gMod = this;
    
#ifdef SMB_US
    void *runMainAddress = reinterpret_cast<void *>(0x800066A0);
#elif defined SMB_JP
    void *runMainAddress = reinterpret_cast<void *>(0x800066A0);
#elif defined SMB_EU
    void *runMainAddress = reinterpret_cast<void *>(0x80006708);
#endif
    
    // Inject the runMain function at the start of the main game loop
    patch::writeBranchBL(runMainAddress, reinterpret_cast<void *>(startMainLoopAssembly));
    
    /*
    mPFN_OSLink_trampoline = patch::hookFunction(
        gc::OSModule::OSLink, [](gc::OSModule::OSModuleInfo *newModule, void *bss)
    {
        return gMod->performRelPatches(newModule, bss);
    });
    */
}

}