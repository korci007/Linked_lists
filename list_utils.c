#include <stdlib.h>
#include <stdio.h>
#include "list_utils.h"

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
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = first;
    return new_node;
}

// traverse the list and print it's values
void print_list(const struct node *some_node){
    while (some_node) {
        printf("%d->", some_node->value);
        some_node = some_node->next;
    }
    printf("NULL\n");
}

// traverse the list and delete nodes one-by-one by freeing up memory
struct node *delete_by_value(struct node *list, int val){
    struct node *prev, *curr;
    
    for (curr = list, prev = NULL; curr != NULL && curr->value != val; 
        prev = curr, curr = curr->next)
        ;
    if (curr == NULL) { // value not found
        return list;
    } else if (prev == NULL) { // value is the first in the list
        list = list->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    return list;
}
