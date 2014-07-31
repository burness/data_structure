#define  DataType char
class Node{
public:
	DataType data;
	Node* leftChild;
	Node* rightChild;
};
void Initiate(Node** root);
Node* InsertLeftNode(Node* curr, DataType x);
Node* InsertRightNode(Node* curr, DataType x);
Node *DeleteLeftTree(Node* curr);
Node *DeleteRightTree(Node* curr);
void Destroy(Node **root);