#ifndef __BLOCKS__
#define __BLOCKS__

#include "head.h"

const string BasicBlock=(string)"\
public class %CLASSNAME% extends Block {\n\
    public %CLASSNAME%() {\n\
       super(Properties.create(%MATERIAL%).hardnessAndResistance(%HARDNESS%).lightLevel(%LIGHTLEVEL%));\n\
    }\n\
}";

void MakeBasicBlock();

#endif 
