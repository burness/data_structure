#include <iostream>
using namespace std;
//#include "AdjMGraph.h"
#include "CreateGraph.h"


int main(){
	AdjMGraph g1;
	ItemType a[]={1,2,3,4,5};
	RowColWeight row[]={{0,1,10},{0,4,20},{1,3,30},{2,1,40},{3,2,50}};
	int n=5,e=5;

	CreateGraph(&g1,a,n,row,e);
	DeleteEdge(&g1,0,4);
	DeleteVertex(&g1,3);
	cout<<"节点集合为：";
	for(list<ItemType>::iterator index=g1.Vertices.begin();index!=g1.Vertices.end();index++)
		cout<<*index<<"	";
	cout<<endl;
	cout<<"权值集合:"<<endl;
	for(int i=0;i<g1.Vertices.size();i++){
		for(int j=0;j<g1.Vertices.size();j++)
			cout<<g1.edge[i][j]<<"	";
		cout<<endl;
	}
}