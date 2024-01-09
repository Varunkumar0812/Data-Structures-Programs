#include<iostream>

#define SIZE 4
using namespace std;

class Queue
{
	private :
		int front = -1, rear = -1;
		int num[SIZE];
	public :
		void enQueue(int);
		void deQueue();
		void disQueue();
};

void Queue :: enQueue(int n)
{
	if(rear == SIZE - 1)
	    cout<<"\nQueue is full\n";
	else
	{
		if(rear == -1 && front == -1)
		{
		    front = 0;
		    rear = 0;
	    }
	    else
	        rear++;
	    num[rear] = n;
	}
}

void Queue :: deQueue()
{
	if(front == -1 && rear == -1)
	    cout<<"Queue is empty";
	else
	{
		cout<<"\nThe removed element is "<<num[front];
		if(front == rear)
		    front = rear = -1;
		else
		    front++;
	}
}

void Queue :: disQueue()
{
	cout<<"Current status of the queue : \n";
	for(int i = front;i < rear + 1;i++)
		cout<<num[i]<<"   ";
}

int main()
{
	Queue q;
	int op, ele, i = 10;
	
	cout<<"------------------------------------------------\n";
	cout<<"   Program to perform Linear Queue Operations";
	cout<<"\n------------------------------------------------";
	
	while(i)
	{
		
	    cout<<"\n\n\t1 - enQueue\n\t2 - deQueue\n\t3 - disQueue";
	    cout<<"\n\nEnter your choice : ";
	    cin>>op;
	
	    switch (op)
	    {
		    case 1 :
			    cout<<"\nEnter the element you wish to enter : ";
			    cin>>ele;
			    q.enQueue(ele);
			    q.disQueue();
			    break;
		    case 2 :
			    q.deQueue();
			    cout<<"\n";
			    q.disQueue();
			    break;
		    case 3 :
			    q.disQueue();
			    break;
		    case 4 :
			    exit(0);
			    break;
		    default :
			    cout<<"!! INVALID INPUT !!";
			    break;
	    }
	}
	return 0;
}
