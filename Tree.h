#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { RB_BLACK, RB_RED } NodeColor;

typedef struct Node {
    int val;
    NodeColor color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

typedef struct RBTree {
    Node *root;
    Node *nil;
    size_t size;
} RBTree;

void nodes_destroy(RBTree *tree, Node *node);
RBTree *rb_tree_create();
void rb_tree_destroy(RBTree *tree);
Node *rb_search(RBTree *tree, int key);
Node *rb_minimum(RBTree *tree, Node *node);
Node *rb_maximum(RBTree *tree, Node *node);
Node *rb_successor(RBTree *tree, Node *node);
Node *rb_predecessor(RBTree *tree, Node *node);
void rb_inorder(RBTree *tree);
void rb_preorder(RBTree *tree);
void rb_postorder(RBTree *tree);
void rb_rotate_left(RBTree *tree, Node *node);
void rb_rotate_right(RBTree *tree, Node *node);
bool rb_insert(RBTree *tree, int val);

#endif
