#include <stdbool.h>

#include "bit.h"

typedef struct node {
	char * id;
    void * data;
    long length;
    struct node_t *zero;
    struct node_t *one;
    struct node_t *parent;
} node_t;

// initialize tree
node_t* bst_init();
// new node
node_t* bst_newNode(void *data, long length);
// destory node (dealloc all assoc. memory)
void bst_destroyNode(node_t *node, bool recursive);
// add to tree (returns id)
char* bst_add(node_t* root, node_t *node);
// delete from tree (returns successful)
bool bst_delete(node_t* root, char *id);
// get node from tree by id
node_t* bst_get(node_t* root, char* id);
// search tree (returns array of related root node and children)
node_t* bst_search(node_t* root, void *data, long length);
// serialize tree (saves tree to file)
// deserialize tree (loads tree from file)

// add bit to hash
char* bst_hashID(char *id, byte_t val, uint8_t i);
