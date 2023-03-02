#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree
 * @tree: Pointer to the root of the tree
 *
 * Return: 1 if the tree is a binary search tree, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int left_value = 0, right_value = 0;

	if (!tree)
		return (0);
	if (tree->parent && tree->parent->parent)
	{
		/* ancestor should be > or < than current value depending on the side */
		if (tree->parent == tree->parent->parent->left
		    && tree->n >= tree->parent->parent->n)
			return (0);
		if (tree->parent == tree->parent->parent->right
		    && tree->n <= tree->parent->parent->n)
			return (0);
	}

	/* taking care of single child nodes */
	if (!tree->left && tree->right)
		if (tree->right->n > tree->n)
			return (1);
	if (tree->left && !tree->right)
		if (tree->left->n < tree->n)
			return (1);

	/* handling nodes with no children */
	if (!tree->left && !tree->right)
		return (1);

	if (tree->left)
		left_value = tree->left->n;
	if (tree->right)
		right_value = tree->right->n;

	if (left_value < tree->n && tree->n < right_value)
		return (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->right));

	if (left_value != 0 || right_value != 0)
		return (left_value ? binary_tree_is_bst(tree->left)
				   : binary_tree_is_bst(tree->right));

	return (0);
}
