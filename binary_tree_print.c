#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * print_t - funcs that Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, q;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (q = 0; q < width; q++)
		s[depth][offset + left + q] = b[q];
	if (depth && is_left)
	{
		for (q = 0; q < width + right; q++)
			s[depth - 1][offset + left + width / 2 + q] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (q = 0; q < left + width; q++)
			s[depth - 1][offset - width / 2 + q] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, q, w;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (q = 0; q < height + 1; q++)
	{
		s[q] = malloc(sizeof(**s) * 255);
		if (!s[q])
			return;
		memset(s[q], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (q = 0; q < height + 1; q++)
	{
		for (w = 254; w > 1; --w)
		{
			if (s[q][w] != ' ')
				break;
			s[q][w] = '\0';
		}
		printf("%s\n", s[q]);
		free(s[w]);
	}
	free(s);
}
