#include<iostream>

using namespace std;

struct Node
{
	Node *left;
	int data;
	Node *right;
};

Node * createNew()
{
	char ch1, ch2;
	Node *ptr = new Node;
	
	cout<<"\nEnter the data : ";
	cin>>ptr->data;
	ptr->left = NULL;
	ptr->right = NULL;
	
	cout<<"\nDo you want to enter a left child of "<<ptr->data<<" (Y/N) : ";
	cin>>ch1;
	if(ch1 == 'Y' || ch1 == 'y')
	    ptr->left = createNew();
	    
	cout<<"\nDo you want to enter a right child of "<<ptr->data<<" (Y/N) : ";
	cin>>ch2;
	if(ch2 == 'Y' || ch2 == 'y')
	    ptr->right = createNew();
	
	return ptr;
}

void preOrder(Node *root)
{
	if(root == NULL)
	    return;
	cout<<root->data<<"   ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(Node *root)
{
	if(root == NULL)
	    return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<"   ";
}

void inOrder(Node *root)
{
	if(root == NULL)
	    return;
	inOrder(root->left);
	cout<<root->data<<"   ";
	inOrder(root->right);
}

int main()
{
	Node *root;
	
	cout<<"  ----------------------------------------------------------\n";
	cout<<"  |        Binary Tree - Construction and Traversal        |\n";
	cout<<"  ----------------------------------------------------------\n";
	
	root = createNew();
	
	cout<<"\nInorder Traversal    : ";
	inOrder(root);
	cout<<"\nPreOrder Traversal   : ";
    preOrder(root);
    cout<<"\nPostOrder Traversal  : ";
    postOrder(root);
}
