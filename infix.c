#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int top = -1;							// top position of stack
char stk[1000];						// stack to store operators	

void push(char item)			// push to stack
{
	stk[++top] = item;
}

char pop()								// pop from stack
{
	return stk[top--];
}

int priority(char ele)		// finding priority of operator
{
	switch (ele)
	{
		case '(': return 1;
 
 		case '+':
 		case '-': return 2;
 
 		case '*':
 		case '/': return 3;
	}
}

void infix_to_postfix(char* ifx, char* pfx)
{
	char ch, temp;
	int i = 0, p = 0;// counter variables, i to traverse through infix expression, p for postfix
	push('(');

	while ((ch = ifx[i++]) != '\n')
	{
		if(ch == '(' || ch == '^')		// if ch is '(' or '^', push to stack
			push(ch);
		else if(isalnum(ch))					// if it is an operand, add to pfx			
			pfx[p++] = ch;	
		else if(ch == ')')						// if ch is ')', pop and add to pfx till '(' is found
		{
			while(stk[top] != '(')
				pfx[p++] = pop();
			temp = pop();								// to remove '('
		}	
		else													// operator, so check priority
		{
			while(priority(stk[top]) >= priority(ch))
				pfx[p++] = pop();
			push(ch);	
		}		
	}
	
	while (top != -1 && stk[top] != '(')	// pop from stack till empty 
  	pfx[p++] = pop();

	pfx[p] = 0;	
}

int postfix_eval(char* pfx)
{
	char ch;						
	int a,b;						// operands
	int i=0;
	
	while((ch = pfx[i++]) != 0)
	{
		if(isdigit(ch))
			push(ch-'0');			// converts character to integer
		else								// ch is an operator
		{
			b = pop();
			a = pop();
			double res;
			switch(ch)
			{
				case '+' : push(a + b); break;
				case '-' : push(a - b); break;
				case '*' : push(a * b); break;
				case '/' : push(a / b); break;
				case '^' : res = pow((double)(a), (double)(b));
										push(res); break;				 
			}
		}	
	}

	return stk[top];							// returns result
}

int main()
{
	char ifx[1000], pfx[1000];

	printf("Input infix expression without any spaces ");
	
	fgets(ifx, 1000, stdin);			// enter infix expression
	

	infix_to_postfix(ifx, pfx);	// convert infix to postfix expression

	printf("Given infix expression is %s", ifx);
	printf("Postfix expression is %s\n", pfx);

	printf("Result after postfix evaluation is %d\n", postfix_eval(pfx));
	return 0;
}