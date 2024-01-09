//Program to convert an infix to postfix and prefix expression
#include <iostream>

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
		char stacktop();
};

class Check
{
	public :
		bool isoperand(char);
		bool isoperator(char);
		bool isclosparen(char);
		bool isopenparen(char);
		bool precedence(char, char);
};


class Convert
{
	private :
		Stack s;
	    Check c;
	    char symb;
	    int i;
	    string str, respost, respref;
	public :
		void getstring();
		void contopost();
		void contopref();
};

bool Check :: precedence(char m, char n)
{
	if(m == '$')
    {
    	if(n == '$')
    	    return false;
    	else
    	    return true;
    }
    else if(m == '*' || m == '/' || m == '%' && n != '$')
        return true;
    else if(m == '+' && n == '-' || m == '-' && n == '+' || m == '+' && n == '+' || m == '-' && n == '-')
        return true;
    else 
        return false;
}

bool Check :: isoperand(char n)
{
	if((n <= 'z' && n >= 'a') || (n <= 'Z' && n >= 'A'))
        return  true;
    else
        return false;
}

bool Check :: isoperator(char n)
{
    if(n == '+' || n == '-' || n == '*' || n == '/' || n == '$' || n == '^' || n == '%')
        return  true;
    else
        return false;
}

bool Check :: isclosparen(char n)
{
    if(n == ')')
        return  true;
    else
        return false;
}

bool Check :: isopenparen(char n)
{
    if(n == '(')
        return  true;
    else
        return false;
}

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
	return num[top + 1];
}

char Stack :: stacktop()
{
	return num[top];
}

void Convert :: getstring()
{
	cout<<"Enter the infix expression : ";
	cin>>str;
}

void Convert :: contopost()
{
		
	for(i = 0;i < str.length();i++)
	{
	    if(c.isoperand(str[i]))
	    {
	    	respost += str[i];
		}
		else
		{
			if(c.isoperator(str[i]))
			{
				while(!s.isempty() && !c.isopenparen(s.stacktop()) && c.precedence(s.stacktop(), str[i]))
				{
					symb = s.pop();
					respost += str[i];
				}
			}
			
			if(!c.isclosparen(str[i]))
			    s.push(str[i]);
			
			if(c.isclosparen(str[i]))
			{
				while(!c.isopenparen(s.stacktop()))
				{
					symb = s.pop();
					respost += str[i];
				}
				symb = s.pop();
			}
		}
	}
	
	while(!s.isempty())
	{
		symb = s.pop();
		respost += str[i];
	}
	
	cout<<"\nPostfix Expression :  ";
	cout<<respost;
}

void Convert :: contopref()
{
		
	for(i = str.length();i >= 0;i--)
	{
	    if(c.isoperand(str[i]))
	    {
	    	respref += str[i];
		}
		else
		{
			if(c.isoperator(str[i]))
			{
				while(!s.isempty() && !c.isclosparen(s.stacktop()) && c.precedence(s.stacktop(), str[i]))
				{
					symb = s.pop();
					respref += str[i];
				}
			}
			
			if(!c.isopenparen(str[i]))
			    s.push(str[i]);
			
			if(c.isopenparen(str[i]))
			{
				while(!c.isclosparen(s.stacktop()))
				{
					symb = s.pop();
					respref += str[i];
				}
				symb = s.pop();
			}
		}
	}
	
	while(!s.isempty())
	{
		symb = s.pop();
		respref += str[i];
	}
	
	cout<<"Prefix Expression  :";
	for(int j = respref.length();j >= 0;j--)
	{
		cout<<respref;
	}
}

int main()
{
	cout<<"----------------------------------------------------------------\n";
	cout<<"   Program to convert an Infix to Postfix & Prefix Expression";
	cout<<"\n----------------------------------------------------------------\n\n";
	
	Convert y;
	y.getstring();
	y.contopost();
	cout<<"\n";
	y.contopref();
	
	return 0;
}
