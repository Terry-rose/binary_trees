#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST)
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (tree == NULL)
		return (NULL);

	/* If the tree is empty, create a new node as root */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;

	/* Traverse the tree to find the appropriate position */
	while (current != NULL)
	{
		/* If the value already exists, return NULL */
		if (value == current->n)
			return (NULL);

		/* If the value is less than current node, go left */
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				/* Insert the value as the left child */
				new_node = binary_tree_node(current, value);
				current->left = new_node;
				return (new_node);
			}
			current = current->left;
		}
		/* If the value is greater than current node, go right */
		else
		{
			if (current->right == NULL)
			{
				/* Insert the value as the right child */
				new_node = binary_tree_node(current, value);
				current->right = new_node;
				return (new_node);
			}
			current = current->right;
		}
	}

	/* Should never reach here */
	return (NULL);
}

