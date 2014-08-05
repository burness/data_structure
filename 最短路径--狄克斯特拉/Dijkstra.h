#include <iostream>
#ifndef CREATEGRAPH
#define CREATEGRAPH
#include "CreateGraph.h"
#endif
#ifndef ADJMGRAPH
#define ADJMGRAPH
#include "AdjMGraph.h"
#endif
using namespace std;

void Dijkstra(AdjMGraph G, int v0, int distance[],int path[]);