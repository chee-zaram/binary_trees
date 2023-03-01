#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: A pointer to the parent node of the node to create
 * @value: The value to be stored in the new node
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	if (!parent)
		return (create_node(parent, value, ROOT));

	if (parent->left == NULL)
		return (create_node(parent, value, LEFT));

	if (parent->right == NULL)
		return (create_node(parent, value, RIGHT));

	return (NULL);
}

/**
 * create_node - Adds a new node with the given value
 * @parent: Address of the pointer to the new node
 * @value: Value to store in the new node
 * @side: Where to place child node
 *
 * Return: Pointer to the new node, or NULL if failed
 */
binary_tree_t *create_node(binary_tree_t *parent, int value, int side)
{
	binary_tree_t *new_node = NULL;

	if (side == ROOT)
		new_node = parent;
	else if (side == LEFT)
		new_node = (parent->left);
	else
		new_node = (parent->right);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
	{
		perror("Failed to create new node");
		return (NULL);
	}

	(new_node)->n     = value;
	(new_node)->left  = NULL;
	(new_node)->right = NULL;

	if (side == ROOT)
	{
		(new_node)->parent = NULL;
		return (new_node);
	}

	(new_node)->parent = parent;

	return (new_node);
}
