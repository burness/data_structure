#include <iostream>
#include "haffman.h"


int main(){
	int i,j,n=4;
	int weight[]={1,3,5,7};
	HaffNode* myHaffTree=new HaffNode[2*n+1];
	Code* myHaffCode=new Code[n];
	if(n>MaxN){
		cout<<"给出的n越界，修改MaxN值！\n";
		exit(0);
	}
	Haffman(weight,n,myHaffTree);
	HaffmanCode(myHaffTree,n,myHaffCode);
	for(i=0;i<n;i++){
		cout<<"Weight = "<<myHaffCode[i].weight <<" code= ";
		for(j=myHaffCode[i].start;j<n;j++){
			cout<<myHaffCode[i].bit[j];
		}
		cout<<endl;
	}
}