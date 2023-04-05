#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

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
    print_list(first);

    return EXIT_SUCCESS;
}
