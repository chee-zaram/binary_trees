# Binary Trees

---

This is a project focused on the use of [binary tree](https://en.wikipedia.org/wiki/Binary_tree)
data structure. It shows the implementation of various binary tree operations
such as insert, deletion, traversal. Various functions also exist to get important
data about a tree, like the height, depth of a node, relations of a given node e.t.c.
Here, you will find C functions for performing various operations on binary trees.

## Operations

The functions implemented include:

- `binary_tree_node`: This function creates a new node without any children. It takes
  a pointer to the parent of.
- `binary_tree_insert_left`: This function inserts a node as the left child of the parent.
  It takes a pointer to the parent, and if the parent already has a left child, the
  new node takes its place and the previous left child becomes the left child of the new node.
- `binary_tree_insert_right`: This function inserts a node as the right child of the parent.
  It takes a pointer to the parent, and if the parent already has a right child, the
  new node takes its place and the previous right child becomes the right child of the new node.
- `binary_tree_delete`: This function deletes an entire tree. It takes a pointer to the
  root node in the tree.
- `binary_tree_is_leaf`: This function checks if a node is a leaf node.
- `binary_tree_is_root`: This function checks if a node is the root of a tree.
- `binary_tree_preorder`: This function goes through a binary tree using pre-order traversal.
- `binary_tree_inorder`: This function goes through a binary tree using in-order traversal.
- `binary_tree_postorder`: This function goes through a binary tree using post-order traversal.
- `binary_tree_height`: This function calculates the height of a binary tree.
  It takes a pointer to the root node of the tree as an argument and returns the height of the tree.
- `binary_tree_depth`: This function calculates the depth of a node in a binary tree.
  It takes a pointer to the node as an argument and returns the depth of the node.
- `binary_tree_size`: This function calculates the size of a binary tree.
  It takes a pointer to the root node of the tree as an argument and returns the size of the tree.
- `binary_tree_leaves`: This function counts the number of leaves in a binary tree.
  It takes a pointer to the root node of the tree as an argument and returns the number of leaves in the tree.
- `binary_tree_nodes`: This function counts the number of nodes in a binary tree
  that have at least one child. It takes a pointer to the root node of the tree as an argument
  and returns the number of nodes in the tree.
- `binary_tree_balance`: This function calculates the balance factor of a binary tree.
  It takes a pointer to the root node of the tree as an argument and returns the balance factor of the tree.
- `binary_tree_is_full`: This function checks if a binary tree is full. It takes a pointer
  to the root node of the tree as an argument and returns 1 if the tree is full, 0 otherwise.
- `binary_tree_is_perfect`: This function checks if a binary tree is perfect.
  It takes a pointer to the root node of the tree as an argument and returns 1 if the tree is perfect, 0 otherwise.
- `binary_tree_sibling`: This function finds the sibling of a given node. It takes a pointer to the node
  for which to find the sibling.
- `binary_tree_uncle`: This function finds the uncle of a given node. It takes a pointer to the node
  for which to find the uncle.
- `binary_trees_ancestor`: This function finds the lowest common ancestor of two nodes. It takes a pointer
  to the two nodes in question and returns the a pointer to the lowest common ancestor if it exists.
- `binary_tree_levelorder`: This function goes through a binary tree using level-order traversal algorithm.
  It takes a pointer to the root of the tree and a pointer to a function to print the data.
- `binary_tree_is_complete`: This function checks whether a binary tree is complete. It takes a pointer to the root
  of the tree.
- `binary_tree_rotate_left`: This performs a left rotation on a node in a tree.
  It takes a pointer to the node in question.
- `binary_tree_rotate_right`: This performs a right rotation on a node in a tree.
  It takes a pointer to the node in question.
- `binary_tree_is_bst`: This function checks if a binary tree fits a binary search tree.
  It takes a pointer to the root of the tree.

Each function has a prototype in the binary_trees.h header file and an implementation in the corresponding .c file.

## Usage

To use these functions in your project, include the [binary_trees.h](https://github.com/chee-zaram/binary_trees/blob/main/binary_trees.h)
header file in your source code and link against the .c files containing the implementations.

Here is an example usage of the binary_tree_height function:

```c
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root = NULL;
    size_t height;

    /* create the binary tree */
    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->left = binary_tree_node(root->right, 128);
    root->right->right = binary_tree_node(root->right, 256);
    root->right->left->left = binary_tree_node(root->right->left, 45);
    root->right->left->right = binary_tree_node(root->right->left, 60);

    /* calculate the height of the binary tree */
    height = binary_tree_height(root);
    printf("Height of binary tree: %lu\n", height);

    return (0);
}
```

This will output:

```sh
Height of binary tree: 3
```
