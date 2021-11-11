#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0

int is_number(char c)
{
	if(c >= '0' && c <= '9')
		return TRUE;
	return FALSE;
}

int main()
{
	char token[11];
	int n1;
	int n2;
	for(;;)
	{
		scanf(" %s", token);
		if(is_number(token[0]))
			push(atoi(token));
		else
		{
			if(token[0] == 'p')
			{
				print_stack();
				continue;
			}
			if(is_empty())
			{
				printf("Error: There are no numbers to compute\n");
				return -1;
			}
			n1 = pop();
			if(is_empty())
			{
				printf("Error: There are no numbers to compute\n");
				return -1;
			}
			n2 = pop();

			if(token[0] == '+')
			{
				n1 = n2 + n1;
				push(n1);
			}
			else if(token[0] == '-')
			{
				n1 = n2 - n1;
				push(n1);
			}
			else if(token[0] == '*')
			{
				n1 = n2 * n1;
				push(n1);
			}
			else if(token[0] == '/')
			{
				if(n1 == 0)
				{
					printf("Can't divide by 0\n");
					return -1;
				}
				n1 = n2 / n1;
				push(n1);
			}
			else
			{
				printf("Unknown operator\n");
				return -1;
			}
		}
	}
}
