#include<iostream>

using namespace std;

void insert(int [], int *, int, int); // Insertion Function
void insert(int arr[], int *n, int ele, int pos)
{
    for(int i = *n - 1;i >= pos;i--)
        arr[i + 1] = arr[i];
    arr[pos] = ele;
    *n++;
}

void del(int [], int *, int, int *); // Deletion Function
void del(int arr[], int *n, int pos, int *ele)
{
    *ele = arr[pos];
    for(int i = pos;i < *n - 1;i++)
        arr[i] = arr[i + 1];
    *n--;
}

void traverse(int [], int); // Traversion Function
void traverse(int arr[], int n)
{
    cout<<"\nCurrent status of the array : \n";
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<"  ";
}

void drawline();  // A Function to draw lines
void drawline()
{
    cout<<"\n--------------------------------------------------------------------------------\n";
}

int main()
{
    int arr[100], n, ele, pos, op, i;
    
    drawline();
    cout<<"\t\t    Program to perform various Array Operations";
    drawline();
    
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    for(i = 0;i < n;i++)
    {
        cout<<"Element "<<i<<" : ";
        cin>>arr[i];
    }
    
    traverse(arr, n);
    
    for(i = 0;i >= 0;i++) // A loop so that the operations can be performed repeatedly without just exiting after one operation
    {
        drawline();
        cout<<"\t1 - Insertion\n";
        cout<<"\t2 - Deletion\n";
        cout<<"\t3 - Traversion\n";
        cout<<"\t4 - Exit";
        drawline();
        cout<<"\nEnter the number to perform the corresponding operation : ";
        cin>>op;
    
        switch (op)
        {  
            case 1 : 
                for(i = 0;i >= 0;i++)
                {
                    cout<<"\n\nEnter the element you wish to insert : ";
                    cin>>ele;
    
                    cout<<"Enter the position where you wish to add this element : ";
                    cin>>pos;
        
                    if(pos <= n)
                    {
                        insert(arr, &n, ele, pos);
                        traverse(arr, n);
                        break;
                    }
                    else
                    {
                        cout<<"\n!!!!The number you entered is not within the bound of the array size!!!!";
                    }
                }
                break;
            case 2 :
                for(i = 0;i >= 0;i++)
                {
                    cout<<"\n\nEnter the position of the element you wish to delete : ";
                    cin>>pos;
        
                    if(pos <= n)
                    {
                        del(arr, &n, pos, &ele);
                        traverse(arr, n);
                        
                        cout<<"\n\nThe deleted element is "<<ele<<".";
                        break;
                    }
                    else
                    {
                        cout<<"\n!!!!The number you entered is not within the bound of the array size!!!!";
                    } 
                } 
                break;
            case 3 :
                traverse(arr, n);
                break;
            case 4 :
                exit(0);
                break;
            default :
                cout<<"\n!!! Enter a valid number !!!";
                break;
        }
    }
    return 0;

}



