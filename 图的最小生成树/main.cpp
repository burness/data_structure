#include<iostream>

#ifndef CREATEGRAPH
#define CREATEGRAPH
#include "CreateGraph.h"
#endif
#ifndef PRIM
#define PRIM
#include "prim.h"
#endif
#ifndef ADJMGRAPH
#define  ADJMGRAPH
#include "AdjMGraph.h"
#endif

using namespace std;

int main(){
	AdjMGraph g1;
	ItemType a[]={1,2,3,4,5,6,7};
	RowColWeight row[]={{0,1,50},{1,0,50},{0,2,66},{2,0,66},{1,3,65},{3,1,65},{1,4,40},{4,1,40},{2,3,52},{3,2,52},{2,6,45},{6,2,45},{3,4,50},{4,3,50}
	,{3,5,30},{5,3,30},{3,6,42},{6,3,42},{4,5,70},{5,4,70}};

	int n=sizeof(a)/sizeof(ItemType);
	MinSpanTree* closeVertex=new MinSpanTree[n];
	CreateGraph(&g1,a,n,row,sizeof(row)/sizeof(RowColWeight));
	prim(g1,closeVertex);
	cout<<"初始节点:";
	cout<<closeVertex[0].vertex;
	cout<<endl;
	for(int i=1;i<n;i++){
		cout<<"节点："<<closeVertex[i].vertex<<"权值："<<closeVertex[i].weight<<endl;
	}
}