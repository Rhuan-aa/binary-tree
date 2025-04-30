#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct _node{
    char item;
    struct _node *left;
    struct _node *right;
} t_node;

typedef struct{
    t_node *root;
} t_binary_tree;

t_node *create_node(char item);
t_binary_tree *create(char *string);
t_node *build_tree(char *string, int *index);
int is_valid(char* string);
void exit_tree(t_binary_tree *tree);
void destroy_nodes(t_node *node);
void pre_order(t_node *node);
void in_order(t_node *node);
void post_order(t_node *node);
int count_side(t_node *node);
int tree_height(t_binary_tree *tree);
void formatted_print(t_binary_tree *tree, t_node *node);

#endif