//Program to check whether a expression is properly parenthesised
#include<iostream>

using namespace std;

class Stack
{
	private :
		int top = -1;
		char num[];
	public :
		bool isfull();
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
	if(!isempty())
	{
		top--;
		return num[top + 1];
	}
}

int main()
{
    Stack s;
    string str;
    bool valid = true;
    int i = 0;
    char symb, t;
    
    cout<<"------------------------------------------------------\n";
    cout<<"        Program to check proper Parenthesis";
    cout<<"\n------------------------------------------------------\n";
	   
    cout<<"Enter the expression you want to check with any spaces : ";
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
    					if(symb == ')' || symb == ']')
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
    
	return 0;
}
