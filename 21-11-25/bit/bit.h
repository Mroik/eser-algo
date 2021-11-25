typedef struct bit_node_s {
		Item item;
		struct bit_node_s* left;
		struct bit_node_s* right;
} bit_node;

bit_node bit_new(Item);
void bit_preorder(bit_node);
void bit_inorder(bit_node);
void bit_postorder(bit_node);

// 1.2 Stampa di alberi a sommario
void bit_printsummary(bit_node, int);

// 1.3 Dal vettore all'albero
bit_node bit_arr2tree(Item a[], int size, int i);
