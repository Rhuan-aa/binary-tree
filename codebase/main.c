#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(int argc, char const *argv[]){
    t_binary_tree *tree = create("(A,(B,(),()),(C,(F,(),()),()))");

    if (tree == NULL) {
        printf("invalid");
        return 0;
    }

    formatted_print(tree, tree->root);
    printf("Pre Order: \n");
    pre_order(tree->root);
    printf("\nIn Order: \n");
    in_order(tree->root);
    printf("\nPost Order: \n");
    post_order(tree->root);

    exit_tree(tree);
    return 0;
}