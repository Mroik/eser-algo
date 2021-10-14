#include <stdio.h>

unsigned int giorni_m(unsigned int m)
{
	switch(m)
	{
		case 11:
		case 4:
		case 6:
		case 9:
			return 30;
		case 2:
			return 28;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		default:
			return 0;
	}
}

int main()
{
	unsigned int month;
	unsigned int day;
	unsigned int tot;

	scanf("%d %d", &month, &day);
	if(day < 1 || day > 7)
	{
		printf("Fuck off!!!");
		return 1;
	}
	day--;
	tot = giorni_m(month);
	printf("L\tM\tM\tG\tV\tS\tD\n");
	for(int x = 0; x < day; x++) printf("\t");
	for(int x = 1; x <= tot; x++)
	{
		printf("%d\t", x);
		day = ++day % 7;
		if(day == 0) printf("\n");
	}
	printf("\n");
}
