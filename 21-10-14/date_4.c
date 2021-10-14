#include <stdio.h>

typedef struct{
	int d;
	int m;
	int y;
} date;

int main()
{
	// Assumo che gli anni bisestili non esistano
	int x;
	date date_a[100];
	date check;
	for(x = 0; x < 100; x++)
	{
		scanf("%d/%d/%d", &(date_a[x].d), &(date_a[x].m), &(date_a[x].y));
		if(date_a[x].d == 0 && date_a[x].m == 0 && date_a[x].y == 0) break;
	}

	scanf("%d/%d/%d", &(check.d), &(check.m), &(check.y));

	for(int y = 0; y < x; y++)
	{
		if(date_a[y].y < check.y) printf("%02d/%02d/%02d\n", date_a[y].d, date_a[y].m, date_a[y].y);
		else if(date_a[y].y == check.y)
		{
			if(date_a[y].m < check.m) printf("%02d/%02d/%02d\n", date_a[y].d, date_a[y].m, date_a[y].y);
			else if(date_a[y].m == check.m)
				if(date_a[y].d < check.d) printf("%02d/%02d/%02d\n", date_a[y].d, date_a[y].m, date_a[y].y);

		}
	}
}
