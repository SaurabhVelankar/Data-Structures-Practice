
#include<iostream>
#include<cstdio>
using namespace std;

class Stack
{
private:
	int top;
	char stack[50];

public:
	Stack()
	{
		top = -1;
	}

	void Push(char);
	char Pop();
	char Top();
	void PrintStack();
	int IsEmpty();
	int IsFull();
};

class Expression
{
private:
	string exp;
public:
	//Expressions Functions
	void ReadExpression();
	void PrintExpression();
	//Evaluation Functions
	void EvaluateExpressions();
	int EvaluatePrefix();
	int EvaluatePostfix();
	int EvaluateInfix();
	int PerformOperation(char, int, int);
	int IsOperator(char);
	int IsNumericDigit(char);
	//Expression Validity
	int CheckIfInfix(string);
	int CheckIfPrefix(string);
	int CheckIfPostfix(string);
	//Convert Expressions Functions
	void ConvertExpression();
	void InfixToPrefix();
	void InfixToPostfix();
	void PrefixToInfix();
	void PrefixToPostfix();
	void PostfixToInfix();
	void PostfixToPrefix();
	//Miscellaneous Functions


};

int main()
{
	Stack s;
	Expression e;

	int choice;

	cout<<"______Welcome to My Code Practice!!______\n";
    cout<<"We'll be learning Expression Conversion and Evaluation this time!\n";
    cout<<endl<<endl;

    do
    {
        cout<<"Enter the operation you want to perform\n";
        cout<<"1] Read Expression \n2] Print current Expression \n3] Evaluate Expressions \n4] Convert Expressions \n5] Exit \n";
        cin>>choice;

        switch(choice) //Entered choices are in Switch case
        {
        	case 1:
            	e.ReadExpression();
            break;

            case 2:
            	e.PrintExpression();
            break;

            case 3:
            	e.EvaluateExpressions();
            break;

            case 4:
                e.ConvertExpression();
            break;

            case 5:
                cout<<"Exiting...\n Thanks for the practicing with me!";
                choice = 0;
            break;

            default:
                    cout<<"Enter the correct choice!\n";
        }

    }while(choice != 0);

    return 0;
}

//Stack Functionalities from class Stack
void Stack :: Push(char value) //Push the parameter in the stack
{
	top++;
	stack[top] = value;
}

char Stack :: Pop () //Return the popped element
{
	return stack[top--];
}

char Stack :: Top() // Function can be modified to simply print top, unneeded here
{
	return stack[top];
}

void Stack :: PrintStack() //Simply print the stack
{
	int i;
	if(IsEmpty())
	{
		cout<<"Stack is Empty, color Cannot Print!\n\n";
		return;
	}
	//printf("top is: %d", top);
	cout<<"The Stack is:  ";
	for(i = 0; i < top + 1; i++)
		cout<<" "<<stack[i];
	printf("\n\n");
}

int Stack :: IsEmpty() //Check whether the stack is empty
{
	return (top == -1);
}

int Stack :: IsFull()
{
	return (top == 49);
}

//Expression Functionalities

void Expression :: ReadExpression()
{
	cout<<"\nEnter a valid expression\n";
	cin>>exp;
	cout<<endl;
}

void Expression :: PrintExpression()
{
	if(CheckIfInfix(exp))
		cout<<"The Expression is "<< exp <<" and is an Infix Expression\n\n";
	else if(CheckIfPrefix(exp))
		cout<<"The Expression is " << exp <<" and is a Prefix Expression\n\n";
	else if(CheckIfPostfix(exp))
		cout<<"The Expression is "<< exp <<" and is a Postfix Expression\n\n";
	else
		cout<<"The Expression is "<< exp <<" and is an INVALD Expression\n\n";
}

void Expression :: EvaluateExpressions() //Evaluates Expressions when taking in an input string, "auto-detects" the type of expression
{
	int ans = 0;

	if(CheckIfInfix(exp))
	{
		cout<<"The Expression is "<< exp <<" and is a Infix Expression\n";
	}
	else if(CheckIfPrefix(exp))
	{
		cout<<"The Expression is " << exp <<" and is a Prefix Expression\n";
	}
	else if(CheckIfPostfix(exp))
	{
		cout<<"The Expression is "<< exp <<" and is a Postfix Expression\n";
	}
	else
	{
		cout<<"The Expression is "<< exp <<" and is an INVALD Expression\n";
		return;
	}

	printf("The Expression has been evaluated and the answer is %d\n\n", ans);
}

