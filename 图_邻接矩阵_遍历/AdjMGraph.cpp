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
	G->numOfEdges=0;


}
void Visit(ItemType item){
	cout<<item<<"	";
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
	
	}
	return -1;
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


void DepthFSearch(AdjMGraph G, int v, int vistied[], void Visit(ItemType item)){
	int w;
	//Visit(G.Vertices.);
	list<ItemType>::iterator index=G.Vertices.begin();
	for(int i=0;index!=G.Vertices.end(),i<v;index++,i++){

	}
	Visit(*index);
	vistied[v]=1;
	w=GetFirstVex(G,v);
	while(w!=-1){
		if(!vistied[w])
			DepthFSearch(G,w,vistied,Visit);
		w=GetNextVex(G,v,w);
	}
}


void DepthFirstSearch(AdjMGraph G, void Visit(ItemType item)){
	int *visited=new int[G.Vertices.size()];
	for(int i=0;i<G.Vertices.size();i++)
		visited[i]=0;
	for(int i=0;i<G.Vertices.size();i++)
		if(!visited[i])
			DepthFSearch(G,i,visited,Visit);
	delete[] visited;
}

void BroadFSearch(AdjMGraph G, int v, int visited[], void Visit(ItemType item)){
	ItemType u,w;
	queue<ItemType> IT_queue;
	list<ItemType>::iterator index=G.Vertices.begin();
	for(int i=0;index!=G.Vertices.end(),i<v;index++,i++){

	}
	Visit(*index);
	visited[v]=1;
	IT_queue.push(v);
	while (!IT_queue.empty())
	{
		u=IT_queue.front();
		IT_queue.pop();
		w=GetFirstVex(G,u);
		while(w!=-1){
			if(!visited[w]){
				list<ItemType>::iterator index=G.Vertices.begin();
				for(int i=0;index!=G.Vertices.end(),i<w;index++,i++){

				}
				Visit(*index);
				visited[w]=1;
				IT_queue.push(w);
			}
			w=GetNextVex(G,u,w);
		}
	}
}


void BroadFirstSearch(AdjMGraph G, void Visit(ItemType item)){
	int i;
	int *visited=new int[G.Vertices.size()];
	for(i=0;i<G.Vertices.size();i++)
		visited[i]=0;
	for(i=0;i<G.Vertices.size();i++)
		if(!visited[i])
			BroadFSearch(G,i,visited,Visit);

	delete[] visited;
}