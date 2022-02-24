// Noel John Robert
// Program to implement dequeue

#include <stdio.h>
#include <stdlib.h>

int front=-1, rear=-1;  // global variables
int max_size = 0;
int* que = 0;


void insert_front(int item)
{
	if(front == (rear+1)%max_size)
	{
		printf("Overflow\n");
		return;
	}

	if(front == -1)			// no element present
		front = rear = 0;
	else if(front == 0)
		front = max_size-1;
	else
		front = front-1;

	que[front] = item;
	return;
}

void insert_rear(int item)
{
	if(front == (rear+1)%max_size)
	{
		printf("Overflow\n");
		return;
	}

	if(front == -1)
		front = rear = 0;
	else
		rear = (rear+1)%max_size;

	que[rear] = item;
	return;
}

void delete_front()
{
	if(front == -1)
	{
		printf("Underflow\n");
		return;
	}
	printf("Item removed from queue: %d\n", que[front]);

	if(front == rear)
		front = rear = -1;
	else
		front = (front+1)%max_size;

	return;
}

void delete_rear()
{
	if(front == -1)
	{
		printf("Underflow\n");
		return;
	}
	printf("Item removed from queue: %d\n", que[rear]);
	
	if(front == rear)
		front = rear = -1;
	else if(rear == 0)
		rear = max_size-1;
	else
		rear = rear-1;

	return;
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
		int i = front;
		printf("%d ", que[i]);
		if(front != rear)
		{
			do
			{
				i = (i+1)%max_size;
				printf("%d ", que[i]);
			}while(i != rear);
		}
		
		printf("\n");	
	}		
}

int main()
{
	printf("Input size of dequeue: "); 
	scanf("%d", &max_size);
	que = (int*)malloc(max_size * sizeof(int));
	
	int code;
	do
	{
		printf("\n1. Insert from front\n");
		printf("2. Insert from rear\n");
		printf("3. Delete from front\n");
		printf("4. Delete from rear\n");
		printf("5. Display queue\n");
		printf("6. Exit from queue menu\n");
		scanf("%d", &code);					// input choice here

		int item;
		switch(code)
		{
			case 1:	printf("Input item to enter to queue: "); scanf("%d", &item);
							insert_front(item); break;

			case 2: printf("Input item to enter to queue: "); scanf("%d", &item);
							insert_rear(item); break;
			
			case 3:	delete_front(); break;

			case 4: delete_rear(); break;
			
			case 5: queueDisplay(); break;
			
			case 6: printf("Exiting program on user input\n"); break;
			
			default:printf("Wrong code inputted\n");
		}
	}while(code != 6);

}