#include "ITEMS.h"

void MakeBasicItem()
{
	string className,creativeTabs;
	cout<<"输入类名:";
	cin>>className;
	cout<<"输入创造模式物品栏:";
	cin>>creativeTabs;
	string mItem = BasicItem;
	replaceAll(mItem,"%CLASSNAME%",className);
	replaceAll(mItem,"%CREATIVETABS%",creativeTabs);
	ofstream fout((className+".java").c_str());
	fout<<mItem;
	fout.close();
}

void MakeBasicItemFood()
{
	string className,hunger,saturation;
	cout<<"输入类名:";
	cin>>className;
	cout<<"输入回复的饥饿值:";
	cin>>hunger;
	cout<<"输入回复的饱食度:";
	cin>>saturation;
	string mItem = BasicItemFood;
	replaceAll(mItem,"%CLASSNAME%",className);
	replaceAll(mItem,"%HUNGER%",hunger);
	replaceAll(mItem,"%SATURATION%",saturation);
	ofstream fout((className+".java").c_str());
	fout<<mItem;
	fout.close();
}
