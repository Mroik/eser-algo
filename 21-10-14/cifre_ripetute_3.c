#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
	int n;
	char buffer[100];
	int rip[10];
	int scritto = FALSE;

	// Init array
	for(int x = 0; x < 10; x++) rip[x] = 0;

	scanf("%d", &n);
	sprintf(buffer,"%d", n);

	for(int x = 0;; x++)
	{
		if(buffer[x] == 0) break;
		rip[buffer[x]-48]++;
	}

	for(int x = 0; x < 10; x++)
	{
		if(rip[x] > 1)
		{
			if(!scritto) printf("Cifre ripetute: ");
			if(scritto) printf(", ");
			printf("%d", x);
			scritto = TRUE;
		}
	}
	if(!scritto) printf("Non ci sono cifre ripetute");
	printf("\n");
}
