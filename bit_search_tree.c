#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bit_search_tree.h"
#include "bit.h"

node_t* bst_init() {
	node_t *root = malloc(sizeof(node_t));
	root->id = malloc(sizeof(bst_id));
	// TODO: root node meta data
	root->data = NULL;
	root->length = 0;
	root->one = NULL;
	root->zero = NULL;
	return root;
}

node_t* bst_newNode(void *data, long length) {
	node_t *node = malloc(sizeof(node_t));
	node->id = malloc(sizeof(bst_id));
	node->id->data = NULL;
	node->id->length = -1;
	node->data = data;
	node->length = length;
	node->one = NULL;
	node->zero = NULL;
	return node;
}

void bst_destroyNode(node_t *node, bool recursive) {
	if (node == NULL) return;

	free(node->id->data);
	free(node->id);
	node->id = NULL;
	free(node->data);
	node->data = NULL;
	// TODO: finish this

	if (recursive) {
		bst_destroyNode(node->zero, true);
		bst_destroyNode(node->one, true);
	}

	//free(node) ??
}

char* bst_add(node_t* root, node_t *node) {
	if (root == NULL) {
		return NULL;
	}

	int level = 0;
	node_t *cur = root;
	node_t *next = NULL;
	byte_t curByte;
	uint8_t curBit;
	do {
		if (level != 0) cur = next;
		curByte = (byte_t)((byte_t *) node->data)[level/8];
		curBit = bit_at(curByte, level % 8);
		node->id = bst_hashID(node->id, level, level % 8);
		next = curBit ? cur->one : cur->zero;
		level++;
	} while (next != NULL && node->length != level/8);

	if (next != NULL) {
		// data is identical (at least it should be if it exhausted all bits)
		// TODO: increment quantity counter?
		return next->id;
	} else {
		node->parent = cur;
		if (curBit) {
			cur->one = node;
		} else {
			cur->zero = node;
		}
		return node->id;
	}
}

bool bst_delete(node_t* root, bst_id *id) {
	return false;
}
node_t* bst_get(node_t* root, bst_id *id) {
	//
	return NULL;
}

node_t* bst_search(node_t* root, void *data, long length) {
	//
	return NULL;
}

bst_id* bst_hashID(bst_id *id, long i, uint8_t val) {
	if (id == NULL || (id->length != -1 && i > (id->length * 8)+1)) {
		printf("invalid arguments provided to hashID... exiting\n");
		return NULL;
	}

	long n = i / 8;
	uint8_t x = i % 8;

	printf("i: %li n: %li, x: %u\n", i, n, x);
	fflush(stdout);

	if (x == 0) {
		printf("reallocating space for id\n");
		// increase size if i spills over current allocated memory
		id->data = realloc(id->data, n);
		(id->data)[n] = 59;
		printf("%c\n", (id->data)[n]);
		printf("%u\n", 'a');
		printf("%u\n", ';');
		if (i != 0) n++;
	}

	// set the bit
	(id->data)[n] = val ? ((id->data)[n] | (1 << x)) : ((id->data)[n] & ~(1 << x));
	printf("%u\n", val);
	printf("%c\n", (id->data)[n]);

	// update length of id
	id->length = n;

	return id;
}

char* bst_id2str(bst_id *id) {
	char* idstr = malloc(sizeof(byte_t)*id->length + 1);
	strncpy(idstr, id->data, id->length);
	return idstr;
}
