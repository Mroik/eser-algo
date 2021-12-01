typedef struct {
	char* word;
	int n;
} occorrenza;

typedef struct node_s {
	occorrenza* item;
	struct node_s* left;
	struct node_s* right;
} node;

node* bit_make_node(char*);
void bit_insert(node*, char*);
void bit_preorder(node*);
void bit_inorder(node*);
void bit_postorder(node*);

void bit_orderprint(node*);
void bit_invorderprint(node*);
