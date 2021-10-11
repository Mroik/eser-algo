#include <stdio.h>

int main()
{
	unsigned int size;
	scanf("%d", &size);
	for(int x = 0; x < size; x++)
	{
		for(int y = 0; y < size; y++)
		{
			if(y%2 == x%2) printf("O ");
			else printf("+ ");
		}
		printf("\n");
	}
}
