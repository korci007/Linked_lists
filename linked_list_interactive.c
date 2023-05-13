#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"

int main(void){ 

    struct node *my_list = populate_list();


    printf("\n");
    printf("The number of nodes used: %zu\n", num_nodes(my_list));
    printf("The entered list:\n");
    print_list(my_list);

    printf("Value to delete: ");
    int value;
    scanf("%d", &value);
    // my_list = delete_by_value(my_list, value);
    delete_by_value(&my_list, value);
    print_list(my_list);

    return EXIT_SUCCESS;
}

