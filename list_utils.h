#ifndef LIST_UTILS_H
#define LIST_UTILS_H

struct node {
    int value;
    struct node *next;
};

struct node *insert_node(struct node *, int);

void print_list(const struct node *);

struct node *delete_by_value(struct node *, int);

struct node *populate_list(void);

size_t num_nodes(const struct node *);


#endif