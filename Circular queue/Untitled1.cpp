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
	if((front == 0 && rear == SIZE - 1) || rear == front - 1)
	    cout<<"\nQueue is full";
	else
	{
		if(rear == -1 && front == -1)
		{
			front = 0;
			rear = 0;
		}
		else if(rear == SIZE - 1)
		    rear = 0;
		else
		    rear++;
		num[rear] = m;
	}
}

void Queue :: dequeue()
{
	if(front == -1 && rear == -1)
	    cout<<"\nQueue is empty";
	else
	{
		cout<<"\nThe removed element is : "<<num[front];
	    if(front == rear)
	    {
	    	front = -1;
	    	rear = -1;
		}
		else if(front == SIZE - 1)
		    front = 0;
		else
		    front++;
	}
}

void Queue :: disqueue()
{
	if(front == -1 && rear == -1)
	    cout<<"\nQueue is empty";
	else
	{
		cout<<"\nCurrent status of queue : ";
		if(front <= rear)
		{
			for(int i = front;i <= rear;i++)
			    cout<<num[i]<<"   ";
		}
		else
		{
			for(int j = front;j < SIZE;j++)
			    cout<<num[j]<<"   ";
			for(int k = 0;k <= rear;k++)
			    cout<<num[k]<<"   ";
		}
	}
}
