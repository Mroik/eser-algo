#include <stdio.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

char perfetto(int a)
{
	char found = FALSE;
	for(int x = 1; x < a/2; x++)
	{
		if(x*x == a)
		{
			found = TRUE;
			break;
		}
	}
	return found;
}

int main()
{
	int done = 0;
	for(int x = 0; done < MAX; x++)
	{
		if(perfetto(x))
		{
			printf("%d\n", x);
			done++;
		}
	}
}
