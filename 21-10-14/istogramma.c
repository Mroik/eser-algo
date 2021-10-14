#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char car;
	int alfa[26];

	// Init array
	for(int x = 0; x < 26; x++) alfa[x] = 0;

	do
	{
		car = getchar();
		if(isalpha(car))
		{
			if(car > 96) alfa[car-32-65]++;
			else alfa[car-65]++;
		}
			
	}while(car != '.');
	for(int x = 0; x < 26; x++)
	{
		if(alfa[x] == 0) continue;
		printf("%c ", x+65);
		for(int y = alfa[x]; y > 0; y--) printf("*");
		printf("\n");
	}
}
