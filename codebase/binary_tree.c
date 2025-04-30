#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

t_node *create_node(char item){
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void destroy_nodes(t_node *node){
    if (node != NULL){
        destroy_nodes(node->left);
        destroy_nodes(node->right);
        free(node);
    }
}

void exit_tree(t_binary_tree *tree){
    if (tree != NULL){
        destroy_nodes(tree->root);
    }

    free(tree);
}
 
int is_valid(char* string){
    int balance = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '(') balance++;
        else if (string[i] == ')') balance--;
        if (balance < 0) return 0; 
    }
    return balance == 0;
}

t_node *build_tree(char *string, int *index){
    if (string[*index] == '\0') return NULL;
    if (string[*index] != '(') return NULL;
    (*index)++;

    if (string[*index] == ')') {
        (*index)++;
        return NULL;
    }

    t_node *node = create_node(string[*index]);
    (*index)++;

    if (string[*index] != ',') {
        free(node);
        return NULL;
    }
    (*index)++;
    node->left = build_tree(string, index);

    if (string[*index] != ',') {
        destroy_nodes(node->left);
        free(node);
        return NULL;
    }
    (*index)++;
    node->right = build_tree(string, index);

    if (string[*index] != ')') {
        destroy_nodes(node->left);
        destroy_nodes(node->right);
        free(node);
        return NULL;
    }
    (*index)++;

    return node;
}

t_binary_tree *create(char *string){
    if (!is_valid(string)){
        return NULL;
    }

    t_binary_tree *tree = (t_binary_tree *)malloc(sizeof(t_binary_tree));
    int index = 0;
    tree->root = build_tree(string, &index);

    if (string[index] != '\0' || tree->root == NULL) {
        exit_tree(tree);
        return NULL;
    }

    return tree;
}

void pre_order(t_node *node){
    if (node != NULL){
        printf("%c ", node->item);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(t_node *node){
    if (node != NULL){
        in_order(node->left);
        printf("%c ", node->item);
        in_order(node->right);
    }
}

void post_order(t_node *node){
    if (node != NULL){
        post_order(node->left);
        post_order(node->right);
        printf("%c ", node->item);
    }
}

int count_side(t_node *node){
    if (node != NULL){
        int left_height = count_side(node->left);
        int right_height = count_side(node->right);

        if (left_height > right_height){
            return 1 + left_height;
        }
        return 1 + right_height;
    }

    return 0;
}

int tree_height(t_binary_tree *tree){
    if (tree){
        return count_side(tree->root);
    }

    return 0;
}

void formatted_print(t_binary_tree *tree, t_node *node){
    if (node != NULL){
        formatted_print(tree, node->right);

        int height = tree_height(tree);
        int node_height = count_side(node);
        for (int i = height - node_height - 1; i >= 0; i--) {
            printf("    ");
        }
        printf("%c\n", node->item);

        formatted_print(tree, node->left);
    }
}