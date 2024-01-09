#include<iostream>

using namespace std;

struct Node
{
	Node *left;
	int data;
	Node *right;
};

class BST
{
	public :
		Node * insertion(Node *, int);
		Node * deletion(Node *, int);
		void preOrder(Node *);
		void postOrder(Node *);
		void inOrder(Node *);
		Node * findMin(Node *);
		Node * searching(Node *, int);
};

Node * BST :: insertion(Node *root, int ele)
{
	if(root == NULL)
    {
    	Node *ptr = new Node;
    	ptr->data = ele;
    	ptr->left = NULL;
    	ptr->right = NULL;
    	return ptr;
	}
	else if(root->data >= ele)
	    root->left = insertion(root->left, ele);
	else
	    root->right = insertion(root->right, ele);
	return root;
}

Node * BST :: deletion(Node *root, int ele)
{
	if(root == NULL)
	    return root;
	else if(ele < root->data)
	    root->left = deletion(root->left, ele);
	else if(ele > root->data)
	    root->right = deletion(root->right, ele);
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
			return root;
		}
		else if(root->left == NULL)
		{
			Node *temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if(root->right == NULL)
		{
			Node *temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		else
		{
			Node *temp = findMin(root->right);
			root->data = temp->data;
			root->right = deletion(root->right, temp->data);
			return root;
		}
	}
	return root;
}

void BST :: preOrder(Node *root)
{
	if(root == NULL)
	    return;
	cout<<root->data<<"   ";
	preOrder(root->left);
	preOrder(root->right);
}

void BST :: inOrder(Node *root)
{
	if(root == NULL)
	    return;
	inOrder(root->left);
	cout<<root->data<<"   ";
	inOrder(root->right);
}

void BST :: postOrder(Node *root)
{
	if(root == NULL)
	    return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<"   ";
}

Node * BST :: findMin(Node *root)
{
	Node *temp = root;
	
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	
	return temp;
}

Node * BST :: searching(Node *root, int key)
{
	if(root == NULL)
	    return root;
	else if(root->data == key)
	    return root;
	else if(root->data > key)
	    return searching(root->left, key);
	else if(root->data < key)
	    return searching(root->right, key);
	else 
	    return NULL;
}

int main()
{
	Node *root = NULL;
	BST b;
	int op, ele1, ele2, ele3, ch;
	
	cout<<"\n  ------------------------------------------------------------------------\n";
	cout<<"  |         Program to perform Binary Search Tree - Operations           |";
	cout<<"\n  ------------------------------------------------------------------------\n";
	
	while(1)
	{
		cout<<"\n\n\t1 - Insertion\n\t2 - Deletion\n\t3 - Traversion\n\t4 - Searching\n\t5 - Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>op;
		
		switch (op)
		{
			case 1 :
				cout<<"\nEnter the element you wish to insert : ";
				cin>>ele1;
				root = b.insertion(root, ele1);
				cout<<"Inorder tarversion : ";
				b.inOrder(root);
				break;
			case 2 :
				cout<<"\nEnter the element you wish to delete : ";
				cin>>ele2;
				root = b.deletion(root, ele2);
				cout<<"Inorder tarversion : ";
				b.inOrder(root);
				break;
			case 3 :
				cout<<"\n\t\t1 - Inorder Traversion\n\t\t2 - Preorder Traversion\n\t\t3 - Postorder Traversion";
				cout<<"\n\nEnter you choice : ";
				cin>>ch;
				switch (ch)
				{
					case 1 :
						cout<<"Inorder tarversion : ";
						b.inOrder(root);
						break;
					case 2 :
						cout<<"Preorder tarversion : ";
						b.preOrder(root);
						break;
					case 3 :
						cout<<"Postorder tarversion : ";
						b.postOrder(root);
						break;
					default :
						cout<<"\n!! INVALID INPUT !!";
						break;
				}
				break;
			case 4 :
				cout<<"\nEnter the element you wish to search : ";
				cin>>ele3;
				Node *t;
				t = b.searching(root, ele3);
				if(!t)
				    cout<<"\n!! Element not found !!";
				else
				    cout<<"\nElement found at : "<<t;
				break;
			case 5 :
				exit(0);
				break;
			default :
				cout<<"\n!! INVALID INPUT !!";
				break;	
		}
	}
	
	return 0;
}
