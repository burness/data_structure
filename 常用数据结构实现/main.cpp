#include <iostream>
#include "BiTree.h"
using namespace std;

int main(){
	Node *root,*p,*pp;
	Initiate(&root);
	p=InsertLeftNode(root,'A');
	p=InsertLeftNode(p,'B');
	p=InsertLeftNode(p,'D');
	p=InsertRightNode(p,'G');
	p=InsertRightNode(root->leftChild,'C');

	pp=p;
	InsertLeftNode(p,'E');
	InsertRightNode(pp,'F');
	return 1;

}