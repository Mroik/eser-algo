#include <stdio.h>

int suc_collatz(int n)
{
	if(n == 1)
		return 0;
	if(n%2 == 0)
		return n/2;
	return n*3 + 1;
}

int main()
{
	int x;
	int n;
	printf("Numero: ");
	scanf(" %d", &n);
	printf("%d ", n);
	for(x = 0;; x++)
	{
		n = suc_collatz(n);
		if(n == 0) break;
		printf("%d ", n);
	}
	printf("\nLunghezza: %d", ++x);
}
