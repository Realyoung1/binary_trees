#include "binary_trees.h"

/**
  * count_nodes - funcs that measures the height of a binary treess
  * @tree: roots nodes of the BT
  * Return: the numbers of nodes
  */

size_t count_nodes(const binary_tree_t *tree)
{
	size_t height = 0;

	if (!tree)
		return (0);

	height = 1;
	height = height + count_nodes(tree->left);
	height = height + count_nodes(tree->right);

	return (height);
}

/**
  * logbase2 - funcs that measurs the heights of a binary trees
  * @nodes: roots nodes of the BT
  * Return: Nothing
  */

size_t logbase2(size_t nodes)
{
	size_t height = 0, pow2 = 1;

	while (nodes >= pow2)
	{
		height++;
		pow2 = pow2 * 2;
	}
	return (height - 1);
}

/**
  * binary_tree_height - funcs that measurs the height of a binary trees
  * @tree: roots node of the BT
  * Return: Nothing
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (!tree)
		return (0);

	height = logbase2(count_nodes(tree));

	return (height);
}
