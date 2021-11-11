#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct node_s{
	struct node_s* next;
	int value;
} node;

node* top_node = NULL;

void make_empty(void)
{
	node* current = top_node;
	node* next;
	while(current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	top_node = NULL;
}

int is_empty(void)
{
	if(top_node == NULL)
		return 1;
	return 0;
}

int top(void)
{
	if(top_node == NULL)
	{
		printf("Error: The stack is empty\n");
		return -1;
	}
	return top_node->value;
}

int pop(void)
{
	int to_return;
	node* to_delete;
	if(top_node == NULL)
	{
		printf("Error: The stack is empty\n");
		return -1;
	}
	to_return = top_node->value;
	to_delete = top_node;
	top_node = top_node->next;
	free(to_delete);
	return to_return;
}

void push(int n)
{
	node* new_node;
	new_node = malloc(sizeof(node));
	new_node->value = n;
	new_node->next = top_node;
	top_node = new_node;
}

void print_stack(void)
{
	node* current = top_node;
	while(current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}
