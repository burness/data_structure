#include "CreateGraph.h"
using namespace std;

void CreateGraph(AdjMGraph *G, ItemType V[], int n, RowColWeight E[], int e){
	//int i,k;
	Initiate(G,n);
	for(int i=0;i<n;i++)
		InsertVertex(G,V[i]);
	for(int k=0;k<e;k++)
		InsertEdge(G,E[k].row, E[k].col, E[k].weight);
}