#include "binary_trees.h"

/**
  * binary_tree_leaves - counts the leaves in a binary tree
  * @tree: root node of the BT
  * Return: numbers of leave
  */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		leaf = 1;

	leaf += binary_tree_leaves(tree->left);
	leaf += binary_tree_leaves(tree->right);

	return (leaf);
}
