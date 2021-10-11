#include <stdio.h>

int main()
{
	int n;
	int divs = 0;
	scanf("%d", &n);
	for(int x = n/2; x > 0; x--)
	{
		if(n%x == 0)
		{
			printf("%d\n", x);
			divs++;
		}
	}
	printf("Divisori: %d\n", divs);
}
