#include <stdlib.h>
#include <stdbool.h>

#include "binary_trees.h"

/**
 * is_full - recursively walk tree to see if it's full
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: true or false -- is it full? --
 */
static bool is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (true);

	if ((tree->left != NULL && tree->right == NULL) ||
		(tree->left == NULL && tree->right != NULL) ||
		is_full(tree->left) == 0 || is_full(tree->right) == 0)
		return (false);

	return (true);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: asdf adsf
 */
bool binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (false);

	return (is_full(tree));
}
