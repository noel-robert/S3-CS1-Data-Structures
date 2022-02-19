// Noel John Robert
// program to implement hashing
// hash function - division method, collision resolution - linear probing

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int table_size;			// size of table
int D;
int *hash_table;


bool isPrime(int n)						// to check if number is prime
{
	int i = 2;
	while(i <= n/2)
	{
		if(n%i == 0)
			return false;
		i++;	
	}
	return true;
}

int closestPrime(int n)				// to find prime number less than table_size
{
	for(int i=n; i>=2; i--)
	{
		if(isPrime(i))
			return i;
	}
}

int hash_function(int k)			// division method
{
	return(k%D);
}

int collision_resolution(int num, int key)		// uses linear probing
{
	int index = key;
	
	do
	{
		if(hash_table[index] == 0)		// location is empty
			return index;

		if(index == table_size-1)			// not empty, so move to next
			index = 0;
		else
			index++;
	}while(index != key);

}

void insert(int num)
{
	int key = hash_function(num);			// finding key

	key = collision_resolution(num, key);		// collision resolution using linear probing
	hash_table[key] = num;
	
	return;
}

void search(int num)
{
	int key = hash_function(num);					// finding key

	int index = key;
	do
	{
		if(hash_table[index] == num)		
		{
			printf("Value is present in table\n");
			return;
		}

		if(index == table_size-1)	
		{
			index = 0;
		}
		else
		{
			index++;
		}	
	}while(index != key);

	printf("Value is not present in table\n");
	return;
}

bool hasSpace()		// checks if there are empty spaces to input more values
{
	for(int i=0; i<table_size; i++)
		if(hash_table[i] == 0)
			return true;

	return false;		
}

void showTable()			// for checking, not needed in final code
{
	for(int i=0; i<table_size; i++)
	{
		printf("%d ", hash_table[i]);
	}
	printf("\n");
}

int main()
{
	printf("Input table size: ");
	scanf("%d", &table_size);

	D = closestPrime(table_size);
	
	hash_table = (int*) malloc(table_size * sizeof(int));
	
	int code;
	do
	{
		printf("1. Insert\n");
		printf("2. Search\n");
		printf("3. Exit\n");
		printf("Input choice ");
		scanf("%d", &code);

		int num;
		switch(code)
		{
			case 1: if(hasSpace())
							{
								printf("Input number to insert ");		// do not take 0 as input
								scanf("%d", &num); 
								insert(num);
							} 
							else
							{
								printf("Table is full, cannot insert anymore\n");	
							}
							break;

			case 2:	printf("Input number to search ");
							scanf("%d", &num); 
							search(num); break;

			case 3: printf("Exiting program on user input\n"); 
							break;

			default: printf("Wrong code inputted");
		}
	}while(code != 3);

	// showTable();					// for checking, not in final code
	return 0;
}