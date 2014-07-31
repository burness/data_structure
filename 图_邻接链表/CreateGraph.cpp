#include "CreateGraph.h"


void CreateGraph(AdjLGraph *G, DataType v[], int n, RowColWeight d[], int e){
	AdjInitiate(G);
	for(int i=0;i<n;i++)
		InsertVertex(G,i,v[i]);
	for(int k=0;k<e;k++)
		InsertEdge(G, d[k].row,d[k].col,d[k].weight);
}