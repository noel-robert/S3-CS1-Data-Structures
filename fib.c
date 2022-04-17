//Fibonacci by recursion

#include <stdio.h>
#include <stdlib.h>

int n;
int currentTerm = 3;		// 2 terms known
int sum = 0;

int fibonacci(int n1, int n2)
{
	if(currentTerm <= n)
	{
		currentTerm++;
		sum = n1+n2;
		return n2 + fibonacci(n2, n1+n2);
	}

	return 0;
}

int main()
{
  scanf("%d", &n);		// nth term

	if(n == 1 || n == 2)
		printf("%dth term is %d\n", n, n-1);
	else
	{
		fibonacci(0,1);
	  printf("%dth term is %d\n",n , sum);
	}

	return 0;
}