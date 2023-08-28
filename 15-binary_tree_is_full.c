#include "binary_trees.h"

/**
  * binary_tree_is_full - checks if a binary tree is full
  * @tree: root node of the BT
  * Return: numbers of leave
  */
int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t full_l = 0, full_r = 0, full = 0;

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);

	full_l = binary_tree_is_full(tree->left);
	full_r = binary_tree_is_full(tree->right);

	if ((full_l == 1 && full_r == 0) || (full_l == 0 && full_r == 1))
		full = 0;
	else
		full = 1;

	return (full);
}
