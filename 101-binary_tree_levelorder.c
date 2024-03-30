#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_levelorder - Traverses a binary tree in level-order fashion
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h = binary_tree_height(tree);
	size_t i;

	if (tree == NULL || func == NULL)
		return;

	for (i = 1; i <= h; i++)
		binary_tree_levelorder_helper(tree, i, func);
}

/**
 * binary_tree_levelorder_helper - Helps to traverse a binary tree in level-order
 * @tree: A pointer to the root node of the tree to traverse.
 * @level: The level of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder_helper(const binary_tree_t *tree, size_t level,
				   void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_levelorder_helper(tree->left, level - 1, func);
		binary_tree_levelorder_helper(tree->right, level - 1, func);
	}
}

