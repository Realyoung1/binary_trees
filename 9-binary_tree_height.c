#include "binary_trees.h"

/**
  * count_nodes - measures the height of a binary tree
  * @tree: root node of the BT
  * Return: the number of nodes
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
  * logbase2 - measures the height of a binary tree
  * @nodes: root node of the BT
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
  * binary_tree_height - measures the height of a binary tree
  * @tree: root node of the BT
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
