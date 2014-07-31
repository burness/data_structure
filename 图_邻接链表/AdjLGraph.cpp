#include "AdjLGraph.h"
#include <iostream>
using namespace std;
void AdjInitiate(AdjLGraph *G){
	G->numOfEdges=0;
	G->numofVerts=0;

	for(int i=0;i<MaxVertices;i++){
		G->a[i].sorce=i;
		G->a[i].adj=NULL; 
	}
}

void AdjDestroy(AdjLGraph *G){
	Node* p, *q;
	for(int i=0;i<G->numofVerts;i++){
		p=G->a[i].adj;
		while(p!=NULL){
			q=p->next;
			delete p;
			p=q;
		}
	}
}

void InsertVertex(AdjLGraph *G, int i, DataType vertex){
	if(i>=0&&i<MaxVertices){
		G->a[i].data=vertex;
		G->numofVerts++;
	}
	else
		cout<<"结点越界";
}

void InsertEdge(AdjLGraph *G, int v1, int v2, int weight){
	Node *p;
	if(v1<0||v1>=G->numofVerts||v2<0||v2>=G->numofVerts){
		cout<<"参数v1或v2越界出错！"<<endl;

	}
	p=new Node;
	p->dest=v2;

	p->next=G->a[v1].adj;
	G->a[v1].adj=p;
	G->a[v1].adj->weight=weight;
	G->numOfEdges++;
}

void DeleteEdge(AdjLGraph *G, int v1, int v2){
	Node *curr, *pre;
	if(v1<0||v1>=G->numofVerts||v2<0||v2>=G->numofVerts){
		cout<<"参数v1或v2越界出错"<<endl;
	}
	pre=NULL;
	curr=G->a[v1].adj;
	while(curr!=NULL&&curr->dest!=v2){
		pre=curr;
		curr=curr->next;
	}

	if(curr!=NULL&&curr->dest==v2&&pre==NULL){
		G->a[v1].adj=curr->next;
		delete curr;
		G->numOfEdges--;
	}
	else if(curr!=NULL&&curr->dest==v2&&pre!=NULL){
		pre->next=curr->next;
		delete curr;
		G->numOfEdges--;
	}
	else
		cout<<"边<v1,v2>不存在"<<endl;
}
int GetFirstVex(AdjLGraph G, int v){
	Node* p;
	if(v<0||v>G.numofVerts)
		cout<<"参数v1或者v2越界出错"<<endl;
	p=G.a[v].adj;
	if(p!=NULL)
		return p->dest;
	else return -1;
}

int GetNextVex(AdjLGraph G, int v1, const int v2){
	Node *p;
	if(v1<0||v1>G.numofVerts||v2<0||v2>G.numofVerts){
		cout<<"参数v1或v2越界出错"<<endl;
	}
	p=G.a[v1].adj;
	while(p!=NULL){
		if(p->dest!=v2){
			p=p->next;
			continue;
		}
		else break;
	}
	p=p->next;
	if(p!=NULL) return p->dest;
	else return -1;
}
