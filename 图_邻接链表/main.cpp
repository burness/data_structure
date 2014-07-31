#include <iostream>
using namespace std;
//#include "AdjLGraph.h"
#include "CreateGraph.h"


int main(){
	AdjLGraph g1;
	DataType a[]={1,2,3,4,5};
	RowColWeight row[]={{0,1,10},{0,2,60},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};


	CreateGraph(&g1,a,sizeof(a)/sizeof(DataType),row,sizeof(row)/sizeof(RowColWeight));
	DeleteEdge(&g1,0,4);
	cout<<"节点集合为：";
	for(int i=0;i<sizeof(a)/sizeof(DataType);i++)
		cout<<g1.a[i].data<<"	";
	
	cout<<endl;
	cout<<"权值集合:"<<endl;
	for(int i=0;i<sizeof(a)/sizeof(DataType);i++)
		for(Node *temp=g1.a[i].adj;temp!=NULL;temp=temp->next){
			cout<<g1.a[i].sorce<<" to "<<temp->dest<<endl; 
			cout<<temp->weight<<endl;
		}
		cout<<endl;
}