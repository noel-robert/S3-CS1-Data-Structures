#include <stdio.h>

int search(int start, int end, int arr[], int ele)
{
  if(end < start)
    return -1;

  int mid = (start + end)/2;
  if(arr[mid] == ele)
    return mid;
  else if(ele > arr[mid])
    search(mid+1, end, arr, ele); 
  else if(ele < arr[mid])
    search(start, mid-1, arr, ele);  
   
}

int main()
{
  int n;
  printf("\nInput number of elements: ");
  scanf("%d", &n);
  
  int arr[n];
  printf("\nInput elements below:\n");
  for(int i=0; i<n; i++)
    scanf("%d", &arr[i]);

  int element;
  printf("\nInput element to be searched: ");
  scanf("%d", &element);
  
  int res = search(0, n-1, arr, element);  
  if(res == -1)
    printf("\n%d is not present in the array\n\n", element);
  else
    printf("\nElement found at position %d\n\n", res); 

  return 0;  
}