#include <stdio.h>
#include "stack.h"

int main()
{
	int temp;
	char c;
	do
	{
		scanf(" %c", &c);
		switch(c)
		{
			case 'a':
				make_empty();
				break;
			case 'b':
				printf("%d\n", is_empty());
				break;
			case 'c':
				printf("%d\n", top());
				break;
			case 'd':
				printf("%d\n", pop());
				break;
			case 'e':
				scanf(" %d", &temp);
				push(temp);
				break;
			case 'f':
				print_stack();
				break;
			case 'z':
				break;
			default:
				printf("Scelta non valida\n");
		}
	}while(c != 'z');
}
