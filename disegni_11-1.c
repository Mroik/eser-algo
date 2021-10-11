#include <stdio.h>

int main()
{
	int size;
	scanf("%d", &size);
	for(int x = 0; x < size; x++)
	{
		for(int y = 0; y < size; y++)
		{
			if(x%2 == 0) printf("+ ");
			else printf("O ");
		}
		printf("\n");
	}
}
