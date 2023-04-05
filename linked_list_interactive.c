#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *insert_node(struct node *, int);
void print_list(const struct node *);
struct node *delete_node(struct node *, int);
struct node *populate_list(void);
static size_t num_nodes(const struct node *);

int main(void){
    

    struct node *my_list = populate_list();


    printf("\n");
    printf("The number of nodes used: %zu\n", num_nodes(my_list));
    printf("The entered list:\n");
    print_list(my_list);

    printf("Value to delete: ");
    int value;
    scanf("%d", &value);
    my_list = delete_node(my_list, value);
    print_list(my_list);

    return EXIT_SUCCESS;
}

// count the number of nodes in the list
static size_t num_nodes(const struct node *current_node){
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
struct node *delete_node(struct node *list, int val){
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
