#include "BLOCKS.h"

void MakeBasicBlock()
{
	string className,material,hardness,lightLevel;
	cout<<"��������:";
	cin>>className;
	cout<<"�������:";
	cin>>material;
	cout<<"����Ӳ��:";
	cin>>hardness;
	cout<<"��������:";
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
