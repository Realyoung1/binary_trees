#include "binary_trees.h"

/**
  * binary_tree_preorder - Goes through a binary tree using pre-order traversal
  * @tree: root node of the BT
  * @func: function to print the traverse
  * Return: Nothing
  */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{

	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
