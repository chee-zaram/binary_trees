#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: The binary tree to measure the size of.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: The binary tree to check.
 *
 * Return: If tree is NULL or not complete, return 0. Otherwise, return 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t          size, i;
	binary_tree_t **queue;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	queue = malloc(sizeof(binary_tree_t *) * size);
	if (!queue)
		return (0);

	queue[0] = (binary_tree_t *)tree;
	for (i = 0; i < size; i++)
	{
		if (!queue[i])
			break;

		if ((2 * i) + 1 < size)
		{
			queue[(2 * i) + 1] = queue[i]->left;
			queue[(2 * i) + 2] = queue[i]->right;
		}
	}

	free(queue);

	return (i == size);
}
