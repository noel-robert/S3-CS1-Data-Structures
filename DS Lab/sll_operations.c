// Noel John Robert
// Singly Linked List operations
// 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int info;
	struct Node *link;
} *head = NULL;

void insertionAt(int item, int pos)
{
	struct Node *temp = (struct Node*) malloc(sizeof(struct Node));	// allocate memory for new node
	temp->info = item;
	temp->link = NULL;

	if(pos == 1)			// item at beginning of SLL
	{
		temp->link = head;
		head = temp;
		return;
	}

	struct Node *ptr = head;
	int i = 1;
	
	while(i < pos-1)				// traversing to the position
	{
		ptr = ptr->link;
		i++;
		
		if(ptr == NULL)
		{
			printf("Node cannot be inserted as it is out of bounds. Try a lower index\n");
	   	return;
		}
	}

	temp->link = ptr->link;	
	ptr->link = temp;
	
	return;
}

void deletion(int item)
{
	if(head->info == item)	// deleting first element
	{
		head = head->link;
		return;
	}

	struct Node *ptr = head;
	struct Node *prev = NULL;		// to store address of previous node

	while(ptr!=NULL && ptr->info!=item)	// traversing through list
	{
		prev = ptr;
		ptr = ptr->link;
	}

	if(ptr == NULL)			// element is not present, so reaches end of SLL
	{
		printf("Element not found\n");
		return;
	}

	prev->link = ptr->link;
	// printf("Node containing %d removed from SLL\n", item);
	free(ptr);
	return;
}

void display()
{
	struct Node *ptr = head;

	if(head == NULL)
	{
		printf("Empty List\n");
		return;
	}

	printf("Linked list is: ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->info);
		ptr = ptr->link;
	}
	printf("\n");
}

int main()
{
	int n;
	printf("How many elements do you want to initially input: ");
  scanf("%d", &n);
	
	if(n != 0)
	{
		int d;
		printf("Input %d elements: ", n);		// initially entering a few elements
		for(int i=0; i<n; i++)
		{
			scanf("%d", &d);
			insertionAt(d, i+1);
		}
		printf("\n");
	}

	int code;
	do
	{
		printf("1. Insert element\n");
		printf("2. Delete element\n");
		printf("3. Display array\n");
		printf("4. Exit program\n");
		scanf("%d", &code);							// input choice here

		int item, pos;
		switch(code)
		{
			case 1 : 	printf("Input item to be inserted: "); scanf("%d", &item);
								printf("Position to insert item: "); scanf("%d", &pos);
								insertionAt(item, pos); break;

			case 2 :	printf("Input item to be deleted: ");	scanf("%d", &item);	
								deletion(item); break;								

			case 3 :	display(); break;

			case 4 :	printf("Exiting program on user input\n"); break;			
							
			default :	printf("Wrong choice entered\n");									
		}
	}while(code != 4);

	return 0;
}