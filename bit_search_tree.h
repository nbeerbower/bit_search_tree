#define BITS_IN_BYTE 8

typedef struct bit {
    unsigned x:1;
} bit_t;

typedef struct node
{
    void * data;
    struct node_t *zero;
    struct node_t *one;
} node_t;
