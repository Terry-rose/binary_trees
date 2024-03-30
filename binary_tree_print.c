#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

#define MAX_HEIGHT 100

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[MAX_HEIGHT][MAX_HEIGHT * 2];
	int width, left, right, i;

	if (!tree)
		return (0);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + 1, depth + 1, s);
	sprintf(b[0] + offset, "(%03d)", tree->n);
	width = strlen(b[0]);
	for (i = 0; i < MAX_HEIGHT && i < depth; i++)
	{
		memcpy(b[i] + offset + left + 1, " ", right * sizeof(char));
		memcpy(b[i + 1] + offset + left + 1, " ", right * sizeof(char));
		memcpy(b[i + 1] + offset - 1, b[i], width + 2);
	}
	if (depth)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + i] = b[0][offset + left + i];
	}
	else
	{
		for (i = 0; i < width + right; i++)
			s[0][i] = b[0][i];
	}
	for (i = 0; i < MAX_HEIGHT && b[i][0]; i++)
		printf("%s\n", b[i]);
	return (width + left + right);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char *s[MAX_HEIGHT];
	int i;

	for (i = 0; i < MAX_HEIGHT; i++)
	{
		s[i] = (char *)calloc(255, sizeof(char));
		if (!s[i])
			return;
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < MAX_HEIGHT; i++)
	{
		free(s[i]);
	}
}

