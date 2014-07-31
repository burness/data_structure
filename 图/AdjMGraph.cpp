#include "AdjMGraph.h"
#include <iostream>
using namespace std;
#define  MaxWeight 1000
void Initiate(AdjMGraph *G, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)
				G->edge[i][j]=0;
			else
				G->edge[i][j]=MaxWeight;
		}
	}

}

void InsertVertex(AdjMGraph *G, ItemType vertex){
	G->Vertices.push_back(vertex);
}

void InsertEdge(AdjMGraph *G, int v1, int v2, int weight){
	if(v1<0||v1>G->Vertices.size()||v2<0||v2>G->Vertices.size()){
		cout<<"参数v1或者v2出错"<<endl;
	}
	G->edge[v1][v2]=weight;
	G->numOfEdges++;
}

void DeleteEdge(AdjMGraph *G, int v1, int v2){
	if(v1<0||v1>G->Vertices.size()||v2<0||v2>G->Vertices.size()){
		cout<<"参数v1或者v2出错！"<<endl;
	}
	if(G->edge[v1][v2]==MaxWeight||v1==v2){
		cout<<"该边吃不存在！"<<endl;
	}
	G->edge[v1][v2]=MaxWeight;
	G->numOfEdges--;
}

void DeleteVertex(AdjMGraph *G, int v){
	int n=G->Vertices.size();
	ItemType x;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if((i==v||j==v)&&G->edge[i][j]>0&&G->edge[i][j]<MaxWeight)
				G->numOfEdges--;
		}
	for(int i=v;i<n;i++)
		for(int j=0;j<n;j++)
			G->edge[i][j]=G->edge[i+1][j];
	for(int i=0;i<n;i++)
		for(int j=v;j<n;j++)
			G->edge[i][j]=G->edge[i][j+1];
	list<ItemType>::iterator index=G->Vertices.begin();
	for ( int i=0;i<v&&index!=G->Vertices.end();i++,index++)
	{

	}

	G->Vertices.erase(index);
}

int GetFirstVex(AdjMGraph G, int v){
	if(v<0||v>G.Vertices.size()){
		cout<<"参数v1越界出错！"<<endl;
	}
	for(int col=0;col<G.Vertices.size();col++){
		if(G.edge[v][col]>0&&G.edge[v][col]<MaxWeight)
			return col;
	return -1;
	}
}

int GetNextVex(AdjMGraph G, int v1, int v2){
	if(v1<0||v1>G.Vertices.size()||v2<0||v2>G.Vertices.size()){
		cout<<"参数v1或者v2出错！"<<endl;
	}
	for(int col=v2+1;col<G.Vertices.size();col++)
		if(G.edge[v1][col]>0&&G.edge[v1][col]<MaxWeight)
			return col;
	return -1;
}

