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

#endif
