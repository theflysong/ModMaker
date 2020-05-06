#include "head.h"

map<string,void(*)(void)> makers;

void replaceAll(string &str,const string old1,const string old2){
    while(str.find(old1)!=-1){
    	str.replace(str.find(old1),old1.length(),old2);
	}
}
