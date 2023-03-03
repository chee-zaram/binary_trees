#include "binary_trees.h"

/**
 * bst_remove - Deletes a node from a binary search tree
 * @root: A pointer to the root node of the tree
 * @value: The value of the node to delete
 *
 * Description: If the node to delete has two children, it is replaced with its
 *		first in-order successor.
 *
 * Return: A pointer to the new root node of the new after deletion
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *replacement = NULL, *successor = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Case 1: No children */
		if (!root->left && !root->right)
		{
			free(root), root = NULL;
			return (NULL);
		}

		/* Case 2: One child */
		if (!root->left)
		{
			replacement = root->right;
			free(root), root = NULL;
			return (replacement);
		}
		if (!root->right)
		{
			replacement = root->left;
			free(root), root = NULL;
			return (replacement);
		}

		/* Case 3: Two children */
		successor = root->right;
		while (successor->left)
			successor = successor->left;
		root->n     = successor->n;
		root->right = bst_remove(root->right, successor->n);
	}
	return (root);
}
