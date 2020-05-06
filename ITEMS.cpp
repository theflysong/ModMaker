#include "ITEMS.h"

void MakeBasicItem()
{
	string className,unlocalizedName,registryName,creativeTabs;
	cout<<"输入类名:";
	cin>>className;
	cout<<"输入未本地化名:";
	cin>>unlocalizedName;
	cout<<"输入注册名:";
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

void MakeBasicItemFood()
{
	string className,unlocalizedName,registryName,creativeTabs,healAmount,saturation;
	cout<<"输入类名:";
	cin>>className;
	cout<<"输入未本地化名:";
	cin>>unlocalizedName;
	cout<<"输入注册名:";
	cin>>registryName;
	cout<<"输入回复的饥饿值:";
	cin>>healAmount;
	cout<<"输入回复的饱食度:";
	cin>>saturation;
	string mItem = BasicItemFood;
	replaceAll(mItem,"%CLASSNAME%",className);
	replaceAll(mItem,"%REGISTRY_NAME%",registryName);
	replaceAll(mItem,"%UNLOACALIZED_NAME%",unlocalizedName);
	replaceAll(mItem,"%HEALAMOUNT%",healAmount);
	replaceAll(mItem,"%SATURATION%",saturation);
	ofstream fout((className+".java").c_str());
	fout<<mItem;
	fout.close();
}
