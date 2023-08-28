#include "binary_trees.h"

/**
  * binary_tree_inorder - Goes through a binary tree using in-order traversal
  * @tree: root node of the BT
  * @func: function to print the traverse
  * Return: Nothing
  */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
