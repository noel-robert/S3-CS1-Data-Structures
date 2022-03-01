// Noel John Robert
// B20CS1147
// program to implement Binary Search Tree 


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

struct node* search(int item)		// returns position where node is found
{
	struct node* ptr = root;
	
	while(ptr!=NULL && ptr->info!=item)
	{
		if(ptr->info < item)
			ptr = ptr->RC;
		else
			ptr = ptr->LC;
	}
	
	return ptr;	
}

void insert(int item)
{
	// create and initialize new node	
	struct node* temp = (struct node*) malloc (sizeof(struct node)); 
	temp->LC = NULL;
	temp->info = item;
	temp->RC = NULL;
	
	if(root == NULL)	// tree is empty, so new node is root of tree
	{
		root = temp;
		return;
	}

	if(search(item) != NULL)   // search returns NULL if element not present   
	{
		printf("Cannot insert same item again\n");
		return;
	}  
	
	struct node* ptr = root;
	struct node* parent = NULL;
	while(ptr != NULL)
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

struct node* inorder_successor(struct node* ptr)
{
	ptr = ptr->RC;				// go to right sub-tree of ptr
	
	while(ptr->LC != NULL)	// finding smallest element in right-subtree of ptr
		ptr = ptr->LC;

	return ptr;
}

void deletion(int item)															
{
	struct node* ptr = NULL;
	struct node *z, *y, *x, *parent;
	
	z = search(item);
	
	if(z == NULL)			// item not present, so cannot delete
	{
		printf("Element not present\n");
		return;
	}
		
	if(z->LC == NULL || z->RC == NULL)
		y = z;
	else
		y = inorder_successor(z);
		
	if(y->LC != NULL)
		x = y->LC;
	else
		x = y->RC;

	parent = searchParent(y->info);

	if(parent == NULL)
	{
		root = x;
		free(y);
		return;
	}

	if(parent->LC == y)
		parent->LC = x;
	else
		parent->RC = x;

	if(y != z)
		z->info = y->info;

	free(y);
	return;			
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
			return l+1;		// or l ????
		else
			return r+1;		// or r ????
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
		printf("5. Traversal\n");
		printf("6. Exit program\n");
		scanf("%d", &code);		// input choice here

		int num;
		switch(code)
		{
			case 1: printf("Input number to insert: "); scanf("%d", &num);
				 			insert(num); break;
			
			case 2: printf("Input number to search: "); scanf("%d", &num);
				 			struct node* ptr = search(num);
							if(ptr!=NULL && ptr->info==num)
							{
								printf("Item is present\n");
								break;
							}	
	       			printf("Item not present\n");
							break;
				 
			case 3: printf("Input number to delete: "); scanf("%d", &num);
				 			deletion(num); break;
				 
			case 4: printf("Height of tree %d\n", height(root)); break;

			case 5: printf("Inorder sequence: "); inorder_traversal(root); printf("\n");
							printf("Preorder sequence: "); preorder_traversal(root); printf("\n");
							printf("Postorder sequence: "); postorder_traversal(root); printf("\n");
							break;
			
			case 6: printf("Exiting program on user input\n"); break;
			
			default:printf("Wrong code inputted\n");
		}
	}while(code != 6);

	return 0;
}

/*
OUTPUT

*/