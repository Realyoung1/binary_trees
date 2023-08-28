#include "binary_trees.h"

/**
  * binary_tree_is_root - funcs Checking if a node is the rootings
  * @node: nodess of the BT
  * Return: 1 if a node is a root otherwise 0
  */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!(node->parent))
		return (1);

	return (0);
}
