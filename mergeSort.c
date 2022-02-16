// Noel John Robert
// program to implement mergeSort
//

#include <stdio.h>
#include <stdlib.h>

int* arr = 0;
int size = 0;

void merge(int left, int mid, int right)
{
	int i, j, k;
	int s1 = mid - left + 1;
	int s2 = right - mid;

	int *L = (int*)malloc(s1 * sizeof(int)); 	// left array
	int *R = (int*)malloc(s2 * sizeof(int));	// right array

	for(i=0; i<s1; i++)					// copying elements to left array
		L[i] = arr[left + i];

	for(j=0; j<s2; j++)					// copying elements to right array	
		R[j] = arr[mid + 1 + j];

	i=0; j=0; k=left;
	while(i<s1 && j<s2)					// comparing elements and putting them back into main array
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i]; i++;
		}
		else
		{
			arr[k] = R[j]; j++;
		}
		k++;
	}
	
	while(i < s1)				// if there are elements still present in left array
	{
		arr[k] = L[i];
		i++; k++;
	}
	while(j < s2)				// if there are elements still present in right array
	{
		arr[k] = R[j];
		j++; k++;
	}
}

void mergesort(int left, int right)
{
	if(left < right)
	{
		int mid = left + (right - left) / 2;
		mergesort(left, mid);
		mergesort(mid+1, right);
		merge(left, mid, right);
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
	mergesort(0, size-1);
	display();

	return 0;
}