#include<iostream>
#define SIZE 5

using namespace std;

class Queue
{
	private :
		int front = -1, rear = -1;
		int num[SIZE];
	public :
		void enqueue(int);
		void dequeue();
		void disqueue();
};

void Queue :: enqueue(int m)
{
	if(rear == SIZE - 1)
	    cout<<"\nQueue is full";
	else
	{
		if(rear == -1 && front == -1)
		    rear = front = 0;
		else
		    rear++;
		num[rear] = m;
	}
}

void Queue :: dequeue()
{
	if(rear == front - 1)
	    cout<<"\nQueue is empty";
	else
	{
		cout<<"\nThe removed element is : "<<num[front];
		if(rear == front)
		    rear = front = -1;
		else
		    front++;
	}
}

void Queue :: disqueue()
{
	cout<<"\nCurrent status of the queue : ";
	for(int i = front;i <= rear;i++)
	    cout<<num[i]<<"   ";
}

int main()
{
	int op, ele;
	Queue q;
	
	cout<<"Program to perform Linear Queue Operations";
	
	while(1)
	{
		cout<<"\n\n\t1 - enqueue\n\t2 - dequeue\n\t3 - disqueue\n\t4 - Exit";
		
		switch (op)
		{
			case 1 :
				cout<<"\nEnter the element you wish to insert : ";
				cin>>ele;
				q.enqueue(ele);
				q.disqueue();
				break;
			case 2 :
				q.dequeue();
				q.disqueue();
				break;
			case 3 :
				q.disqueue();
				break;
			case 4 :
				exit(0);
			default :
				cout<<"\n!! INVALID INPUT !!";
				break;
		}
	}
	return 0;
}
