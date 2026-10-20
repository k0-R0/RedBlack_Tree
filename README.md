# Red-Black Tree in C

A complete implementation of a self-balancing Red-Black Binary Search Tree in C, based on the CLRS algorithms.

The implementation uses an explicit sentinel (`NIL`) node rather than `NULL` pointers to simplify boundary conditions during rotations and fixups.

## Features

- **Self-Balancing Operations**:
  - `rb_insert`: Standard BST insertion followed by recoloring and rotations to restore Red-Black properties.
  - `rb_delete`: Node deletion handling 0, 1, or 2 children, transplanting nodes, and fixing black-height deficits (double-black cases).
- **BST Primitives**:
  - Search (`rb_search`)
  - Minimum & Maximum (`rb_minimum`, `rb_maximum`)
  - In-order Successor & Predecessor (`rb_successor`, `rb_predecessor`)
- **Traversals**:
  - In-order (sorted order)
  - Pre-order
  - Post-order
- **Interactive CLI**: Menu-driven interface in `main.c` to test inserts, deletes, searches, and traversals.

## Project Structure

```text
.
├── Tree.h        # Node and RBTree definitions, function declarations
├── Tree.c        # Core Red-Black tree implementation
├── main.c        # Interactive CLI menu
├── makefile      # Build script
└── README.md
```

## Building and Running

Compile using `make`:

```bash
make
```

Run the interactive program:

```bash
./RBTree
```

To clean up build artifacts:

```bash
make clean
```

For debug symbols:

```bash
make debug
```

## Example CLI Usage

When running `./RBTree`, you can interact with the tree through the menu:

```text
=== Red-Black Tree Menu ===
1. Create / Reset Tree
2. Insert Element
3. Delete Element
4. Search Element
5. Print Tree (Traversals)
6. Exit
Enter choice (1-6): 2
Enter integer to insert: 10
Successfully inserted 10. (Tree size: 1)

=== Red-Black Tree Menu ===
...
Enter choice (1-6): 5

Select Traversal:
1. In-order   (Sorted)
2. Pre-order  (Root-first)
3. Post-order (Leaves-first)
4. All
Choice: 1
In-order: 5 10 15 20
```

## API Overview

```c
/* Lifecycle */
RBTree *rb_tree_create(void);
void rb_tree_destroy(RBTree *tree);

/* Modifications */
bool rb_insert(RBTree *tree, int val);
bool rb_delete(RBTree *tree, int val);

/* Queries */
Node *rb_search(RBTree *tree, int key);
Node *rb_minimum(RBTree *tree, Node *node);
Node *rb_maximum(RBTree *tree, Node *node);
Node *rb_successor(RBTree *tree, Node *node);
Node *rb_predecessor(RBTree *tree, Node *node);

/* Traversals */
void rb_inorder(RBTree *tree);
void rb_preorder(RBTree *tree);
void rb_postorder(RBTree *tree);
```
