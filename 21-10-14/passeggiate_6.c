#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sometimes doesn't work, need to fix

int main()
{
	srand(time(NULL));
	char a = 'B';
	int posx = 0, posy = 0;
	int choice;
	char table[10][10];

	// Init arr
	for(int x = 0; x < 10; x++) for(int y = 0; y < 10; y++) table[x][y] = '.';
	table[0][0] = 'A';

	do
	{
		if(
			(table[posx-1][posy] != '.' || posx-1 < 0) &&
			(table[posx][posy-1] != '.' || posy-1 < 0) &&
			(table[posx+1][posy] != '.' || posx+1 > 9) &&
			(table[posx][posy+1] != '.' || posy+1 > 9)
		) break;
		choice = rand() % 4;
		if(choice == 0)
		{
			if(posy + 1 > 9 || table[posx][posy+1] != '.') continue;
			posy++;
			table[posx][posy] = a;
			a++;
		}
		else if(choice == 1)
		{
			if(posx + 1 > 9 || table[posx+1][posy] != '.') continue;
			posx++;
			table[posx][posy] = a;
			a++;
		}
		else if(choice == 2)
		{
			if(posy - 1 < 0 || table[posx][posy-1] != '.') continue;
			posy--;
			table[posx][posy] = a;
			a++;
		}
		else if(choice == 0)
		{
			if(posx - 1 < 0 || table[posx-1][posy] != '.') continue;
			posx--;
			table[posx][posy] = a;
			a++;
		}
	}while(a != 'Z');
	
	for(int x = 0; x < 10; x++)
	{
		for(int y = 0; y < 10; y++) printf("%c ", table[x][y]);
		printf("\n");
	}
}
