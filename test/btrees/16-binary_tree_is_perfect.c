#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of binary tree.
 * @tree: Pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}


/**
 * binary_tree_is_perfect - checks if a given tree is full and balanced
 * @tree: pointer to the root node of a tree
 *
 * Return: the number of nodes with atleast one child
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int buffer = 0;

	if (tree == NULL)
		return (0);

	if (tree->left && tree->right)
	{
		*((short *)&buffer) = binary_tree_size(tree->left);
		*((short *)&buffer + 1) = binary_tree_size(tree->right);
	}
	if (*((short *)&buffer) == *((short *)&buffer + 1))
		return (1);

	return (0);
}
