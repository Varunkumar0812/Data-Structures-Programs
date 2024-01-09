#include<iostream>
#include<cmath>

using namespace std;

class Stack 
{
	private :
		int top = -1;
		float num[50];
	public :
		void push(float);
        float pop();
        bool isempty();
};

class Check
{
	public :
		bool isoperand(char);
		bool isoperator(char);
		float num(char);
		float valfin(float, float, char);
};

class Evaluate
{
	private :
		string str;
		Stack s;
		Check c;
		int i;
		float op1, op2, value;
	public :
		void getString();
		void Evapost();
		void Evapref();
};

void Stack :: push(float m)
{
	top++;
	num[top] = m;
}

float Stack :: pop()
{
	return num[top--];
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
	if(m >= '0' && m <= '9')
	    return true;
	else
	    return false;
}

bool Check :: isoperator(char m)
{
	if(m == '+' || m == '-' || m == '*' || m == '/' || m == '%')
	    return true;
	else
	    return false;
}

float Check :: num(char m)
{
	switch (m)
	{
		case '0' : return 0;
	    case '1' : return 1;
	    case '2' : return 2;
	    case '3' : return 3;
	    case '4' : return 4;
	    case '5' : return 5;
	    case '6' : return 6;
	    case '7' : return 7;
	    case '8' : return 8;
	    case '9' : return 9;
    }
}

float Check :: valfin(float m, float n, char o)
{
	switch (o)
	{
		case '+' : return (m+n);
		case '-' : return (m-n);
		case '*' : return (m*n);
		case '/' : return (m/n);;
		case '$' : return pow(m, n);
	}
}

void Evaluate :: getString()
{
	cout<<"\nEnter the string : ";
	cin>>str;
}

void Evaluate :: Evapost()
{
	for(i = 0;i < str.length();i++)
	{
		if(c.isoperand(str[i]))
		    s.push(c.num(str[i]));
		if(c.isoperator(str[i]))
		{
			op2 = s.pop();
			op1 = s.pop();
			value = c.valfin(op1, op2, str[i]);
			s.push(value);
		}
	}
	
	cout<<"\nThe value of the expression is : "<<s.pop();
}

void Evaluate :: Evapref()
{
	for(i = str.length();i >= 0;i--)
	{
		if(c.isoperand(str[i]))
		    s.push(c.num(str[i]));
		if(c.isoperator(str[i]))
		{
			op2 = s.pop();
			op1 = s.pop();
			value = c.valfin(op1, op2, str[i]);
			s.push(value);
		}
	}
	
	cout<<"\nThe value of the expression is : "<<s.pop();
}

int main()
{
	Evaluate e;
	int op;
	
	while(1)
	{
		cout<<"\n\t1 - Postfix Expression\n\t2 - Prefix Expression\n\t3 - Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>op;
		
		switch (op)
		{
			case 1 :
				e.getString();
				e.Evapost();
				break;
			case 2 :
				e.getString();
				e.Evapref();
				break;
			case 3 :
				exit(0);
			default : 
			    cout<<"\n!! INVALID INPUT !!";
			    break;
		}
	}
}