int Expression :: CheckIfInfix(string exp) //Check whether the input string is Infix
{
	int i, countOperand = 0, countOperator = 0;
	for(i = 0; i < exp.length() - 1; i++)
	{
		if(IsNumericDigit(exp[i]))
			countOperand++;
		if(IsOperator(exp[i]))
			countOperator++;
	}
	if(countOperand - countOperator != 1)
		return 0;

	if(!IsNumericDigit(exp[0]) && !IsOperator(exp[1]) && !IsNumericDigit(exp[2]))
		return 0;
	return 1;
}

int Expression :: CheckIfPostfix(string exp) //Check whether the input string is Postfix
{
	int i, countOperand = 0, countOperator = 0;
	for(i = 0; i < exp.length() - 1; i++)
	{
		if(IsNumericDigit(exp[i]))
			countOperand++;
		if(IsOperator(exp[i]))
			countOperator++;
	}
	if(countOperand - countOperator != 1)
		return 0;

	if(!IsNumericDigit(exp[0]) && !IsNumericDigit(exp[2]) && !IsOperator(exp[1]))
		return 0;
	return 1;
}

int Expression :: CheckIfPrefix(string exp) //Check whether the input string is Prefix
{
	Stack s;
	int i, countOperand = 0, countOperator = 0;
	for(i = 0; i < exp.length() - 1; i++)
	{
		if(IsNumericDigit(exp[i]))
			countOperand++;
		if(IsOperator(exp[i]))
			countOperator++;
	}
	if(countOperand - countOperator != 1)
		return 0;

	if(!IsNumericDigit(exp[0]) && !IsNumericDigit(exp[2]) && !IsOperator(exp[1]))
		return 0;
	return 1;
}

void Expression :: ConvertExpression() //Converts Expressions from one form to another, Can "auto-detect" and provide you the right options
{
	int choice;

	if(CheckIfInfix(exp))
	{
		cout<<"The Entered expression is an Infix Expression, You can convert it to the following forms\n";
		cout<<"1] Infix to Prefix \n2] Infix to Postfix\n";
		cout<<"Enter your choice\n";
		cin>>choice;
		if(choice == 1)
		{
			InfixToPrefix();
			return;
		}
		else if(choice == 2)
		{
			InfixToPostfix();
			return;
		}
		else
		{
			cout<<"Enter correct option!\nGoing Back...\n";
			return;
		}
	}

	if(CheckIfPrefix(exp))
	{
		cout<<"The Entered expression is a Prefix Expression, You can convert it to the following forms\n";
		cout<<"1] Prefix to Infix\n2] Prefix to Postfix\n";
		cout<<"Enter your choice\n";
		cin>>choice;
		if(choice == 1)
		{
			PrefixToInfix();
			return;
		}
		else if(choice == 2)
		{
			PrefixToPostfix();
			return;
		}
		else
		{
			cout<<"Enter correct option!\nGoing Back...";
			return;
		}
	}
	if(CheckIfPostfix(exp))
	{
		cout<<"The Entered expression is a Postfix Expression, You can convert it to the following forms\n";
		cout<<"1] Postfix to Prefix \n2] Postfix to Infix\n";
		cout<<"Enter your choice\n";
		cin>>choice;
		if(choice == 1)
		{
			PostfixToPrefix();
			return;
		}
		else if(choice == 2)
		{
			PostfixToInfix();
			return;
		}
		else
		{
			cout<<"Enter correct option!\nGoing Back...";
			return;
		}
	}
}

void Expression :: InfixToPrefix() //Convert from Infix to Prefix
{

}

void Expression :: InfixToPostfix() //Convert from Infix to Postfix
{

}

void Expression :: PrefixToInfix() //Convert from Prefix to Infix
{

}

void Expression :: PrefixToPostfix() //Convert from Prefix to Postfix
{

}

void Expression :: PostfixToInfix() //Convert from Postfix to Infix
{

}

void Expression :: PostfixToPrefix() //Convert from Postfix to Prefix
{

}

int Expression :: IsOperator(char oprtr)
{
	if(oprtr == '+' || oprtr == '-' || oprtr == '*' || oprtr == '/')
		return 1;
	return 0;
}

int Expression::IsNumericDigit(char oprnd)
{
	if((oprnd >= '0' && oprnd <= '9') || (oprnd >= 'a' && oprnd <= 'z') || (oprnd >= 'A' && oprnd <= 'Z'))
		return 1;
	return 0;
}

int Expression::PerformOperation(char oprtr, int op1, int op2)
{

}
