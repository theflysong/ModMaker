#include "BLOCKS.h"

void MakeBasicBlock()
{
	string className,unlocalizedName,registryName,creativeTabs,material,hardness,lightLevel;
	cout<<"��������:";
	cin>>className;
	cout<<"����δ���ػ���:";
	cin>>unlocalizedName;
	cout<<"����ע����:";
	cin>>registryName;
	cout<<"���봴��ģʽ��Ʒ��:";
	cin>>creativeTabs;
	cout<<"�������:";
	cin>>material;
	cout<<"����Ӳ��:";
	cin>>hardness;
	cout<<"��������:";
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
