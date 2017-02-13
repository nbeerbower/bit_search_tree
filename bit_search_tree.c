#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bit_search_tree.h"

node_t* bst_init() {
	node_t *root = (node_t *) malloc(sizeof(node_t));
	root->data = NULL;
	root->length = 0;
	root->one = NULL;
	root->zero = NULL;
	return root;
}
