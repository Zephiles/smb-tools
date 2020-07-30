## Credits
* **PistonMiner** for their work on the initial code for the rel framework, elf2rel, and gcipack utilities. (GitHub repo for these tools [here](https://github.com/PistonMiner/ttyd-tools).)

## Overview
REL Loader for Super Monkey Ball. Ported from the REL Loader for Paper Mario: The Thousand-Year Door.

## Prerequisites
To build this, you need to have devkitPPC installed. Instructions for doing so can be found [here](https://devkitpro.org/wiki/Getting_Started). You also need to place **elf2rel.exe** in the **bin** folder. This file can either be compiled manually, or downloaded from [here](https://github.com/PistonMiner/ttyd-tools/releases/download/v2.7/elf2rel.exe).

## Building
To build, you must first add **DEVKITPPC** and **SMBTOOLS** to your environment. **DEVKITPPC** should be set to the `devkitPPC` folder, and **SMBTOOLS** should be set to the `smb-tools` folder. Then, navigate to the root directory of the repository (the folder with the makefile in it) and run `make`. Any combination of rules can be applied to this. You should also run `make clean` after making any changes, as files built with a previous build could cause issues.  

Examples of `make` being used:  
`make us`  
`make jp eu`  
`make us eu`  
