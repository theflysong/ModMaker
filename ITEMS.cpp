#include "ITEMS.h"

void MakeBasicItem()
{
	string className,unlocalizedName,registryName,creativeTabs;
	cout<<"��������:";
	cin>>className;
	cout<<"����δ���ػ���:";
	cin>>unlocalizedName;
	cout<<"����ע������:";
	cin>>registryName;
	cout<<"���봴��ģʽ��Ʒ��:";
	cin>>creativeTabs;
	string mItem = BasicItem;
	replaceAll(mItem,"%CLASSNAME%",className);
	replaceAll(mItem,"%REGISTRY_NAME%",registryName);
	replaceAll(mItem,"%UNLOACALIZED_NAME%",unlocalizedName);
	replaceAll(mItem,"%CREATIVETABS%",creativeTabs);
	ofstream fout((className+".java").c_str());
	fout<<mItem;
	fout.close();
}
