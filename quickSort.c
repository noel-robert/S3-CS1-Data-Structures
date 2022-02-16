// Noel John Robert
// program to implement quickSort
//

#include <stdio.h>
#include <stdlib.h>

int* arr = 0;
int size = 0;

void swap(int *a, int *b)			// swapping two variables a and b
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int left, int right)
{
	int pivot = arr[left];
	int i = left, j = right;

	while(i < j)
	{
		while(arr[i] <= pivot)
			i++;	

		while(arr[j] > pivot)
			j--;

		if(i < j)
			swap(&arr[i], &arr[j]);				
	}

	swap(&arr[left], &arr[j]);	
	return j;
}

void quicksort(int left, int right)
{
	if(left < right)
	{
		int p = partition(left, right);
		quicksort(left, p-1);
		quicksort(p+1, right);
	}
}

void assign()			// function to take inputs to array
{
	printf("Input elements of array: ");
	for(int i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);	
	}
}

void display()			// function to display sorted array 
{
	printf("Elements of array in sorted order is: \n");
	for(int i=0; i<size; i++)
		printf("%d ", arr[i]);

	printf("\n");	
}

int main()
{
	printf("Input size of array: "); 
	scanf("%d", &size);
	arr = (int*)malloc(size * sizeof(int));

	assign();
	quicksort(0, size-1);
	display();

	return 0;
}