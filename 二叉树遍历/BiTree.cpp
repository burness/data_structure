#include <iostream>
#include <stack>
#include <deque>
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

void Visit(DataType item){
	cout<<item<<"	";
}

void PreOrder(Node* t, void Visit(DataType item)){
	if(t!=NULL){
		Visit(t->data);
		PreOrder(t->leftChild,Visit);
		PreOrder(t->rightChild,Visit);

	}
}

void InOrder(Node* t, void Visit(DataType item)){
	if(t!=NULL){
		InOrder(t->leftChild,Visit);
		Visit(t->data);
		InOrder(t->rightChild,Visit);
	}
}

void PostOrder(Node* t, void Visit(DataType item)){
	if(t!=NULL){
		PostOrder(t->leftChild,Visit);
		PostOrder(t->rightChild,Visit);
		Visit(t->data);
	}
}


void PrintBiTree(Node* root, int n){
	int i;
	if(root==NULL)return;
	PrintBiTree(root->rightChild,n+1);
	for(i=0;i<n;i++)
		cout<<"	";
	if(n>=0){
		cout<<"---";
		cout<<root->data<<endl;
	}
	PrintBiTree(root->leftChild,n+1);
}


void PreOrder_stack(Node* t, void Visit(DataType item)){
	stack<Node*> Node_stack;
	Node_stack.push(t);
	while(!Node_stack.empty()){
		//访问该节点
		//cout<<Node_stack.pop()<<endl;
		Node* t= Node_stack.top();
		Node_stack.pop();	
		//cout<<t->data<<"	";
		Visit(t->data);
		if(t->rightChild!=NULL){
			Node_stack.push(t->rightChild);
		}
		if(t->leftChild!=NULL){
			Node_stack.push(t->leftChild);
		}
	}
}
void InOrder_stack(Node* t, void Visit(DataType item)){
	stack<Node*> Node_stack;
	
	while(t||!Node_stack.empty()){
		while(t!=NULL){
			Node_stack.push(t);
			t=t->leftChild;
		}
		if(!Node_stack.empty()){
			t=Node_stack.top();
			//cout<<t->data<<"	";
			Visit(t->data);
			Node_stack.pop();
			t=t->rightChild;
			
		}
	}
}

void PostOrder_stack(Node* t, void Visit(DataType item)){
	stack<Node*> Node_stack;
	Node* curr;
	Node* pre=NULL;
	Node_stack.push(t);
	while(!Node_stack.empty()){
		curr=Node_stack.top();
		// pre==curr->leftChild||pre==curr->rightChild 表示已经已经访问其子树，返回来时pre为其子树节点就表明已经反问过，那么此时节点就需要输出
		if((curr->leftChild==NULL&&curr->rightChild==NULL)||(pre!=NULL&&(pre==curr->leftChild||pre==curr->rightChild))){
			//cout<<curr->data<<"	";
			Visit(curr->data);
			Node_stack.pop();
			pre=curr;
		}
		else{
			if(curr->rightChild!=NULL)
				Node_stack.push(curr->rightChild);
			if(curr->leftChild!=NULL)
				Node_stack.push(curr->leftChild);
		}
	}
}

void LevelOrder_deque(Node* t, void Visit(DataType item)){
	deque<Node*> Node_deque;
	Node_deque.push_back(t);
	while(!Node_deque.empty()){
		Node* temp=Node_deque.front();
		//cout<<temp->data<<"	";
		Visit(temp->data);
		Node_deque.pop_front();
		if(temp->leftChild!=NULL)
			Node_deque.push_back(temp->leftChild);
		if(temp->rightChild!=NULL)
			Node_deque.push_back(temp->rightChild);
	}
}
