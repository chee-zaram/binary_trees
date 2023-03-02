#include "binary_trees.h"

/**
 * bst_insert - Inserts a new node in a Binary Search Tree recursively
 * @tree: The address to the pointer to the root node of the BST
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		new_node = binary_tree_node(NULL, value);
		if (!new_node)
			return (NULL);

		*tree = new_node;
		return (new_node);
	}

	if (value < (*tree)->n)
		return (bst_insert(&((*tree)->left), value));
	else if (value > (*tree)->n)
		return (bst_insert(&((*tree)->right), value));

	return (NULL);
}
