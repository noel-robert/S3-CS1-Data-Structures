// Noel John Robert
// B20CS1147
// program to implement Binary Search Tree 
							// deletion not done

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
		printf("%d ", ptr->info);
		inorder_traversal(ptr->RC);
	}	
	else
		return;
}

void preorder_traversal(struct node *ptr)
{
	if(ptr != NULL)
	{
		printf("%d ", ptr->info);
		preorder_traversal(ptr->LC);
		preorder_traversal(ptr->RC);
	}	
	else
		return;
}

void postorder_traversal(struct node *ptr)
{
	if(ptr != NULL)
	{
		postorder_traversal(ptr->LC);
		postorder_traversal(ptr->RC);
		printf("%d ", ptr->info);
	}	
	else
		return;
}

bool search(int item)
{
	struct node* ptr = root;
	
	while(ptr!=NULL && ptr->info!=item)
	{
		if(ptr->info < item)
			ptr = ptr->RC;
		else
			ptr = ptr->LC;
	}
	
	if(ptr == NULL)
		return false;
	else if(ptr->info == item)
		return true;		
}

void insert(int item)
{
	// create and initialize new node	
	struct node* temp = (struct node*) malloc (sizeof(struct node)); 
	temp->LC = NULL;
	temp->info = item;
	temp->RC = NULL;
	
	if(root == NULL)	// empty tree
	{
		root = temp;
		return;
	}

	if(search(item))   // item already present
	{
		printf("Item already present\n");
		return;
	}  
	
	struct node* ptr = root;
	struct node* parent = NULL;
	while(ptr!=NULL)
	{
		parent = ptr;
		if(ptr->info > item)
			ptr = ptr->LC;
		else
			ptr = ptr->RC;
	}
	
	if(parent->info > item)
		parent->LC = temp;
	else
		parent->RC = temp;
}

//struct node* searchParent(int item)
//{
//	struct node* ptr = root;
//	struct node* parent = NULL;
//	
//	while(ptr!=NULL && ptr->info!=item)
//	{
//		parent = ptr;
//		if(ptr->info < item)
//			ptr = ptr->RC;
//		else
//			ptr = ptr->LC;
//	}	
//	return parent;
//}

void deletion(int item)
{
	
}

int height(struct node *ptr)
{
	if(ptr == NULL)
		return -1;
	else
	{
		int l = height(ptr->LC);
		int r = height(ptr->RC);

		if(l > r)
			return l;		// or l+1
		else
			return r;		// or r+1
	}	
}

int main()
{
	int code;
	do
	{
		printf("\n1. Insert node\n");
		printf("2. Search for element\n");
		printf("3. Delete node\n");
		printf("4. Height of tree\n");
		printf("5. Inorder traversal\n");
		printf("6. Exit program\n");
		scanf("%d", &code);		// input choice here

		int num;
		switch(code)
		{
			case 1: printf("Input number to insert: "); scanf("%d", &num);
				 			insert(num); break;
			
			case 2: printf("Input number to search: "); scanf("%d", &num);
				 			if(search(num))
								printf("Item is present\n");
							else
								printf("Item not present\n");
							break;
				 
			case 3: printf("Input number to delete: "); scanf("%d", &num);
				 			deletion(num); break;
				 
			case 4: height(root); break;

			case 5: inorder_traversal(root);
							preorder_traversal(root);
							postorder_traversal(root);
							printf("\n"); break;
			
			case 6: printf("Exiting program on user input\n"); break;
			
			default:printf("Wrong code inputted\n");
		}
	}while(code != 6);

	return 0;
}

/*
OUTPUT

*/