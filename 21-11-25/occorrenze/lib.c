#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

#define MAX_WORD 30

// word size should be checked before calling this function
node* bit_make_node(char* word)
{
	node* n = malloc(sizeof(node));
	n->item = malloc(sizeof(occorrenza));
	n->item->word = malloc(sizeof(char) * MAX_WORD);
	strcpy(n->item->word, word);
	n->item->n = 1;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void bit_insert(node* root, char* word)
{
	int equal = strcmp(word, root->item->word);
	if(equal < 0)
	{
		if(root->left == NULL)
			root->left = bit_make_node(word);
		else
			bit_insert(root->left, word);
		return;
	}
	else if(equal > 0)
	{
		if(root->right == NULL)
			root->right = bit_make_node(word);
		else
			bit_insert(root->right, word);
		return;
	}
	else
		root->item->n++;
}

void bit_preorder(node* root)
{
	printf("%s\n", root->item->word);
	if(root->left != NULL)
		bit_preorder(root->left);
	if(root->right != NULL)
		bit_preorder(root->right);
}

void bit_inorder(node* root)
{
	if(root->left != NULL)
		bit_inorder(root->left);
	printf("%s\n", root->item->word);
	if(root->right != NULL)
		bit_inorder(root->right);
}

void bit_postorder(node* root)
{
	if(root->left != NULL)
		bit_postorder(root->left);
	if(root->right != NULL)
		bit_postorder(root->right);
	printf("%s\n", root->item->word);
}

void bit_orderprint(node* root)
{
	if(root->left != NULL)
		bit_orderprint(root->left);
	printf("%s %d\n", root->item->word, root->item->n);
	if(root->right != NULL)
		bit_orderprint(root->right);
}

void bit_invorderprint(node* root)
{
	if(root->right != NULL)
		bit_invorderprint(root->right);
	printf("%s %d\n", root->item->word, root->item->n);
	if(root->left != NULL)
		bit_invorderprint(root->left);
}
