#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *insert_node(struct node *first, int n);
void print_list(const struct node *some_node);
void delete_node(struct node *some_node);
struct node *populate_list(struct node *);
int sum_list(const struct node *);
size_t num_nodes(const struct node *);

int main(int argc, char **argv){
    struct node *first = NULL;

    if (argc < 2) {
        printf("Usage: linked_lists int_value1 int_value2 ...\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 1; i < argc; i++) {
        int number = atoi(argv[i]); // no error checking yet
        first = insert_node(first, number);
    }


    printf("\n");
    printf("The number of nodes used: %zu\n", num_nodes(first));
    printf("The sum of entered values is: %d\n", sum_list(first));
    //print_list(first);

    while (first) {
        delete_node(first);
    }

    return EXIT_SUCCESS;
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
struct node *populate_list(struct node *first_node){
    for(;;) {
        printf("Enter integer values to store or '0' to stop: ");
        int num;
        scanf("%d", &num);
        if (!num) {
            return first_node;
        }
        first_node = insert_node(first_node, num);       
    }
}

// traverse the node and sum it's values
int sum_list(const struct node *some_node){
    int sum = 0;
    while (some_node) {
        sum += some_node->value;
        some_node = some_node->next;
    }
    return sum;
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
        printf("Value: %d\n", some_node->value);
        some_node = some_node->next;
    }
}

// traverse the list and delete nodes one-by-one by freeing up memory
void delete_node(struct node *some_node){
    struct node *prev_node = some_node;
    while (some_node->next) {
        prev_node = some_node;
        some_node = some_node->next;
    }

    free(prev_node->next);
    prev_node->next = NULL;
}
