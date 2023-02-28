#ifndef _BINARY_TREES_
#define _BINARY_TREES_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROOT    0
#define LEFT    1
#define RIGHT   2
#define LEAF    0
#define REPLACE 1

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int                   n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* main functions */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void           binary_tree_delete(binary_tree_t *tree);
int            binary_tree_is_leaf(const binary_tree_t *node);
int            binary_tree_is_root(const binary_tree_t *node);
void           binary_tree_preorder(const binary_tree_t *, void (*func)(int));
void           binary_tree_inorder(const binary_tree_t *, void (*func)(int));

/* helper functions */
void           binary_tree_print(const binary_tree_t *);
binary_tree_t *create_node(binary_tree_t *new_node, int value, int side);
binary_tree_t *insert_node_left(binary_tree_t *new_node, int value, int side);
binary_tree_t *insert_node_right(binary_tree_t *new_node, int value, int side);
int            binary_tree_is_leaf(const binary_tree_t *node);

#endif /* for _BINARY_TREES_ */
