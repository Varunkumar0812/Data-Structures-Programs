#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

class Stack
{
	private :
		Node *top = NULL;
	public :
		void push(int);
		void pop();
		void dis_Stack();
		int stacktop();
};

void Stack :: push(int val)
{
	Node *ptr = new Node;
	ptr->data = val;
	ptr->next = NULL;
	
	if(top == NULL)
	    top = ptr;
	else
	{
		ptr->next = top;
		top = ptr;
	}
}

void Stack :: pop()
{
	Node *p = top;
	if(top == NULL)
	    cout<<"\nStack is empty";
	else
	{
		top = top->next;
		delete p;	
	}
}

void Stack :: dis_Stack()
{
	Node *t = top;
	while(top != NULL)
	{
		cout<<top->data<<"   ";
	}
}

int Stack :: stacktop()
{
	return top->data;
}

int main()
{
	Stack s;
	int op, ele;
	
	while(1)
	{
		cout<<"\nEnter you choice : ";
		cin>>op;
		
		switch (op)
		{
			case 1 :
				cout<<"\nEnter the element : ";
				cin>>ele;
				s.push(ele);
				s.dis_Stack();
				break;
			case 2 :
				s.pop();
				s.dis_Stack();
				break;
			case 3 :
				s.dis_Stack();
				break;
			case 4 :
				cout<<"\nThe top most element in the stack is : "<<s.stacktop();
			    break;
			case 5 :
				exit(0);
			default :
				cout<<"\n!! INVALID INPUT !!";
				break;
		}
	}
}
