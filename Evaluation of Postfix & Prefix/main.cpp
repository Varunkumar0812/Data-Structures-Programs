#include<iostream>
#include<cmath>

using namespace std;

class Stack
{
	private :
		int top = -1;
		float num[50];
	public :
		bool isempty();
		void push(float);
		float pop();
};

class Check
{
	public :
		bool isoperand(char);
		bool isoperator(char);
		float valfin(float, float, char);
		float num(char);
};

class Evaluate 
{
	private :
		string str;
	    Stack s;
	    Check c;
	    float op2, op1, value;
	public :
		void getstring();
		void Evapost();
		void Evapref();		
};

float Check :: num(char m)
{
	switch (m)
	{
		case '0' :
			return 0;
		case '1' :
			return 1;
		case '2' :
			return 2;
		case '3' :
			return 3;
		case '4' :
			return 4;
		case '5' :
			return 5;
		case '6' :
			return 6;
		case '7' :
			return 7;
		case '8' :
			return 8;
		case '9' :
			return 9;
	}
}

float Check :: valfin(float m, float n, char o)
{
	switch (o)
	{
		case '+' :
			return (m+n);
		case '-' :
			return (m-n);
		case '*' :
			return (m*n);
		case '/' :
			return (m/n);
		case '$' :
			return pow(m, n);
	}
}

bool Check :: isoperand(char n)
{
	if(n >= '0' && n <= '9')
	    return true;
	else
	    return false;
}

bool Check :: isoperator(char n)
{
	if(n == '+' || n == '-' || n == '*' || n == '/' || n == '$')
	    return true;
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

void Stack :: push(float n)
{
	top++;
	num[top] = n;
}

float Stack :: pop()
{
	top--;
	return num[top+1];
}

void Evaluate :: getstring()
{
	cout<<"Enter a string using only single digit numbers : ";
	cin>>str;
}

void Evaluate :: Evapost()
{
	for(int i = 0;i < str.length();i++)
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
	cout<<"\nThe value of the expression is ";
	cout<<s.pop();
}

void Evaluate :: Evapref()
{
	for(int i = str.length();i >= 0;i--)
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
	cout<<"\nThe value of the expression is ";
	cout<<s.pop();
}


int main()
{
	Evaluate e;
	int op, t = 1;
	
	while(t)
	{
		cout<<"\n---------------------------------------------------------";
		cout<<"\n    Program to evaluate Postfix and Prefix expression\n";
		cout<<"---------------------------------------------------------\n\n";
	    cout<<"\t1 - Postfix Expression\n\t2 - Prefix Expression\n\t3 - Exit";
	    cout<<"\n\nEnter your choice : ";
	    cin>>op;
	
     	switch (op)
    	{
	 	    case 1 :
	 		    e.getstring();
			    e.Evapost();
			    break;
	      	case 2 :
		    	e.getstring();
			    e.Evapref();
		    	break;
		    case 3 :
		    	exit(0);
		    	break;
		    default :
		    	cout<<"\n!! Invalid Input !!";
		    	break;
	    }
	}
    return 0;
}
