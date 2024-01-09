#include<iostream>

#define SIZE 6

using namespace std;

class Searching
{
	public :
		int arr[SIZE];
	    void getElements();
	    void seq_search(int);
	    void bin_search(int);
};

void Searching :: getElements()
{
	cout<<"\n\nEnter the elements : \n";
	for(int i = 0;i < SIZE;i++)
	{
		cout<<"Element "<<i<<" : ";
		cin>>arr[i];
	}
}

void Searching :: seq_search(int ele)
{
	bool flag = false;
	for(int i = 0;i < SIZE;i++)
	{
		if(arr[i] == ele)
		{
			cout<<"\nElement found at : "<<i<<".";
			flag = true;
			break;
		}
	}
	if(!flag)
	    cout<<"\n!! Element not found !!";
}

void Searching :: bin_search(int ele)
{
	bool flag = false;
	int low = 0, high = SIZE - 1, mid;
	
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(arr[mid] == ele)
		{
			flag = true;
			break;
		}
		else
		{
			if(arr[mid] < ele)
			    low = mid + 1;
			else
			    high = mid - 1;
		}
	}
	
	if(!flag)
	    cout<<"\n!! Element not found !!";
	else
	    cout<<"\nElement found at "<<mid<<".";
}

int main()
{
	int op, ele1, ele2;
	Searching s;
	
	cout<<"--------------------------------------------------------------------\n";
	cout<<"      Program to perform various types of Searching Operations\n";
	cout<<"--------------------------------------------------------------------\n";
	
	s.getElements();
	
	while(1)
	{
	    cout<<"\n\n\t1 - Sequential Searching\n\t2 - Binary Searching\n\t3 - Exit";
	    cout<<"\n\nEnter your choice : ";
	    cin>>op;
	    
	    switch (op)
	    {
	    	case 1 :
	    		cout<<"\nEnter the elemwnt you wish to search : ";
	    		cin>>ele1;
	    		s.seq_search(ele1);
	    		break;
	    	case 2 :
	    		cout<<"\nEnter the element you wish to search : ";
	    		cin>>ele2;
	    		s.bin_search(ele2);
	    		break;
	    	case 3 :
	    		exit(0);
	    		break;
	    	default :
	    		cout<<"\n!! INVALID INPUT !!";
	    		break;
		}
	}
	return 0;
}
