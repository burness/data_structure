#include <iostream>
using namespace std;
#define MaxN 100


class HaffNode{
public:
	int weight;
	int flag;
	int parent;
	int leftChild;
	int rightChild;
};


class Code{
public:
	int bit[MaxN];
	int start;
	int weight;
};


void Haffman(int weight[], int n, HaffNode haffTree[]);
void HaffmanCode(HaffNode haffTree[], int n, Code HaffNode[]);