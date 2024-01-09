#include <iostream>

#define SIZE 4
using namespace std;

struct PQ
{
	int data;
	int priority;
};

class Queue
{
	private :
		struct PQ queue[SIZE];
		int front = -1, rear = -1;
	public :
		void enQueue(int, int);
		void deQueue();
		void disQueue();
		int mostprior();		
};

int Queue :: mostprior()
{
	int prior = queue[0].priority, f = 0, g = 0, i;
	for(i = 0;i <= rear;i++)
	{
		if(prior > queue[i].priority)
		{
			prior = queue[i].priority;
			f = i;
		}
		else if(prior == queue[i].priority)
		{
			if(g > i)
			{
				g = i;
				f = g;
			}
		}
	}
	return f;
}

void Queue :: enQueue(int m, int n)
{
	if(rear == SIZE - 1)
	    cout<<"\nQueue is full\n";
	else
	{
		if(rear == -1 && front == -1)
		{
			rear = 0;
			front = 0;
		}
		else
		    rear++;
		queue[rear].data = m;
		queue[rear].priority = n;
	}
}

void Queue :: deQueue()
{
	int t;
	if(front == -1 && rear == -1)
	    cout<<"\nQueue is empty\n";
	else
	{
		if(rear == front)
	    {
	    	rear = -1;
			front = -1;
		}
		else
		{
			t = mostprior();
		    cout<<"\nThe removed element is "<<queue[t].data<<endl;
		    for(int i = t;i < SIZE;i++)
		    {
			    queue[i].data = queue[i + 1].data;
			    queue[i].priority = queue[i + 1].priority;
		    }
		    rear--;
		}
	}
}

void Queue :: disQueue()
{
	cout<<"\nCurrent status of queue : ";
	for(int i = front;i < rear + 1;i++)
	{
		cout<<queue[i].data<<"   ";
	}
}

int main()
{
	Queue q;
	int op, i = 10, ele, pri;
	
	cout<<"------------------------------------------------------\n";
	cout<<"     Program to perform Priority Queue Operations";
	cout<<"\n------------------------------------------------------";

	while(i)
	{
		cout<<"\n\n\t1 - enQueue\n\t2 - deQueue\n\t3 - disqueue";
		cout<<"\n\nEnter your choice : ";
		cin>>op;
		
		switch (op)
		{
			case 1 :
				cout<<"Enter the element you wish to add : ";
				cin>>ele;
				cout<<"Enter its priority : ";
				cin>>pri;
				q.enQueue(ele, pri);
				q.disQueue();
				break;
			case 2 :
				q.deQueue();
				q.disQueue();
				break;
			case 3 :
				q.disQueue();
				break;
			default :
				cout<<"\n!! INVALID INPUT !!\n";
			    break;
		}
	}
}


