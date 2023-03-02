#ifndef _BINARY_TREES_
#define _BINARY_TREES_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROOT       0
#define CHILD      1
#define LEAF       0
#define REPLACE    1
#define INCOMPLETE 0
#define COMPLETE   1

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

/*************************** main functions ****************************/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void           binary_tree_delete(binary_tree_t *tree);
int            binary_tree_is_leaf(const binary_tree_t *node);
int            binary_tree_is_root(const binary_tree_t *node);
void           binary_tree_preorder(const binary_tree_t *, void (*func)(int));
void           binary_tree_inorder(const binary_tree_t *, void (*func)(int));
void           binary_tree_postorder(const binary_tree_t *, void (*func)(int));
size_t         binary_tree_height(const binary_tree_t *tree);
size_t         binary_tree_depth(const binary_tree_t *tree);
size_t         binary_tree_size(const binary_tree_t *tree);
size_t         binary_tree_leaves(const binary_tree_t *tree);
size_t         binary_tree_nodes(const binary_tree_t *tree);
int            binary_tree_balance(const binary_tree_t *tree);
int            binary_tree_is_full(const binary_tree_t *tree);
int            binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/*************************** advanced tasks ****************************/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);
void           binary_tree_levelorder(const binary_tree_t *tree,
				      void (*func)(int));
int            binary_tree_is_complete(const binary_tree_t *tree);

/*************************** helper functions ****************************/
void           binary_tree_print(const binary_tree_t *);
binary_tree_t *create_node(binary_tree_t *new_node, int value, int side);
binary_tree_t *insert_node_left(binary_tree_t *new_node, int value, int side);
binary_tree_t *insert_node_right(binary_tree_t *new_node, int value, int side);
int            binary_tree_is_leaf(const binary_tree_t *node);
void           _binary_tree_levelorder(const binary_tree_t *tree, size_t level,
				       void (*func)(int));
int            is_complete(const binary_tree_t *, size_t, size_t);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

#endif /* for _BINARY_TREES_ */
