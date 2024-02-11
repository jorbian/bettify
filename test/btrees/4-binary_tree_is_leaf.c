#include "binary_trees.h"

/**
 * binary_tree_is_leaf - determines whether or not a given node is a leaf
 * @node: the node to be tested
 *
 * Return: '0' if it's not a leaf, '1' if it is.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if ((node == NULL) || (node->right != NULL) || (node->left != NULL))
		return (0);

	return (1);
}
