#include<iostream>

#ifndef CREATEGRAPH
#define CREATEGRAPH
#include "CreateGraph.h"
#endif
#ifndef DIJKSTRA
#define DIJKSTRA
#include "Dijkstra.h"
#endif
#ifndef ADJMGRAPH
#define  ADJMGRAPH
#include "AdjMGraph.h"
#endif


int main(){
	AdjMGraph g;
	int a[]={1,2,3,4,5,6};
	RowColWeight rcw[]={{0,2,5},{0,3,30},{1,0,2},{1,4,8},{2,1,15},{2,5,7},{4,3,4},{5,3,10},{5,4,18}};

	int *distance=new int[sizeof(a)/sizeof(int)];
	int *path=new int[sizeof(a)/sizeof(int)];
	CreateGraph(&g,a,sizeof(a)/sizeof(int),rcw,sizeof(rcw)/sizeof(RowColWeight));
	Dijkstra(g,0,distance,path);
	list<ItemType>::iterator index=g.Vertices.begin();

	cout<<"从结点"<<*index<<" 到其他各节点的最短距离为"<<endl;
	for(int i=0;index!=g.Vertices.end();i++,index++){
		cout<<"到结点"<<*index<<"的最短距离为"<<distance[i]<<endl;
	}
	index=g.Vertices.begin();
	cout<<"从结点"<<*index<<"到其他各节点最短路径的前一结点为:"<<endl;
	for(int i=0;index!=g.Vertices.end();index++,i++)
		if(path[i]!=-1)
			cout<<"到结点"<<*index<<"的前一结点为"<<a[path[i]]<<endl;
}