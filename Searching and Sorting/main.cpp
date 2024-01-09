#include<iostream>

#define SIZE 6
using namespace std;

class SearchSort
{
	int arr[SIZE];
	public :
		void getElements();
		void display();
		void seq_search(int);
		void bin_search(int);
		void bub_sort();
		void sel_sort();
		void ins_sort();
		void she_sort();
};

void SearchSort :: getElements()
{
	cout<<"\n\nEnter the elements : \n";
	for(int i = 0;i < SIZE;i++)
	{
		cout<<"Element "<<i<<" : ";
		cin>>arr[i];
	}
}

void SearchSort :: display()
{
	cout<<"\nCurrent status of array : ";
	for(int i = 0;i < SIZE;i++)
	    cout<<arr[i]<<"    ";
}

void SearchSort :: seq_search(int ele)
{
	bool flag = false;
	for(int i = 0;i < SIZE;i++)
	{
		if(arr[i] == ele)
		{
			cout<<"\nElement found at : "<<i;
			flag = true;
			break;
		}
	}
	if(!flag)
	    cout<<"\n!! Element not found !!";
}

void SearchSort :: bin_search(int ele)
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
	    cout<<"\nElement found at : "<<mid;
}

void SearchSort :: bub_sort()
{
	int t;
	for(int i = 1;i <= SIZE - 1;i++)
	    for(int j = 0;j <= SIZE - i - 1;j++)
	        if(arr[j] > arr[j + 1])
	        {
	        	t = arr[j];
	        	arr[j] = arr[j + 1];
	        	arr[j + 1] = t;
			}
}

void SearchSort :: sel_sort()
{
	int min, t;
	for(int i = 0;i <= SIZE - 2;i++)
	{
		min = i;
		for(int j = i + 1;j <= SIZE - 1;j++)
		    if(arr[j] < arr[min])
		        min = j;
		if(min != i)
		{
		   	t = arr[min];
		   	arr[min] = arr[i];
		   	arr[i] = t;
		}
	}
}

void SearchSort :: ins_sort()
{
	int t, j;
	for(int i = 1;i <= SIZE - 1;i++)
	{
		t = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > t)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = t;
	}
}

void SearchSort :: she_sort()
{
	int gap = SIZE / 2, t;
	bool swapped;
	do
	{
		do
		{
			swapped = false;
			for(int i = 0;i < SIZE-gap;i++)
			    if(arr[i] > arr[gap + i])
			    {
			    	t = arr[i];
			    	arr[i] = arr[i + gap];
			    	arr[i + gap] = t;
			    	swapped = true;
				}
		}while(swapped);
		gap = gap/2;
	}while(gap >= 1);
}

int main()
{
	int op, ele1, ele2, ch1, ch2;
	SearchSort s;
	
	cout<<"\n    -------------------------------------------------------------------------\n";
	cout<<"    |      Program to perform various Searching and Sorting Operations      |\n";
	cout<<"    -------------------------------------------------------------------------\n\n";
	
	s.getElements();
	s.display();
	
	while(1)
	{
		cout<<"\n\n\t1 - Searching\n\t2 - Sorting\n\t3 - Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>op;
		
		switch (op)
		{
			case 1 :
				cout<<"\n\n\t\t1 - Sequential Search\n\t\t2 - Binary Search";
				cout<<"\n\nEnter your choice : ";
				cin>>ch1;
				
				switch (ch1)
				{
					case 1 : 
					    cout<<"\nEnter the element you want to search : ";
					    cin>>ele1;
					    s.seq_search(ele1);
					    break;
					case 2 :
						cout<<"\nEnter the element you wish to search : ";
						cin>>ele2;
						s.bub_sort();
						s.bin_search(ele2);
						break;
					default :
						cout<<"\n!! INVALID INPUT !!";
						break;
				}
				break;
			case 2 :
				cout<<"\n\n\t\t1 - Bubble Sort\n\t\t2 - Selection Sort\n\t\t3 - Insertion Sort\n\t\t4 - Shell Sort";
				cout<<"\n\nEnter your choice : ";
				cin>>ch2;
				
				switch (ch2)
				{
					case 1 : 
					    s.bub_sort();
					    s.display();
					    break;
					case 2 :
						s.sel_sort();
						s.display();
						break;
					case 3 :
						s.ins_sort();
						s.display();
						break;
					case 4 :
						s.she_sort();
						s.display();
						break;
					default :
						cout<<"\n!! INVALID INPUT !!";
						break;
				}
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
