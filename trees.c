// Noel John Robert
// B20CS1147
// program to implement binary search tree operations


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	struct node* LC;	// left child
	int info;
	struct node* RC;	// right child
} *root = NULL;

void inorder_traversal(struct node *ptr)
{
	if(ptr != NULL)
	{
		inorder_traversal(ptr->LC);
		printf("%d", ptr->info);
		inorder_traversal(ptr->RC);
	}	
	else
		return;
}

void insert(int item)
{
	
}

struct node* searchParent(int item)
{
	struct node* ptr = root;
	struct node* parent = NULL;
	
	while(ptr!=NULL && ptr->info!=item)
	{
		parent = ptr;
		if(ptr->info < item)
			ptr = ptr->RC;
		else
			ptr = ptr->LC;
	}	
	return parent;
}

boolean search(int item)
{
	struct node* parent = searchParent(item);

	if(parent == NULL)
		return false;
	else if((parent->LC)->info == item || (parent->RC)->info == item)
		return true;
	else
		return false;
}

void height()
{
	
}

int main()
{
	int code;
	do
	{
		printf("\n1. Insert node\n");
		printf("2. Search\n");
		printf("3. Height\n");
		printf("4. Exit program\n");
		scanf("%d", &code);							// input choice here

		int num;
		switch(code)
		{
			case 1:	printf("Input number to insert: "); scanf("%d", &num);
							insert(num); break;
			
			case 2:	printf("Input number to search: "); scanf("%d", &num);
							search(num); break;
			
			case 3: height(); break;
			
			case 4: printf("Exiting program on user input\n"); break;
			
			default:printf("Wrong code inputted\n");
		}
	}while(code != 4);
	inorder_traversal(root);
	
	return 0;
}