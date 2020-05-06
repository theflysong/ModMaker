#include "ITEMS.h"

void MakeBasicItem()
{
	string className,unlocalizedName,registryName,creativeTabs;
	cout<<"输入类名:";
	cin>>className;
	cout<<"输入未本地化名:";
	cin>>unlocalizedName;
	cout<<"输入注册名名:";
	cin>>registryName;
	cout<<"输入创造模式物品栏:";
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
