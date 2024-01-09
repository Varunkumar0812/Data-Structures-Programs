#include<iostream>

using namespace std;

struct Node
{
	int coeff, exop;
	Node *next;
};

void create(Node **head, int co, int ex)
{
	Node *ptr = new Node;
	ptr->coeff = co;
	ptr->exop = ex;
	ptr->next = NULL;
	
	if(*head == NULL)
	    *head = ptr;
	else
	{
		Node *temp = *head;
		while(temp->next != NULL)
		    temp = temp->next;
		temp->next = ptr;
	}
}

Node * polyAdd(Node *A_Ptr, Node *B_Ptr, Node *C_Ptr)
{
	Node *f;
	while(A_Ptr != NULL && B_Ptr != NULL)
	{
		Node *newTerm = new Node;
		newTerm->next = NULL;
		
		if(A_Ptr->exop == B_Ptr->exop)
		{
			newTerm->exop = A_Ptr->exop;
			newTerm->coeff = A_Ptr->coeff + B_Ptr->coeff;
			A_Ptr = A_Ptr->next;
			B_Ptr = B_Ptr->next;
		}
		else if(A_Ptr->exop > B_Ptr->exop)
		{
			newTerm->exop = A_Ptr->exop;
			newTerm->coeff = A_Ptr->coeff;
			A_Ptr = A_Ptr->next;
		}
		else
		{
			newTerm->exop = B_Ptr->exop;
			newTerm->coeff = B_Ptr->coeff;
			B_Ptr = B_Ptr->next;
		}
		
		if(C_Ptr == NULL)
		{
			C_Ptr = newTerm;
			f = newTerm;
		}
		else
		{
			C_Ptr->next = newTerm;
			C_Ptr = newTerm;
		}
	}
	
	while(A_Ptr != NULL)
	{
		Node *newTerm1 = new Node;
		newTerm1->next = NULL;
		newTerm1->exop = A_Ptr->exop;
		newTerm1->coeff = A_Ptr->coeff;
		A_Ptr = A_Ptr->next;
		
		if(C_Ptr == NULL)
		{
			C_Ptr = newTerm1;
            f = newTerm1;
		}
		else
		{
			C_Ptr->next = newTerm1;
			C_Ptr = newTerm1;
		}
	}
	
	while(B_Ptr != NULL)
	{
		Node *newTerm2 = new Node;
		newTerm2->next = NULL;
		newTerm2->exop = B_Ptr->exop;
		newTerm2->coeff = B_Ptr->coeff;
		B_Ptr = B_Ptr->next;
		
		if(C_Ptr == NULL)
		{
			C_Ptr = newTerm2;
            f = newTerm2;
		}
		else
		{
			C_Ptr->next = newTerm2;
			C_Ptr = newTerm2;
		}
	}
	return f;
}

void getValues()
{
	Node *A_Ptr = NULL;
	Node *B_Ptr = NULL;
	Node *C_Ptr = NULL;
	Node *f;
	
	int i = 8, coe, exo;
	
	cout<<"   ------------------------------------------------------------------------------\n";
	cout<<"   |                    Polynomial Addition - Linked Lists                      |";
	cout<<"\n   ------------------------------------------------------------------------------\n\n\n";
	
	cout<<"To stop writing new terms, Enter zero for both Co-efficient and Exponential\n\n";
	cout<<"------------------------\n";
	cout<<"      POLYNOMIAL 1";
	cout<<"\n------------------------\n";
	
	while(i)
	{
		cout<<"\nEnter the co-efficient : ";
		cin>>coe;
		cout<<"Enter the exponential : ";
		cin>>exo;
		
		if(coe == 0 && exo == 0)
			break;
		else
		    create(&A_Ptr, coe, exo);
	}
	
	cout<<"\n------------------------\n";
	cout<<"      POLYNOMIAL 2";
	cout<<"\n------------------------\n";
	
	while(i)
	{
		cout<<"\nEnter the co-efficient : ";
		cin>>coe;
		cout<<"Enter the exponential : ";
		cin>>exo;
		
		if(coe == 0 && exo == 0)
			break;
		else
		    create(&B_Ptr, coe, exo);
	}
	
	f = polyAdd(A_Ptr, B_Ptr, C_Ptr);
    
    cout<<"\n------------------------------";
    cout<<"\nThe resultant polynomial is : \n";
    cout<<"------------------------------\n\n";
	Node *temp = f;
	while(temp->next != NULL)
	{
	    cout<<temp->coeff<<" X "<<temp->exop<<endl;
	    temp = temp->next;
	}
	cout<<temp->coeff<<" X "<<temp->exop;
}

int main()
{
	getValues();
	return 0;
}
