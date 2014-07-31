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


void Visit(DataType item);
void PreOrder(Node* t, void Visit(DataType item));
void InOrder(Node* t, void Visit(DataType item));
void PostOrder(Node* t, void Visit(DataType item));
void PreOrder_stack(Node* t, void Visit(DataType item));
void InOrder_stack(Node* t, void Visit(DataType item));
void PostOrder_stack(Node* t, void Visit(DataType item));
void LevelOrder_deque(Node* t, void Visit(DataType item));
void PrintBiTree(Node* root, int n);