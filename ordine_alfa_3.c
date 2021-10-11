#include <stdio.h>

int main()
{
	char c1, c2;
	scanf("%c %c", &c1, &c2);
	if(c1-c2 < 0)
		printf("%d\n", c2-c1);
	else
		printf("%d\n", c1-c2);
}
