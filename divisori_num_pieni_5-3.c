#include <stdio.h>

#define TRUE 1
#define FALSE 0

int primo(int n)
{
	int divs = 0;
	for(int x = n/2; x > 0; x--)
	{
		if(n%x == 0)
			divs++;
	}

	if(divs > 1)
		return FALSE;
	else
		return TRUE;
}

int main()
{
	int n;
	int using;
	scanf("%d", &n);
	using = n/2;
	while(n > 1 && using > 0)
	{
		if(primo(using) == TRUE && n%using == 0)
		{
			printf("%d\n", using);
			n /= using;
		}
		else
			using--;
	}
}
