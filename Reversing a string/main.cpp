#include<iostream>

using namespace std;

class Stack
{
	private :
		int top = -1;
		char num[100];
	public :
		bool isempty();
		void push(char);
		char pop();
};

bool Stack :: isempty()
{
	if(top == -1)
	    return true;
	else
	    return false;
}

void Stack :: push(char n)
{
	top++;
	num[top] = n;
}

char Stack :: pop()
{
	top--;
	return num[top+1];
}

int main()
{
	Stack s;
	string str, res;
	int i;
	
    cout<<"------------------------------------------------\n";
	cout<<"    Program to reverse a string using stacks";
	cout<<"\n------------------------------------------------";
	
	cout<<"\n\nEnter the string : ";
	cin>>str;
	
	for(i = 0;i < str.length();i++)
		s.push(str[i]);
		
	for(i = 0;i < str.length();i++)
		res = res + s.pop();

	cout<<"\nThe reversed string is : ";
	cout<<res;
}
