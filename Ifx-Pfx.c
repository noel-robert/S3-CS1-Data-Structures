/*
<-- this is wrong -->
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int top=-1;										// top position of stack
//int max_size = 0;
char stk[1000];								// stack to store operators
char ifx[1000], pfx[1000];	

void push(char item)					// push to stack
{
	stk[++top] = item;
	//printf("Pushed: %c\n", item);
}

char pop()										// pop from stack
{
	//char item = stk[top--];
	//printf("Popped: %c\n", item);
	//return item;
	return stk[top--];
}

int priority(char ele)				// finding priority of operator
{
	switch(ele)
	{
		case '^' : return 3;
		case '*' :
		case '/' : return 2;
		case '+' : 
		case '-' : return 1;
		case '(' : return 0;
	}
}

void infix_to_postfix(char* ifx, char* pfx)
{
	char ch, temp;
	int i = 0, p = 0;// counter variables, i to traverse through infix expression, p for postfix
	push('(');

	while ((ch = ifx[i++]) != '\n')
	{
		if(ch == '(' || ch == '^')			// if ch is '(' or '^', push to stack
			push(ch);
		if(isalnum(ch))								// if it is an operand, add to pfx			
			pfx[p++] = ch;	
		else if(ch == ')')						// if ch is ')', pop and add to pfx till '(' is found
		{
			while(stk[top] != '(')
				pfx[p++] = pop();
			temp = pop();										// to remove '('
		}	
		else															// operator, so check priority
		{
			while(priority(stk[top]) >= priority(ch))
				pfx[p++] = pop();
			push(ch);	
		}		
	}
	
	while (top != -1 && stk[top] != '(')	// pop from stack till empty 
  	pfx[p++] = pop();

	// while(stk[top] != '(')
	// 	pfx[p++] = pop();

	pfx[p] = 0;	
}

int postfix_eval(char* pfx)
{
	char ch;						
	int a,b;						// operands
	int i=0;
	
	while((ch = pfx[i++]) != '\n')
	{
		if(isdigit(ch))
			push(ch);
		else								// ch is an operator
		{
			b = pop();
			a = pop();

			switch(ch)
			{
				case '+' : push(a + b); break;
				case '-' : push(a - b); break;
				case '*' : push(a * b); break;
				case '/' : push(a / b); break;
				case '^' : push(a ^ b); break;					 
			}
		}	
	}

	return stk[top];							// returns result
}

// void append(char* s)
// {
// 	int len = strlen(s);
//   s[len] = ')';
//   s[len+1] = '\0';
// }

int main()
{
	printf("Input infix expression without any spaces ");
	
	fgets(ifx, 1000, stdin);			// enter infix expression
	
	//append(ifx);
	
	//char ch[1] = ")";
	//strcat(ifx, ch);
	
	//int i=0;
	//while(ifx[i++] != '\0');
	//ifx[i] = ')';
	
	//ifx[i+1] = '\0';
	infix_to_postfix(ifx, pfx);	// convert infix to postfix expression

	printf("Given infix expression is %s", ifx);
	printf("Postfix expression is %s\n", pfx);

	//printf("Result after postfix evaluation is %d\n", postfix_eval(pfx));
	return 0;
}