#include "binary_trees.h"

/**
 * insert - Inserts a new node into the binary search tree
 * @node: Pointer to the current node under evaluation
 * @new_node: Pointer to the new node to insert
 *
 * Return: true if inserted correctly, false otherwise
 */
static bst_t *insert(bst_t *node, bst_t *new_node)
{
	if (!node || new_node->n == node->n)
	{
		free(new_node);
		return (NULL);
	}

	if (!node->left && node->n > new_node->n)
	{
		node->left = new_node;
		return (new_node);
	}

	if (!node->right && node->n < new_node->n)
	{
		node->right = new_node;
		return (new_node);
	}

	return (new_node->n < node->n ? insert(node->left, new_node)
				      : insert(node->right, new_node));
}

/**
 * bst_insert - Inserts a node in a binary search tree
 * @tree: Address of the pointer to the root node of the tree
 * @value: Value stored in the node to be inserted
 *
 * Return: A pointer to the newly created node, or NULL otherwise
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;

	if (!tree)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*tree)
	{
		*tree = new_node;
		return (new_node);
	}

	return (insert(*tree, new_node));
}
