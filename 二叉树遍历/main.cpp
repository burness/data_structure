#include <iostream>
#include "BiTree.h"
using namespace std;

int main(){
	Node* root,*p,*pp;
	Initiate(&root);
	p=InsertLeftNode(root,'A');
	p=InsertLeftNode(p,'B');
	p=InsertLeftNode(p,'D');
	p=InsertRightNode(p,'G');
	p=InsertRightNode(root->leftChild,'C');

	pp=p;
	InsertLeftNode(p,'E');
	InsertRightNode(pp,'F');

	PrintBiTree(root,0);
	cout<<"前序遍历:";
	PreOrder(root->leftChild,Visit);
	cout<<endl;
	PreOrder_stack(root->leftChild,Visit);
 	cout<<endl;
	cout<<"中序遍历：";
	InOrder(root->leftChild,Visit);
	cout<<endl;
	InOrder_stack(root->leftChild,Visit);
	cout<<endl;
	cout<<"后续遍历：";
	PostOrder(root->leftChild,Visit);
	cout<<endl;
	PostOrder_stack(root->leftChild,Visit);
	cout<<endl;
	cout<<"层次遍历:";
	LevelOrder_deque(root->leftChild,Visit);

	Destroy(&root);

}