#ifndef ADJMGRAPH
#define ADJMGRAPH
#include "AdjMGraph.h"
#endif

class MinSpanTree{
public:
	ItemType vertex;
	int weight;
};


void prim(AdjMGraph G, MinSpanTree closeVertex[]);