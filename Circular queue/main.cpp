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
	if((front == 0 && rear == SIZE - 1) || (rear == front - 1))
	    cout<<"\nQueue is full\n";
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
	    num[rear] = n;
	}
}

void Queue :: deQueue()
{
	if(front == -1 && rear == -1)
	    cout<<"\nQueue is empty\n";
	else
	{
		cout<<"\nThe removed element is "<<num[front];
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

void Queue :: disQueue()
{
	if(rear == -1 && front == -1)
	    cout<<"\nQueue is empty\n";
	else
	{
		if(front <= rear)
		{
			cout<<"\nThe current status of the queue : ";
	        for(int i = front;i < rear + 1;i++)
	            cout<<num[i]<<"   ";
		}
		else
		{
			cout<<"\nThe current status of the queue : ";
			for(int j = front;j < SIZE;j++)
			    cout<<num[j]<<"   ";
			for(int k = 0;k <= rear;k++)
			    cout<<num[k]<<"   ";
		}
	}
	

}

int main()
{
	Queue q;
	int i = 10, op, ele;
	
	cout<<"--------------------------------------------------\n";
    cout<<"   Program to perform Circular Queue Operations";
	cout<<"\n--------------------------------------------------\n";
    
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
}
