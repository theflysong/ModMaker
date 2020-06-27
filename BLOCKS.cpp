#include "BLOCKS.h"

void MakeBasicBlock()
{
	string className,material,hardness,lightLevel;
	cout<<"输入类名:";
	cin>>className;
	cout<<"输入材质:";
	cin>>material;
	cout<<"输入硬度:";
	cin>>hardness;
	cout<<"输入亮度:";
	cin>>lightLevel;
	string mBlock = BasicBlock;
	replaceAll(mBlock,"%CLASSNAME%",className);
	replaceAll(mBlock,"%MATERIAL%",material);
	replaceAll(mBlock,"%HARDNESS%",hardness);
	replaceAll(mBlock,"%LIGHTLEVEL%",lightLevel);
	ofstream fout((className+".java").c_str());
	fout<<mBlock;
	fout.close();
}
