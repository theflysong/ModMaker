#include"head.h"
#include"ITEMS.h"
#include"BLOCKS.h"
using namespace std;

void init(){
	makers["Item"]=MakeBasicItem;
	makers["ItemFood"]=MakeBasicItemFood;
	makers["Block"]=MakeBasicBlock;
} 

int main()
{
	init();
	while(true){
		string type;
		cout<<"输入类型(help可以获取帮助):"; 
		cin>>type;
		if(type=="help"){
			cout<<"所有类型：\n";
			for(map<string,void(*)(void)>::iterator it=makers.begin();it!=makers.end();it++){
				cout<<it->first<<"\n";
			}
			continue;
		}
		if(makers.count(type)==0){
			cout<<"没有该类型\n";
			continue;
		} 
		makers[type]();
	}
} 
