#include<iostream>

#define SIZE 4
using namespace std;

class Queue
{
	private :
		int front = -1, rear = -1;
		int num[SIZE];
	public :
		void enqueueRear(int);
		void enqueueFront(int);
		void dequeueRear();
		void dequeueFront();
		void disQueue();
};

void Queue :: enqueueRear(int n)
{
    if(rear == SIZE - 1)
        cout<<"\nOperation not possible\n";
    else
    {
    	if(rear == -1)
        {
        	rear = 0;
        	front = 0;
		}
		else
		    rear++;
		num[rear] = n;
	}
}

void Queue :: enqueueFront(int n)
{
    if(front == 0)
        cout<<"\nOperation not possible\n";
    else
    {
    	if(front == -1)
        {
        	rear = 0;
        	front = 0;
		}
		else
		    front--;
		num[front] = n;
	}
}

void Queue :: dequeueRear()
{
	if(rear == -1)
	    cout<<"\nOperation not possible\n";
	else
	{
		cout<<"\nThe removed element is "<<num[rear];
		if(rear == front)
		{
			front = -1;
			rear = -1;
		}
		else
		    rear--;
	}
}

void Queue :: dequeueFront()
{
	if(front == -1)
	    cout<<"\nOperation not possible\n";
	else
	{
		cout<<"\nThe removed element is "<<num[front];
		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		    front++;
	}
}

void Queue :: disQueue()
{
	cout<<"\nThe current status of the queue : ";
	for(int i = front;i < rear + 1;i++)
	    cout<<num[i]<<"   ";
}

int main()
{
	Queue q;
	int i = 10, op, ele;
	
	cout<<"------------------------------------------------------\n";
    cout<<"   Program to perform Double-Ended Queue Operations";
	cout<<"\n----------------------------------------------------";
    
    while(i)
    {
        cout<<"\n\n\t1 - enqueueRear\n\t2 - enqueueFront";
        cout<<"\n\t3 - dequeueRear\n\t4 - dequeueFront\n\t5 - disqueue\n\t6 - Exit";
        cout<<"\n\nEnter your choice : ";
        cin>>op;
        
        switch (op)
        {
            case 1 :
                cout<<"\nEnter the element you wish to enter : ";
                cin>>ele;
                q.enqueueRear(ele);
                q.disQueue();
                break;
            case 2 :
                cout<<"\nEnter the element you wish to enter : ";
                cin>>ele;
                q.enqueueFront(ele);
                q.disQueue();
                break;
            case 3 :
                q.dequeueRear();
                cout<<"\n";
                q.disQueue();
                break;
            case 4 :
                q.dequeueFront();
                cout<<"\n";
                q.disQueue();
                break;
            case 5 :
                q.disQueue();
                break;
            case 6 :
                exit(0);
                break;
            default :
                cout<<"!! INVALID INPUT !!";
                break;
        }
    }
}
