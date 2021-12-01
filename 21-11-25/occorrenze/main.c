#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define MAX_WORD 30
#define TRUE 1
#define FALSE 0

int main()
{
	char* buf = NULL;
	char* word;
	int size = MAX_WORD;
	node* root;

	getline(&buf, &size, stdin);
	word = strtok(buf, " ");
	root = bit_make_node(word);
	while((word = strtok(NULL, " ")) != NULL)
		bit_insert(root, word);
	bit_orderprint(root);
}
