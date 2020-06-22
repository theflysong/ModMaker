#include "BLOCKS.h"

void MakeBasicBlock()
{
	string className,unlocalizedName,registryName,creativeTabs,material,hardness,lightLevel;
	cout<<"输入类名:";
	cin>>className;
	cout<<"输入未本地化名:";
	cin>>unlocalizedName;
	cout<<"输入注册名:";
	cin>>registryName;
	cout<<"输入创造模式物品栏:";
	cin>>creativeTabs;
	cout<<"输入材质:";
	cin>>material;
	cout<<"输入硬度:";
	cin>>hardness;
	cout<<"输入亮度:";
	cin>>lightLevel;
	string mBlock = BasicBlock;
	replaceAll(mBlock,"%CLASSNAME%",className);
	replaceAll(mBlock,"%REGISTRY_NAME%",registryName);
	replaceAll(mBlock,"%UNLOACALIZED_NAME%",unlocalizedName);
	replaceAll(mBlock,"%CREATIVETABS%",creativeTabs);
	replaceAll(mBlock,"%MATERIAL%",material);
	replaceAll(mBlock,"%HARDNESS%",hardness);
	replaceAll(mBlock,"%LIGHTLEVEL%",lightLevel);
	ofstream fout((className+".java").c_str());
	fout<<mBlock;
	fout.close();
}
