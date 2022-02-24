// DS lab qn 2
// program to implement stack and queue
// status: working

#include <stdio.h>
#include <stdlib.h>

int top=-1, front=-1, rear=-1;  // global variables
int max_size = 0;
int* stk = 0;
int* que = 0;

void push(int item)			// pushing to stack
{
	if(top == max_size-1)
	{
		printf("Overflow, cannot push new element\n");
		return;
	}
	else
	{
		top++;
		stk[top] = item;
	}
}

void pop()							// popping from stack
{
	if(top == -1)
	{
		printf("Underflow\n");
		return;
	}
	else
	{
		printf("Item popped: %d\n", stk[top]);
		top--;
	}		
}

void stackDisplay()				// display stack
{
	if(top == -1)
	{
		printf("Empty stack\n");
		return;
	}
	else
	{
		for(int i=top; i>=0; i--)
			printf("%d ", stk[i]);
		printf("\n");	
	}
}

void stackMenu()
{
	printf("Input size of stack: "); 
	scanf("%d", &max_size);
	stk = (int*)malloc(max_size * sizeof(int));
	
	int code;
	do
	{
		printf("\n1. Push to stack\n");
		printf("2. Pop from stack\n");
		printf("3. Display stack\n");
		printf("4. Exit from stack menu\n");
		scanf("%d", &code);							// input choice here

		int item;
		switch(code)
		{
			case 1:	printf("Input item to push to stack: "); scanf("%d", &item);
							push(item); 
							break;
			case 2:	pop(); 
							break;
			case 3: stackDisplay(); 
							break;
			case 4: printf("Exiting program on user input\n"); 
							break;
			default:printf("Wrong code inputted\n");
		}
	}while(code != 4);
	free(stk);
}

void enqueue(int item)		// insert to queue
{
	if(rear == max_size-1)
	{
		printf("Overflow\n");
		return;
	}

	if(rear == -1)
		front=rear=0;
	else
		rear++;
	que[rear] = item;	
}

void dequeue()					// remove from queue
{
	if(front == -1)
	{
		printf("Underflow\n");
		return;
	}

	printf("Item removed from queue: %d", que[front]);
	if(front == rear)
		front = rear = -1;
	else
		front = front+1;	
}

void queueDisplay()		// display queue
{
	if(front == -1 || rear == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	else
	{
		for(int i=front; i<=rear; i++)
			printf("%d ", que[i]);
		printf("\n");	
	}		
}

void queueMenu()
{
	printf("Input size of queue: "); 
	scanf("%d", &max_size);
	que = (int*)malloc(max_size * sizeof(int));
	
	int code;
	do
	{
		printf("\n1. Enqueue to queue\n");
		printf("2. Dequeue from queue\n");
		printf("3. Display queue\n");
		printf("4. Exit from queue menu\n");
		scanf("%d", &code);							// input choice here

		int item;
		switch(code)
		{
			case 1:	printf("Input item to enter to queue: "); scanf("%d", &item);
							enqueue(item);
							break;
			case 2:	dequeue(); 
							break;
			case 3: queueDisplay(); 
							break;
			case 4: printf("Exiting program on user input\n"); 
							break;
			default:printf("Wrong code inputted\n");
		}
	}while(code != 4);
	free(que);
}

int main()
{
	int code;
	do
	{
		printf("1. Perform Stack operations\n");
		printf("2. Perform Queue operations\n");
		printf("3. Exit program\n");
		scanf("%d", &code);							// input choice here

		switch(code)
		{
			case 1:	stackMenu(); printf("\n");
							break;
			case 2:	queueMenu(); printf("\n");
							break;
			case 3: printf("Exiting program on user input\n"); 
							break;
			default:printf("Wrong code inputted\n");
		}
	}while(code != 3);
	return 0;
}