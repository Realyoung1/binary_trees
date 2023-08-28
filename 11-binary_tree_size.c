#include "binary_trees.h"

/**
  * binary_tree_size - funcs measuring the size of a binary treess
  * @tree: rootss node of the BT
  * Return: the numbesr of node
  */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);

	size = 1;
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}
