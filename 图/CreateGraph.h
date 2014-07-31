#include "AdjMGraph.h"
class RowColWeight{
public:
	int row;
	int col;
	int weight;
};

void CreateGraph(AdjMGraph* G, ItemType V[], int n, RowColWeight E[], int e);