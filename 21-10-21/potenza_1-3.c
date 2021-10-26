#include <stdio.h>

int potenza(int b, int e)
{
	if(e == 0)
		return 1;
	return b * potenza(b, e-1)
}
