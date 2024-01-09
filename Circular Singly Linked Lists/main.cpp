#include<iostream>

using namespace std;

struct Node 
{
	int data;
	Node *next;
};

class List
{
	private :
		Node *head = NULL;
	public :
		int count = 0;
		void creation(int);
		void insertion(int, int);
		void deletion(int);
		void traversion();
		bool searching(int);
};

void List :: creation(int val)
{
	Node *ptr = new Node;
	ptr->data = val;
	ptr->next = NULL;
	
	if(head == NULL)
	{
	    head = ptr;
	    head->next = ptr;
    }
	else
	{
		Node *temp = head;
		while(temp->next != head)
		    temp = temp->next;
		temp->next = ptr;
		ptr->next = head;
	}
	count++;
}

void List :: insertion(int val, int loc)
{
	Node *ptr = new Node;
	ptr->data = val;
	ptr->next = NULL;
	int i = 1;
	Node *p = head, *q = NULL;
	
    while(i < loc)
    {
    	q = p;
    	p = p->next;
    	i++;
	}
	
	if(p == head && q == NULL)
	{
		Node *last = head;
		while(last->next != head)
		    last = last->next;
		head = ptr;
		ptr->next = p;
		last->next = head;
	}
	else if(q->next == NULL)
	{
	    q->next = ptr;
		ptr->next = head;		
	}
	else
	{
		q->next = ptr;
		ptr->next = p;
	}
	count++;
}

void List :: deletion(int loc)
{
	int i = 1;
	Node *p = head, *q = head;
	
	while(i < loc)
	{
		q = p;
		p = p->next;
		i++;
	}
	
	if(p == q)
	{
	    Node *last = head;
	    while(last->next != head)
	        last = last->next;
	    head = p->next;	
		last->next = head;	
	}
	else if(p->next == head)
	    q->next = head;
	else
	    q->next = p->next;
	delete p;
	count--;
}

void List :: traversion()
{
	if(head == NULL)
	{
		cout<<"\nQueue is empty";
	}
	else
	{
		cout<<"\nCurrent status of the linked list : ";
	    Node *p = head;
        while(p->next != head)
	    {
		    cout<<p->data<<"   ";
		    p = p->next;
	    }
	    cout<<p->data<<"   ";
	}
}

bool List :: searching(int ele)
{
	int i = 1;
	bool check = false;
	Node *p = head;
    while(p->next != head)
	{
		if(p->data == ele)
		{
			cout<<"\nThe element found at location : "<<i<<".\n";
			check = true;
			break;
		}
		p = p->next;
		i++;
	}
    if(p->data == ele && check == false)
    {
    	cout<<"\nThe element found at location : "<<i<<".\n";
		check = true;
	}
	return check;
}

int main()
{
	int op, val1, val2, loc1, loc2, ele, i = 8;
	List ln;
	
	cout<<"----------------------------------------------------------------\n";
	cout<<"      Program to perform Circular Linked List - Operations\n";
	cout<<"----------------------------------------------------------------";
	
	while(i)
	{
		cout<<"\n\n\t1 - Creation\n\t2 - Insertion\n\t3 - Deletion";
		cout<<"\n\t4 - Traversion\n\t5 - Searching\n\t6 - Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>op;
		
		switch (op)
		{
			case 1 :
				cout<<"\nEnter the element you wish to create : ";
				cin>>val1;
				ln.creation(val1);
				ln.traversion();
				break;
			case 2 :
				for(int j = 0;j >= 0;)
				{
					cout<<"\nEnter the element you wish to insert : ";
				    cin>>val2;
				    cout<<"Enter the location where you wish to insert : ";
				    cin>>loc1;
				    if(loc1 > ln.count+1 || loc1 <= 0)
				    {
					    cout<<"\n!! The position entered is beyond the scope of Linked List !!\n";
				    }
				    else
				    {
					    ln.insertion(val2, loc1);
				        ln.traversion();
				        break;
				    }
				}
                break;
			case 3 :
				for(int k = 0;k >= 0;)
				{
					cout<<"\nEnter the location of the elemnet which you want to delete : ";
				    cin>>loc2;
				    if(loc2 > ln.count || loc2 <= 0)
				    {
					    cout<<"\n!! The position entered is beyond the scope of Linked List !!\n";
				    }
				    else
				    {
				        ln.deletion(loc2);
				        ln.traversion();
				        break;					
				    }
				}
                break;
			case 4 :
				ln.traversion();
				break;
			case 5 : 
			    cout<<"\nEnter the element which you want to search : ";
			    cin>>ele;
			    if(!ln.searching(ele))
			        cout<<"\n!! Element not found !!\n";
			    break;
			case 6 :
				exit(0);
				break;
			default :
				cout<<"\n!! INVALID INPUT !!\n";
				break;
		}
	}
	return 0;
}
