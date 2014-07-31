#include <iostream>
#include "BiTree.h"

using namespace std;

void Initiate(Node** root){
	*root=new Node;
	(*root)->leftChild=NULL;
	(*root)->rightChild=NULL;
}
//  在当前节点的左节点插入，当前节点的左子树，成为当前节点的左节点的左子树
Node* InsertLeftNode(Node* curr, DataType x){
	Node *s, *t;
	if(curr==NULL)return NULL;

	t=curr->leftChild;
	s=new Node;
	s->data=x;
	s->leftChild=t;
	s->rightChild=NULL;
	curr->leftChild=s;

	return curr->leftChild;
}


Node* InsertRightNode(Node* curr, DataType x){
	Node *s, *t;
	if(curr==NULL)return NULL;

	t=curr->rightChild;
	s=new Node;
	s->data=x;
	s->rightChild=t;
	s->leftChild=NULL;
	curr->rightChild=s;

	return curr->rightChild;
}

Node *DeleteLeftTree(Node* curr){
	if(curr==NULL||curr->leftChild==NULL)return NULL;
	Destroy(&curr->leftChild);
	curr->leftChild=NULL;
	return curr;
}

Node *DeleteRightTree(Node* curr){
	if(curr==NULL||curr->rightChild==NULL)return NULL;
	Destroy(&curr->rightChild);
	curr->rightChild=NULL;
	return curr;
}

void Destroy(Node **root){
	if((*root)!=NULL&&(*root)->leftChild!=NULL)
		Destroy(&(*root)->leftChild);
	if((*root)!=NULL&&(*root)->rightChild!=NULL)
		Destroy(&(*root)->rightChild);
	delete(*root);
	*root=NULL;

}
