// Noel John Robert
// program to implement quickSort
//

#include <stdio.h>
#include <stdlib.h>

int* arr = 0;
int size = 0;

void swap(int *a, int *b)	// swapping two variables a and b
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
	printf("starting sorting \n");
	if(left < right)
	{
		int p = partition(left, right);
		quicksort(left, p-1);
		quicksort(p+1, right);
	}
}

void assign()
{
	printf("Input elements of array: ");
	for(int i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);	
	}
}

void display()
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


// #include <stdio.h>
// #define size 50
// void quick_sort(int a[size],int l ,int r);
// int partion(int a[size],int l,int r);
// void quick_sort(int a[size],int l,int r)
// {
//   int p;
//   if(l<r)
//   {
//     p=partion(a,l,r);
//     printf("%d",p);
//     quick_sort(a,l,p-1);
//     quick_sort(a,p+1,r);  

//   }
// }
// int partion(int a[size],int l, int r) 
// {
//   int i,j,t;
//   int pivot=a[l];
//   i=l;
//   j=r;
//   while(i<j)
//   {
//     while(a[i]<=pivot && i<r)
//     {
//       i++;
//     }
//     while(a[j]>pivot)
//     {
//       j--;
//     }
//     if(i<j)
//     {
//       t=a[i];
//       a[i]=a[j];
//       a[j]=t;
//     }
//   }
//    t=a[l];
//    a[l]=a[j];
//    a[j]=t;
//   return j;
// } 
// int main() 
// {
//   int arr[size];
//   int n,i=0;
//   printf("Enter the number of elements in the array\n");
//   scanf("%d",&n);
//   printf("Enter the elements of the array\n");
//   while(i<n)
//   {
//     scanf("%d",&arr[i]);
//     i++;
//   }
//   arr[n]=99999999;
//   quick_sort(arr,0,n-1);
//   printf("Your Sorted array is\n");
//   for(int i=0;i<n;i++)
//   {
//      printf("\t%d",arr[i]);
//   }

//   return 0;
// }