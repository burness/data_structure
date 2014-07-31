#include "AdjLGraph.h"

class RowColWeight{
public:
	int row;
	int col;
	int weight;
};


void CreateGraph(AdjLGraph *G, DataType v[], int n, RowColWeight d[], int e);