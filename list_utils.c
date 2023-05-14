#include <stdlib.h>
#include <stdio.h>
#include "list_utils.h"

#define safeFree(p) saferFree((void**) &(p))

// pointer to the last node to contain n or return NULL
struct node *find_last(struct node *list, int n){
    struct node *last = NULL;
    while(list != NULL) {
        if (list->value == n) {
            last = list;
        }
        list = list->next;
    }
    return last;
}


// count the number of nodes in the list
size_t num_nodes(const struct node *current_node){
    size_t num = 0;
    while(current_node) {
        num++;
        current_node = current_node->next;
    }
    return num;
}

// build the list by repeatedly adding values untill the user enters 0
struct node *populate_list(void){
    struct node *list = NULL;
    
    for(;;) {
        printf("Enter integer values to store or '0' to stop: ");
        int num;
        scanf("%d", &num);
        if (!num) {
            return list;
        }
        list = insert_node(list, num);       
    }
}


// inserts a node before the first node in the list and initializes it's value
struct node *insert_node(struct node *first, int n){
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error inserting a new node\n");
        delete_all(first);
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = first;
    return new_node;
}

// traverse the list and print it's values
void print_list(const struct node *some_node){
    while (some_node) {
        printf("%p:%d->", (void*) some_node, some_node->value);
        some_node = some_node->next;
    }
    printf("NULL\n");
}

// traverse the list and delete nodes one-by-one by freeing up memory
void delete_by_value(struct node **list, int val){
    struct node *prev, *curr;
    
    for (curr = *list, prev = NULL; curr != NULL && curr->value != val; 
        prev = curr, curr = curr->next)
        ;
    if (curr == NULL) { // value not found
        return;
    } else if (prev == NULL) { // value is the first in the list
        *list = (*list)->next;
    } else {
        prev->next = curr->next;
    }
    // free(curr);
    safeFree(curr);
}

// take list delete last element and return the list 
static struct node *delete_last(struct node *list) {
    struct node *curr, *prev;

    for(curr = list, prev = NULL;
        curr->next != NULL; prev = curr, curr = curr -> next)
        ;
    
    if (!prev) {
        list = NULL;
    } else {
        prev->next = NULL;
    }
    // free(curr);
    safeFree(curr);
    return list;
}

// take list and free up all allocated memory
void delete_all(struct node *list) {
    while(list)
        list = delete_last(list);
}

// take a list and append a new node at the and and update it's value
// struct node *append_value(struct node *my_list, int num) {
//     struct node *new_node = malloc(sizeof(struct node));
    
//     if (new_node == NULL) {
//         printf("Error allocating new memory\n");
//         delete_all(my_list);
//         exit(EXIT_FAILURE);
//     }
//     new_node->value = num;
//     new_node->next = NULL;

//     struct node *temp = my_list;

//     while(temp->next) {
//         temp = temp -> next;
//     } 
//     temp->next = new_node;
//     return my_list;
// }

void append_value(struct node **my_list, int num) {
    struct node *new_node = malloc(sizeof(struct node));
    
    if (new_node == NULL) {
        printf("Error allocating new memory\n");
        delete_all(*my_list);
        exit(EXIT_FAILURE);
    }
    new_node->value = num;
    new_node->next = NULL;

    struct node *temp = *my_list;

    while(temp->next) {
        temp = temp -> next;
    } 
    temp->next = new_node;
}

// take a list and search for a given value and return a pointer to the node holding it
// or NULL if not found 
static struct node *search_value(struct node *list, int val){
    
    while (list && list->value != val) {
        list = list->next;
    }
    return list;
}

void saferFree(void **pp) {
    if (pp != NULL && *pp != NULL) {
        free(*pp);
        *pp = NULL;
    }
}

