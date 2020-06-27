#ifndef __ITEMS__
#define __ITEMS__

#include "head.h"

const string BasicItem=(string)
"public class %CLASSNAME% extends Item {\n\
    public %CLASSNAME%()\n\
    {\n\
    	super(new Properties().group(%CREATIVETABS%));\n\
    }\n\
}\n"; 

const string BasicItemFood=(string)
"public class %CLASSNAME% extends ItemFood {\n\
    private static Food food = (new Food.Builder())\n\
            .saturation(%SATURATION%)\n\
            .hunger(%HUNGER%)\n\
            .build();\n\
            \n\
    public %CLASSNAME%() {\n\
	    super(new Properties().food(food).group(ItemGroup.FOOD));\n\
    }\n\
}"; 

void MakeBasicItem();
void MakeBasicItemFood();

#endif
