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

node_t* bst_newNode(void *data, long length) {
	node_t *node = (node_t *) malloc(sizeof(node_t));
	node->data = data;
	node->length = length;
	node->one = NULL;
	node->zero = NULL;
	return node;
}

char* bst_add(node_t *node) {
	//
	return NULL;
}

bool bst_delete(char *id) {
	return false;
}

node_t* bst_search(void *data, long length) {
	//
	return NULL;
}

char* bst_hashID(char *id, bit_t val) {
	//
	return id;
}	
