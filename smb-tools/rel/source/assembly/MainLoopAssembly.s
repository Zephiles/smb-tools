.global startMainLoopAssembly

#ifdef SMB_US
offset = -0x64B8
#elif defined SMB_JP
offset = -0x6518
#elif defined SMB_EU
offset = -0x5D38
#endif

startMainLoopAssembly:
stwu %sp,-0x10(%sp)
mflr %r0
stw %r0,0x14(%sp)

bl runMain

lwz %r0,0x14(%sp)
mtlr %r0
addi %sp,%sp,0x10

# Restore the overwritten instruction
lwz %r0,offset(%r13)
blr