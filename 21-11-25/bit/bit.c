#include <stdio.h>

bit_node bit_new(Item item)
{
		bit_node* ris = malloc(sizeof(bit_node));
		ris->item = item;
		ris->left = NULL;
		ris->right = NULL;
		return *ris;
}

void bit_preorder(bit_node root)
{
		printf("%d\n", root.value);
		if(root.left != NULL)
				bit_preorder(*(root.left));
		if(root.right != NULL)
				bit_preorder(*(root.right));
}

void bit_inorder(bit_node root)
{
		if(root.left != NULL)
				bit_preorder(*(root.left));
		printf("%d\n", root.value);
		if(root.right != NULL)
				bit_preorder(*(root.right));
}

void bit_postorder(bit_node root)
{
		if(root.right != NULL)
				bit_preorder(*(root.right));
		printf("%d\n", root.value);
		if(root.left != NULL)
				bit_preorder(*(root.left));
}

void bit_printsummary(bit_node root, int spaces)
{
		for(int x = 0; x < spaces; x++)
				printf("\t");
		printf("%d\n", root.item);
		bit_printsummary(*(root.left), spaces+1);
		bit_printsummary(*(root.right), spaces+1);
}

bit_node bit_arr2tree(Item a[], int size, int i)
{
		bit_node ris = bit_new(a[i]);
		bit_node* temp;

		if(i*2+1 < size)
		{
				temp = malloc(sizeof(bit_node));
				*temp = bit_arr2tree(a, size, i*2+1);
				ris.left = temp;
		}
		if(i*2+2 < size)
		{
				temp = malloc(sizeof(bit_node));
				*temp = bit_arr2tree(a, size, i*2+2);
				ris.right = temp;
		}
		return ris;
}
