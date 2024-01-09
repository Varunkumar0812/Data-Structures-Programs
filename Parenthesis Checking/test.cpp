#include<iostream>

using namespace std;

class Stack
{
	private :
		int top = -1;
		char num[100];
	public :
		void push(char);
		bool isempty();
		char pop();
		char stacktop();
};

bool Stack :: isempty()
{
	if(top == -1)
	    return true;
	else
	    return false;
}

void Stack :: push(char m)
{
	top++;
	num[top] = m;
}

char Stack :: pop()
{
	return num[top--];
}

char Stack :: stacktop()
{
	return num[top];
}

int main()
{
	string str;
	Stack s;
	bool valid = true;
	int i = 0;
	char symb, t;
	
	cout<<"\nEnter the string : ";
	cin>>str;
	
	while(i < str.length())
	{
		symb = str[i];
		if(symb == '(' || symb == '[' || symb == '{')
		    s.push(symb);
		if(symb == ')' || symb == ']' || symb == '}')
		{
			if(s.isempty())
			    valid = false;
			else
			{
				t = s.pop();
				switch (t)
				{
					case '(' :
						if(symb == ']' || symb == '}')
						    valid = false;
						break;
					case '[' :
						if(symb == ')' || symb == '}')
						    valid = false;
						break;
					case '{' :
						if(symb == ']' || symb == ')')
						    valid = false;
						break;
				}
			}
		}
		i++;
	}
	
	if(!s.isempty())
	    valid = false;
	
	if(valid)
	    cout<<"\nString is valid";
	else
	    cout<<"\nString is invalid";
}
