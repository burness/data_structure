#define  DataType int
#include <iostream>
#define MaxVertices 100
using namespace std;
class Node{
public:
	int dest;
	int weight;
	Node* next;
};

class AdjLHeight{
public:
	DataType data;
	int sorce;
	Node *adj;
};


class AdjLGraph{
public:
	AdjLHeight a[MaxVertices];
	int numofVerts;
	int numOfEdges;
}; 


void AdjInitiate(AdjLGraph *G);
void AdjDestroy(AdjLGraph *G);
void InsertVertex(AdjLGraph *G, int i, DataType vertex);
void InsertEdge(AdjLGraph  *G, int v1, int v2, int weight);
void DeleteEdge(AdjLGraph *G, int v1, int v2);
int GetFirstVex(AdjLGraph G, int v);
int GetNextVex(AdjLGraph G, int v1, const int v2);