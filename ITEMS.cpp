#include "ITEMS.h"

void MakeBasicItem()
{
	string className,creativeTabs;
	cout<<"��������:";
	cin>>className;
	cout<<"���봴��ģʽ��Ʒ��:";
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
	cout<<"��������:";
	cin>>className;
	cout<<"����ظ��ļ���ֵ:";
	cin>>hunger;
	cout<<"����ظ��ı�ʳ��:";
	cin>>saturation;
	string mItem = BasicItemFood;
	replaceAll(mItem,"%CLASSNAME%",className);
	replaceAll(mItem,"%HUNGER%",hunger);
	replaceAll(mItem,"%SATURATION%",saturation);
	ofstream fout((className+".java").c_str());
	fout<<mItem;
	fout.close();
}
