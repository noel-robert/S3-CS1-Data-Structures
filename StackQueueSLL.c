// Noel John Robert
// implement stack and queue using Singly Linked List
// 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int info;
	struct Node *link;
} *head, *temp, *ptr, *front=NULL, *rear=NULL;

// stack operations
void push(int item)
{
	// insert new node to first position
	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->info = item;			
	temp->link = head;
	head = temp;
	return;
}

void pop()
{
	// remove node at first position
	if(head == NULL)
	{
		printf("Underflow \n");
		return;
	}

	printf("Item popped: %d\n", head->info);
	temp = head;
	head = head->link;
	free(temp);
	return;
}

void stackDisplay()
{
	if(head == NULL)
	{
		printf("Empty stack \n");
		return;
	}
	ptr = head;
	while(ptr != NULL)
	{
		printf("%d ", ptr->info);
		ptr = ptr->link;
	}
	printf("\n");
}

void stackMenu()
{
	int code;
	do
	{
		printf("1. Push to stack\n");
		printf("2. Pop from stack\n");
		printf("3. Display stack\n");
		printf("4. Exit from stack menu\n");
		scanf("%d", &code);							// input choice here

		int item;
		switch(code)
		{
			case 1:	printf("Input item to push to stack: "); scanf("%d", &item);
							push(item); break;
							
			case 2:	pop(); break;
							
			case 3: stackDisplay(); break;
							
			case 4: printf("Exiting program on user input\n"); break;
							
			default:printf("Wrong code inputted\n"); break;
		}
	}while(code != 4);
}


// queue operations
void enqueue(int item)
{
	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->info = item;
	temp->link = NULL;

	if((front==rear) && (front==NULL))	// empty SLL
		front = rear = temp;
	else
	{
		rear->link = temp;
		rear = temp;
	}

	return;
}

void dequeue()
{
	if(front == NULL)
	{
		printf("Underflow");
		return;
	}
	printf("Item popped: %d\n", front->info);
	temp = front;

	if(front == rear)		// only one element
		front = rear = NULL;
	else
		front = front->link;

	free(temp);
	return;	
}

void queueDisplay()
{
	ptr = front;
	if(front == NULL)
	{
		printf("Empty queue \n");
		return;
	}
	
	while(ptr != NULL)   
	{  
			printf("%d ",ptr->info);  
			ptr = ptr->link;  
	}
	printf("\n");
}

void queueMenu()
{
	int code;
	do
	{
		printf("1. Enqueue to queue\n");
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
			case 1:	stackMenu(); printf("\n"); head = NULL;
							break;
			case 2:	queueMenu(); printf("\n"); front = NULL; rear = NULL;
							break;
			case 3: printf("Exiting program on user input\n"); 
							break;
			default:printf("Wrong code inputted\n");
		}
	}while(code != 3);
	return 0;
}