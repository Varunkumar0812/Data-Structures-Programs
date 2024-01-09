#include<iostream>

using namespace std;

class Stack
{
	private :
		int top = -1;
		char num[100];
	public :
		void push(char);
		char pop();
		char stacktop();
		bool isempty();
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
		string str, respost, respref;
		char symb;
		int i;
	public :
		void getString();
		void contopost();
		void contopref();
};

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

bool Stack :: isempty()
{
	if(top == -1)
	    return true;
	else
	    return false;
}

bool Check :: isoperand(char m)
{
	if((m <= 'z' && m >= 'a') || (m <= 'Z' && m >= 'A'))
	    return true;
	else
	    return false;
}

bool Check :: isoperator(char m)
{
	if(m == '+' || m == '-' || m == '*' || m == '/' || m == '$')
	    return true;
	else
	    return false;
}

bool Check :: isclosparen(char m)
{
	if(m == ')')
	    return true;
	else
	    return false;
}

bool Check :: isopenparen(char m)
{
	if(m == '(')
	    return true;
	else
	    return false;
}

bool Check :: precedence(char m, char n)
{
	if(m == '$' && n != '$')
	    return true;
	else if(m == '*' || m == '/' || m == '%' && n != '$')
	    return true;
	else if(m == '+' && n == '+' || m == '+' && n == '-' || m == '-' && n == '+' || m == '-' && n == '-')
	    return true;
	else
	    return false;
}

void Convert :: getString()
{
	cout<<"\nEnter the infix string : ";
	cin>>str;
}

void Convert :: contopost()
{
	for(i = 0;i < str.length();i++)
	{
		if(c.isoperand(str[i]))
		    respost += str[i];
		else
		{
			if(c.isoperator(str[i]))
			{
				while(pop()!s.isempty() && !isopenparen(s.stacktop()) && c.precedence(s.stacktop(), str[i]))
				{
					symb = s.pop();
					respost += symb;
				}
			}
			
			if(!c.isclosparen(str[i]))
			    s.push(str[i]);
			
			if(c.isclosparen(str[i]))
			{
				while(!c.isopenparen(s.stacktop()))
				{
					symb = s.pop();
					respost += symb;
				}
				symb = s.pop();
			}
		}
	}
	
	while(!s.isempty())
	{
		symb = s.pop();
		respost += symb;
	}
	
	cout<<"\nPostfix Expression : ";
	cout<<respost;
}

void Convert :: contopref()
{
	for(i = str.length();i >= 0;i--)
	{
		if(c.isoperand(str[i]))
		    respref += str[i];
		else
		{
			if(c.isoperator(str[i]))
			{
				while(pop()!s.isempty() && !isclosparen(s.stacktop()) && c.precedence(s.stacktop(), str[i]))
				{
					symb = s.pop();
					respref += symb;
				}
			}
			
			if(!c.isopenparen(str[i]))
			    s.push(str[i]);
			
			if(c.isopenparen(str[i]))
			{
				while(!c.isclosparen(s.stacktop()))
				{
					symb = s.pop();
					respref += symb;
				}
				symb = s.pop();
			}
		}
	}
	
	while(!s.isempty())
	{
		symb = s.pop();
		respref += symb;
	}
	
	cout<<"Prefix Expression : ";
	for(int j = respref.length();j >= 0;j--)
	    cout<<respref[j];
}

int main()
{
	Convert y;
	y.getString();
	y.contopost();
	y.contopref();
	
	return 0;
}
