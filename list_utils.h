#ifndef LIST_UTILS_H
#define LIST_UTILS_H

struct node {
    int value;
    struct node *next;
};

// pointer to the last node to contain n or return NULL
struct node *find_last(struct node *list, int n);

// insert node to the begining of the list 
struct node *insert_node(struct node *, int);

// print the contents of a given linked list
void print_list(const struct node *);

// delete a node by a value
// struct node *delete_by_value(struct node *, int);
void delete_by_value(struct node **, int);

// take a list and delete it's last value then return the list
static struct node *delete_last(struct node *);

// take a list and detete it by freeing up all used memory
void delete_all(struct node *);

// create a list by getting values from user
struct node *populate_list(void);

// print the number of usef nodes
size_t num_nodes(const struct node *);

// take a list and append a new node at the and and update it's value
// struct node *append_value(struct node *, int);
 void append_value(struct node **, int);

// take a list and search for a given value and return a pointer to the node holding it
// or NULL if not found 
static struct node *search_value(struct node *, int);

//implement a saferFree() function to free allocated space and set pointers to NULL
void saferFree(void **pp);

#endif