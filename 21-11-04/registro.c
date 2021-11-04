#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_NAME 100

// Creates a new book of size "size", if registry has an existing book destroys
// the old one and replaces it with the new one.
// Returns 0 on failure, non-zero otherwise.
char** new_book(char** registry, int size)
{
	if(size < 1)
	{
		printf("Invalid size\n");
		return NULL;
	}
	if(registry != NULL) free(registry);
	registry = malloc(sizeof(char**) * size);
	if(registry == NULL)
	{
		printf("Memory couldn't be allocated\n");
		return NULL;
	}

	for(int x = 0; x < size; x++)
		registry[x] = NULL;
	return registry;
}

// Books a position if the position is free and returns non-zero,
// otherwise returns 0. Fails and returns 0 if the pos given is less than 0.
// Passing a NULL pointer as a registry results in an undefined behaviour.
int book(char** registry, int pos, char* name)
{
	int name_size;
	if(pos < 0)
	{
		printf("Invalid posizion\n");
		return FALSE;
	}
	if(registry[pos] != NULL)
	{
		printf("Position is already occupied\n");
		return FALSE;
	}

	name_size = strlen(name);
	registry[pos] = malloc(sizeof(char) * (name_size+1));
	strcpy(registry[pos], name);
	return TRUE;
}

// Cancels a booking if the position is not free. Otherwise fails and returns 0.
// If the passed position is less than 0 it fails and reutnrs 0.
// Passing a NULL pointer as registry results in undefined behaviour.
int cancel(char** registry, int pos)
{
	if(pos < 0)
	{
		printf("Invalid position\n");
		return FALSE;
	}
	if(registry[pos] == NULL)
	{
		printf("Position is already empty\n");
		return FALSE;
	}
	free(registry[pos]);
	registry[pos] = NULL;
	return TRUE;
}

// Moves position of the booking if FROM is non-empty and TO is empty,
// otherwise fails and returns 0. If FROM or TO are given as int less than 0
// fails and returns 0.
// On success a non-zero integer is returned.
int move(char** registry, int from, int to)
{
	if(from < 0 || to < 0)
	{
		printf("FROM position or TO position are invalid\n");
		return FALSE;
	}
	if(registry[to] != NULL)
	{
		printf("TO position is already occupied\n");
		return FALSE;
	}
	if(registry[from] == NULL)
	{
		printf("FROM position is empty\n");
		return FALSE;
	}
	registry[to] = registry[from];
	registry[from] = NULL;
	return TRUE;
}

// Passing a NULL pointer as registry results in undefined behaviour.
void print_book(char** registry, int size)
{
	printf("REGISTER[0..%d]\n", size-1);
	for(int x = 0; x < size; x++)
	{
		if(registry[x] != NULL)
			printf("%d --> %s\n", x, registry[x]);
	}
}

void cleanup(char** registry, int size)
{
	for(int x = 0; x < size; x++)
	{
		if(registry[x] != NULL)
			free(registry[x]);
	}
	free(registry);
}

int main()
{
	char** registry = NULL;
	int size = 0;

	char sel;
	int temp;
	int temp2;
	char name[MAX_NAME];

	while((sel = getchar()) != 'f')
	{
		switch(sel)
		{
			case 'b':
				scanf(" %d", &temp);
				registry = new_book(registry, temp);
				if(registry != NULL) size = temp;
				break;
			case '+':
				scanf(" %d %s", &temp, name);
				book(registry, temp, name);
				break;
			case '-':
				scanf(" %d", &temp);
				cancel(registry, temp);
				break;
			case 'm':
				scanf(" %d %d", &temp, &temp2);
				move(registry, temp, temp2);
				break;
			case 'p':
				print_book(registry, size);
		}
	}
	cleanup(registry, size);
}
