#include "Tree.h"

void nodes_destroy(RBTree *tree, Node *node) {
    if (node == tree->nil)
        return;
    nodes_destroy(tree, node->left);
    nodes_destroy(tree, node->right);
    free(node);
}

RBTree *rb_tree_create() {
    RBTree *tree = malloc(sizeof(RBTree));
    tree->nil = malloc(sizeof(Node));
    tree->nil->val = 0;
    tree->nil->color = RB_BLACK;
    tree->nil->parent = NULL;
    tree->nil->left = NULL;
    tree->nil->right = NULL;
    tree->root = tree->nil;
    tree->root->parent = tree->nil;
    return tree;
}

void rb_tree_destroy(RBTree *tree) {
    nodes_destroy(tree, tree->root);
    free(tree->nil);
    free(tree);
}

Node *rb_search(RBTree *tree, int key) {
    Node *curr = tree->root;
    while (curr != tree->nil && curr->val != key) {
        if (key < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return curr;
}

Node *rb_minimum(RBTree *tree, Node *node) {
    if (node == tree->nil)
        return node;
    while (node->left != tree->nil)
        node = node->left;
    return node;
}

Node *rb_maximum(RBTree *tree, Node *node) {
    if (node == tree->nil)
        return node;
    while (node->right != tree->nil)
        node = node->right;
    return node;
}

Node *rb_successor(RBTree *tree, Node *node) {
    if (node == tree->nil)
        return node;
    if (node->right != tree->nil)
        return rb_minimum(tree, node->right);
    Node *p = node->parent;
    while (p != tree->nil && node != p->left) {
        node = p;
        p = node->parent;
    }
    return p;
}

Node *rb_predecessor(RBTree *tree, Node *node) {
    if (node == tree->nil)
        return node;
    if (node->left != tree->nil)
        return rb_maximum(tree, node->left);
    Node *p = node->parent;
    while (p != tree->nil && node != p->right) {
        node = p;
        p = node->parent;
    }
    return p;
}

void inorder(RBTree *tree, Node *node) {
    if (node == tree->nil)
        return;
    inorder(tree, node->left);
    printf("%d ", node->val);
    inorder(tree, node->right);
}

void rb_inorder(RBTree *tree) { inorder(tree, tree->root); }

void preorder(RBTree *tree, Node *node) {
    if (node == tree->nil)
        return;
    printf("%d ", node->val);
    preorder(tree, node->left);
    preorder(tree, node->right);
}

void rb_preorder(RBTree *tree) { preorder(tree, tree->root); }

void postorder(RBTree *tree, Node *node) {
    if (node == tree->nil)
        return;
    postorder(tree, node->left);
    postorder(tree, node->right);
    printf("%d ", node->val);
}

void rb_postorder(RBTree *tree) { postorder(tree, tree->root); }

void rb_rotate_left(RBTree *tree, Node *node) {
    if (node == tree->nil || node->right == tree->nil)
        return;
    // get rightnode
    Node *right_node = node->right;
    node->right = right_node->left;
    right_node->left = node;
    // swap parents
    right_node->parent = node->parent;
    node->parent = right_node;
    if (node->right != tree->nil)
        node->right->parent = node;

    if (right_node->parent == tree->nil)
        tree->root = right_node;
    else if (right_node->parent->left == node)
        right_node->parent->left = right_node;
    else
        right_node->parent->right = right_node;
}

void rb_rotate_right(RBTree *tree, Node *node) {
    if (node == tree->nil || node->left == tree->nil)
        return;
    Node *left_node = node->left;
    node->left = left_node->right;
    left_node->right = node;
    // swap parents
    left_node->parent = node->parent;
    node->parent = left_node;
    if (node->left != tree->nil)
        node->left->parent = node;

    if (left_node->parent == tree->nil)
        tree->root = left_node;
    else if (left_node->parent->left == node)
        left_node->parent->left = left_node;
    else
        left_node->parent->right = left_node;
}
