#include "binary_trees.h"

/**
  * binary_tree_insert_right - Insert a node on right of Binary tree
  * @parent: node parent
  * @value: key to insert in the new node
  * Return: the address of the new node
  */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newright_node = NULL;

	if (!parent)
		return (NULL);

	newright_node = binary_tree_node(parent, value);
	if (!newright_node)
		return (NULL);

	if (parent->right)
	{
		parent->right->parent = newright_node;
		newright_node->right = parent->right;
	}
	parent->right = newright_node;

	return (newright_node);
}
