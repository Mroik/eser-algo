#include <stdio.h>

int hanoi(int n, int from, int to, int temp)
{
	int m;
	if(n == 1)
	{
		printf("%d -> %d\n", from, to);
		return 1;
	}
	m = 0;
	m += hanoi(n-1, from, temp, to);
	m += hanoi(1, from, to, temp);
	m += hanoi(n-1, temp, to, from);
	return m;
}

int main()
{
	unsigned int n;
	scanf(" %d", &n);
	n = hanoi(n, 0, 1, 2);
	printf("Mosse: %d\n", n);
}
