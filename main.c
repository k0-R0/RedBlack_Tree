#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

static void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

static void print_menu() {
    printf("\n=== Red-Black Tree Menu ===\n");
    printf("1. Create / Reset Tree\n");
    printf("2. Insert Element\n");
    printf("3. Delete Element\n");
    printf("4. Search Element\n");
    printf("5. Print Tree (Traversals)\n");
    printf("6. Exit\n");
    printf("Enter choice (1-6): ");
}

static void handle_print(RBTree *tree) {
    if (!tree || tree->root == tree->nil) {
        printf("Tree is empty.\n");
        return;
    }

    printf("\nSelect Traversal:\n");
    printf("1. In-order   (Sorted)\n");
    printf("2. Pre-order  (Root-first)\n");
    printf("3. Post-order (Leaves-first)\n");
    printf("4. All\n");
    printf("Choice: ");

    int choice;
    if (scanf("%d", &choice) != 1) {
        clear_input_buffer();
        printf("Invalid input.\n");
        return;
    }

    switch (choice) {
    case 1:
        printf("In-order: ");
        rb_inorder(tree);
        printf("\n");
        break;
    case 2:
        printf("Pre-order: ");
        rb_preorder(tree);
        printf("\n");
        break;
    case 3:
        printf("Post-order: ");
        rb_postorder(tree);
        printf("\n");
        break;
    case 4:
        printf("In-order:   ");
        rb_inorder(tree);
        printf("\nPre-order:  ");
        rb_preorder(tree);
        printf("\nPost-order: ");
        rb_postorder(tree);
        printf("\n");
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }
}

int main() {
    RBTree *tree = rb_tree_create();
    int choice;
    int val;

    printf("Red-Black Tree initialized.\n");

    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("Please enter a valid number.\n");
            continue;
        }

        switch (choice) {
        case 1:
            if (tree)
                rb_tree_destroy(tree);
            tree = rb_tree_create();
            printf("Tree created/reset successfully.\n");
            break;

        case 2:
            printf("Enter integer to insert: ");
            if (scanf("%d", &val) != 1) {
                clear_input_buffer();
                printf("Invalid integer.\n");
                break;
            }
            if (rb_insert(tree, val)) {
                printf("Successfully inserted %d. (Tree size: %zu)\n", val,
                       tree->size);
            } else {
                printf("Failed to insert %d.\n", val);
            }
            break;

        case 3:
            if (tree->root == tree->nil) {
                printf("Tree is empty. Nothing to delete.\n");
                break;
            }
            printf("Enter integer to delete: ");
            if (scanf("%d", &val) != 1) {
                clear_input_buffer();
                printf("Invalid integer.\n");
                break;
            }
            if (rb_delete(tree, val)) {
                printf("Successfully deleted %d. (Tree size: %zu)\n", val,
                       tree->size);
            } else {
                printf("Value %d not found in tree.\n", val);
            }
            break;

        case 4:
            if (tree->root == tree->nil) {
                printf("Tree is empty.\n");
                break;
            }
            printf("Enter integer to search: ");
            if (scanf("%d", &val) != 1) {
                clear_input_buffer();
                printf("Invalid integer.\n");
                break;
            }
            {
                Node *found = rb_search(tree, val);
                if (found != tree->nil) {
                    printf("Found %d [Color: %s]\n", found->val,
                           found->color == RB_RED ? "RED" : "BLACK");
                } else {
                    printf("Value %d not found in tree.\n", val);
                }
            }
            break;

        case 5:
            handle_print(tree);
            break;

        case 6:
            printf("Exiting...\n");
            if (tree)
                rb_tree_destroy(tree);
            return 0;

        default:
            printf("Invalid option. Please choose between 1 and 6.\n");
            break;
        }
    }

    return 0;
}
