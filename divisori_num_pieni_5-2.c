#include <stdio.h>

int main()
{
	int n, x;
	int divs = 0;
	scanf("%d", &n);

	// Versione for
	//for(int x = n/2; x > 0; x--)
	//{
	//	if(n%x == 0)
	//		divs++;
	//}
	
	// Versione while
	x = n/2;
	while(x > 0)
	{
		if(n%x == 0)
			divs++;
		x--;
	}
	// Comune
	if(divs > 1)
		printf("Non primo!\n");
	else
		printf("Primo!\n");
}
