#include "haffman.h"
#define MaxValue 1000


void Haffman(int weight[], int n, HaffNode haffTree[]){
	int i,j,m1,m2,x1,x2;
	for(i=0;i<2*n-1;i++){
		if(i<n)
			haffTree[i].weight=weight[i];
		else
			haffTree[i].weight=0;
		haffTree[i].parent=-1;
		haffTree[i].flag=0;
		haffTree[i].leftChild=-1;
		haffTree[i].rightChild=-1;

	}
	for(i=0;i<n-1;i++){
		m1=m2=MaxValue;
		x1=x2=0;
		// 以下这段代码真的很有意思，能够找到指定数组内的最小的两个数，且m1表示其中较小的，m2中表示较大的
 		for(j=0;j<n+i;j++){
			if(haffTree[j].weight<m1&&haffTree[j].flag==0){
				m2=m1;//保证m1是其中比较小的，m2是其中比较大的，这里的代码太有技巧性了！！！！
				x2=x1;
				m1=haffTree[j].weight;
				x1=j;
			}
			else if(haffTree[j].weight<m2&&haffTree[j].flag==0){
				m2=haffTree[j].weight;
				x2=j;
			}
		}
		haffTree[x1].parent=n+i;
		haffTree[x2].parent=n+i;
		haffTree[x1].flag=1;
		haffTree[x2].flag=1;
		haffTree[n+i].weight=haffTree[x1].weight+haffTree[x2].weight;
		haffTree[n+i].leftChild=x1;
		haffTree[n+i].rightChild=x2;
	}
}


void HaffmanCode(HaffNode haffTree[], int n, Code haffCode[]){
	Code* cd=new Code;
	int i,j, child, parent;
	for(i=0;i<n;i++){
		cd->start=n-1;
		cd->weight=haffTree[i].weight;
		child=i;
		parent=haffTree[child].parent;

		while(parent!=-1){
			if(haffTree[parent].leftChild==child)
				cd->bit[cd->start]=0;
			else
				cd->bit[cd->start]=1;
			
			cd->start--;
			child=parent;
			parent=haffTree[child].parent;

		}
		for(j=cd->start+1;j<n;j++)
			haffCode[i].bit[j]=cd->bit[j];

		haffCode[i].start=cd->start+1;
		haffCode[i].weight=cd->weight;
	}
}