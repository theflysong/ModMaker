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
		cout<<"��������(help���Ի�ȡ����):"; 
		cin>>type;
		if(type=="help"){
			cout<<"�������ͣ�\n";
			for(map<string,void(*)(void)>::iterator it=makers.begin();it!=makers.end();it++){
				cout<<it->first<<"\n";
			}
			continue;
		}
		if(makers.count(type)==0){
			cout<<"û�и�����\n";
			continue;
		} 
		makers[type]();
	}
} 
