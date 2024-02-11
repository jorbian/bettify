#include "binary_trees.h"

/**
  * validate - recursive function that does the real work
  * @tree: node that's currently being checked
  * @min: current minimum acceptable value
  * @max: current max
  *
  * Return: Whether a branch of the tree was validated.
 */
static int __validate_BST(binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (
		(__validate_BST(tree->left, min, tree->n - 1)) &&
		(__validate_BST(tree->right, tree->n + 1, max))
	);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of binary tree being examined
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
*/
int binary_tree_is_bst(binary_tree_t *tree)
{
	return (__validate_BST(tree, INT_MIN, INT_MAX));
}
