#include <stdbool.h>

typedef struct node
{
	char * id;
    void * data;
    long length;
    struct node_t *zero;
    struct node_t *one;
} node_t;

// initialize tree
node_t* bst_init();
// new node
node_t* bst_newNode(void *data, long length);
// add to tree (returns id)
char* bst_add(node_t *);
// delete from tree (returns successful)
bool bst_delete(char *id);
// search tree (returns array of related root node and children)
node_t* bst_search(void *data, long length);
// serialize tree (saves tree to file)
// deserialize tree (loads tree from file)
