#ifndef __ITEMS__
#define __ITEMS__

#include "head.h"

const string BasicItem=(string)
"public class %CLASSNAME% extends Item {\n\
    public %CLASSNAME%()\n\
    {\n\
    	super();\n\
        this.setRegistryName(\"%REGISTRY_NAME%\");\n\
        this.setUnlocalizedName(\"%UNLOACALIZED_NAME%\");\n\
        this.setCreativeTab(%CREATIVETABS%);\n\
    }\n\
}\n"; 

const string BasicItemFood=(string)
"public class %CLASSNAME% extends ItemFood {\n\
    public %CLASSNAME%() {\n\
        super(%HEALAMOUNT%, %SATURATION%, false);\n\
        this.setRegistryName(\"%REGISTRY_NAME%\");\n\
        this.setUnlocalizedName(\"%UNLOACALIZED_NAME%\");\n\
        this.setCreativeTab(CreativeTabs.FOOD);\n\
    }\n\
}"; 

void MakeBasicItem();
void MakeBasicItemFood();

#endif
