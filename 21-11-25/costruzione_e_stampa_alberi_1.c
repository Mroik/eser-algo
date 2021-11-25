#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct node_s {
		int value;
		struct node_s* left;
		struct node_s* right;
} node;

// Undefined behaviour when a NULL pointer is passed as root
void insert(node* root, int value)
{
		if(value < root->value)
		{
				if(root->left == NULL)
				{
						root->left = malloc(sizeof(node));
						root->left->left = NULL;
						root->left->right = NULL;
						root->left->value = value;
						return;
				}
				insert(root->left, value);
		}
		else if(value > root->value)
		{
				if(root->right == NULL)
				{
						root->right = malloc(sizeof(node));
						root->right->left = NULL;
						root->right->right = NULL;
						root->right->value = value;
						return;
				}
				insert(root->right, value);
		}
}

void preordine(node* root)
{
		printf("%d\n", root->value);
		if(root->left != NULL)
				preordine(root->left);
		if(root->right != NULL)
				preordine(root->right);
}

void inordine(node* root)
{
		if(root->left != NULL)
				inordine(root->left);
		printf("%d\n", root->value);
		if(root->right != NULL)
				inordine(root->right);
}

void postordine(node* root)
{
		if(root->right != NULL)
				postordine(root->right);
		printf("%d\n", root->value);
		if(root->left != NULL)
				postordine(root->left);
}

void cleanup(node* root)
{
		if(root->left != NULL)
		{
				cleanup(root->left);
				free(root->left);
		}
		if(root->right != NULL)
		{
				cleanup(root->right);
				free(root->right);
		}
}

int main()
{
		int values[MAX];
		node root;
		root.left = NULL;
		root.right = NULL;
		srand(time(NULL));

		for(int x = 0; x < MAX; x++)
				values[x] = rand();
		root.value = values[0];

		for(int x = 1; x < MAX; x++)
				insert(&root, values[x]);
		printf("Preordine:\n");
		preordine(&root);
		printf("Inordine:\n");
		inordine(&root);
		printf("Postordine:\n");
		postordine(&root);
		cleanup(&root);
}
