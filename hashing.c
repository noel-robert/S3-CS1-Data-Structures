// Noel John Robert
// program to implement hashing
// hash function - division method, collision resolution - linear probing

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define def_val -2147483647			// default value 

int *hash_table;				// table
int table_size;					// size of table
int D;


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

int collision_resolution(int key)		// uses linear probing
{
	int index = key;
	
	do
	{
		if(hash_table[index] == def_val)		// current location is empty
			return index;

		if(index == table_size-1)						// updating index as element already present
			index = 0;
		else
			index++;
	}while(index != key);

}

void insert(int num)
{
	int key = hash_function(num);				// finding key

	key = collision_resolution(key);		// collision resolution using linear probing
	hash_table[key] = num;
	
	return;
}

void search(int num)
{
	int key = hash_function(num);					// finding key

	int index = key;
	do
	{
		if(hash_table[index] == num)		// searched number is at that position
		{
			printf("Value is present in table\n");
			return;
		}

		if(hash_table[index] == def_val)		// searched number is not at position, and position is empty
		{
			printf("Value is not present in table\n");
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
		if(hash_table[i] == def_val)
			return true;

	return false;		
}

void assign_values()			// assign default value to all positions in table 
{
	for(int i=0; i<table_size; i++)
	{
		hash_table[i] = def_val;
	}
}

void showTable()					// display values in table
{
	for(int i=0; i<table_size; i++)
	{
		if(hash_table[i] == def_val)
		{
			printf(" _ ");
			continue;
		}
		else
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
	assign_values();									// assign default values to array
	
	int code;
	do
	{
		printf("\n1. Insert\n");
		printf("2. Search\n");
		printf("3. Exit\n");
		printf("Input choice ");
		scanf("%d", &code);

		int num;
		switch(code)
		{
			case 0: showTable(); break;

			case 1: if(hasSpace())
							{
								printf("Input number to insert ");
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

	return 0;
}