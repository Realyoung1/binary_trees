#include "binary_trees.h"

/**
  * node_depth - count the levels of the Binary tree
  * @tree: root node of the BT
  * Return: Nothing
  */
size_t node_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + node_depth(tree->parent));
}

/**
  * binary_tree_depth - measures the depth of a node in a binary tree
  * @tree: root node of the BT
  * Return: Nothing
  */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (node_depth(tree) - 1);
}
