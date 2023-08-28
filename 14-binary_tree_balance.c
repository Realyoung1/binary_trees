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

/**
  * binary_tree_height - counts the leaves in a binary tree
  * @tree: root node of the BT
  * Return: numbers of leave
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, height_left = 0, height_right = 0, max_high = 0;

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
	{
		max_high = binary_tree_depth(tree);
		if (max_high > height)
			height = max_high;
		return (height);
	}

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	if (height_left >= height_right)
		height = height_left;

	else
		height = height_right;

	return (height);
}

/**
  * binary_tree_balance - measures the balance factor of a binary tree
  * @tree: root node of the BT
  * Return: numbers of leave
  */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + binary_tree_height(tree->left);
		height_left -= binary_tree_depth(tree->left);

	if (tree->right)
		height_right = 1 + binary_tree_height(tree->right);
		height_right -= binary_tree_depth(tree->right);

	return (height_left - height_right);
}
