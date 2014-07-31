#include <list>
#include <queue>
using namespace std;
#define ItemType int
#define  MaxVertices 100

class AdjMGraph{
public:
	list<ItemType> Vertices;
	int edge[MaxVertices][MaxVertices];
	int numOfEdges;
};
void Visit(ItemType item);
void Initiate(AdjMGraph *G, int n);
void InsertVertex(AdjMGraph *G, ItemType vertex);
void InsertEdge(AdjMGraph *G, int v1, int v2, int weight);
void DeleteEdge(AdjMGraph *G, int v1, int v2);
void DeleteVertex(AdjMGraph *G, int v);
int GetFirstVex(AdjMGraph G, int v);
int GetNextVex(AdjMGraph G, int v1, int v2);
// 连通图的深度优先遍历
void DepthFSearch(AdjMGraph G, int v, int vistied[], void Visit(ItemType item));
// 非连通图的深度优先遍历
void DepthFirstSearch(AdjMGraph G, void Visit(ItemType item));

// 连通图的广度优先遍历
void BroadFSearch(AdjMGraph G, int v, int visited[], void Visit(ItemType item));
void BroadFirstSearch(AdjMGraph G, void Visit(ItemType item));