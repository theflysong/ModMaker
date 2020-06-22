#ifndef __BLOCKS__
#define __BLOCKS__

#include "head.h"

const string BasicBlock=(string)
"public class %CLASSNAME% extends Block {\n\
    public %CLASSNAME%() {\n\
        super(%MATERIAL%);\n\
        this.setUnlocalizedName(\"%UNLOACALIZED_NAME%\");\n\
        this.setRegistryName(\"%REGISTRY_NAME%\");\n\
        this.setHardness(%HARDNESS%);\n\
        this.setCreativeTab(%CREATIVETABS%);\n\
        this.setLightLevel(%LIGHTLEVEL%F);\n\
    }\n\
}";

void MakeBasicBlock();

#endif 
