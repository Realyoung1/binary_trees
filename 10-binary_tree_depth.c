#include "binary_trees.h"

/**
  * node_depth - funcs that countss the levels of the Binary trees
  * @tree: rootss node of the BT
  * Return: Nothing
  */

size_t node_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + node_depth(tree->parent));
}

/**
  * binary_tree_depth - funcs that measures the depths of a node in a binary trees
  * @tree: roots node of the BT
  * Return: Nothing
  */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (node_depth(tree) - 1);
}
