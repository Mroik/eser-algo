#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main()
{
	// Si assume che tutti i caratteri letti siano parte dell'alfabeto e minuscoli
	int alfa[26];
	char car;
	int anam = TRUE;
	
	// Init array
	for(int x = 0; x < 26; x++) alfa[x] = 0;

	do
	{
		car = getchar();
		alfa[car-'a']++;
	}while(car != '\n');
	do
	{
		car = getchar();
		alfa[car-'a']--;
	}while(car != '\n' && car != EOF);

	for(int x = 0; x < 26; x++)
	{
		if(alfa[x] != 0)
		{
			anam = FALSE;
			break;
		}
	}

	if(anam) printf("Anagramma\n");
	else printf("Non anagramma\n");
}
