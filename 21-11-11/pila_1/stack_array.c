#include "stack.h"
#include <stdio.h>

#define STACK_MAX 100

int stack[STACK_MAX];
int stack_size = 0;

void make_empty(void)
{
	stack_size = 0;
}

int is_empty(void)
{
	if(stack_size == 0)
		return 1;
	return 0;
}

int top(void)
{
	if(stack_size == 0)
	{
		printf("Error: The stack is empty\n");
		return -1;
	}
	return stack[stack_size-1];
}

int pop(void)
{
	int to_return;
	if(stack_size == 0)
	{
		printf("Error: The stack is empty\n");
		return -1;
	}
	return stack[--stack_size];
}

void push(int n)
{
	if(stack_size == STACK_MAX)
	{
		printf("Error: The stack is full\n");
		return;
	}
	stack[stack_size] = n;
	stack_size++;
}

void print_stack(void)
{
	for(int x = stack_size-1; x >= 0; x--)
		printf("%d\n", stack[x]);
}
