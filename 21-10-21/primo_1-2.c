#include <stdio.h>

#define TRUE 1
#define FALSE 0

int is_primo(int n)
{
	int divs = 0;
	for(int x = x/2; x > 0; x--)
		if(n%x == 0)
			divs++;
	if(divs > 1)
		return FALSE;
	return TRUE;
}
