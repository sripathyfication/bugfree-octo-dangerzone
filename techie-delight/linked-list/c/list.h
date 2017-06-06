/*
 * A generic C linked list implementation, that can hold different types
 * of data.
 *
 */

typedef struct list_node {
    void *data; // pointer to a generic void data pointer
    struct node *next;
    /* if needed previous */
    struct node *previous;
} list_node_t;


/* supported operations on the linked list */

