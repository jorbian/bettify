#include "binary_trees.h"

#define NODE_EXISTS(n) ((n) ? 1 + binary_tree_height(n) : 0)

/**
 * measure_branches - measure the subbranches of the tree
 * @tree: node of the root or sub-root of the tree
 * @counters: pointer to counter array
*/
static void measure_branches(const binary_tree_t *tree, int *counters)
{
	counters[LEFT] = NODE_EXISTS(tree->left);
	counters[RIGHT] = NODE_EXISTS(tree->right);
}

/**
 * is_balanced - Check if the binary tree is balanced
 * @tree: Node of tree to start checking from
 *
 * Return: true if balanced, false if unbalanced
*/
static bool is_balanced(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (true);
	else if (
		LR_BALANCE(
			binary_tree_height(tree->left),
			binary_tree_height(tree->right)
		)
	)
		return (false);
	else
		return (
			is_balanced(tree->left) &&
			is_balanced(tree->right)
		);
}
/**
 * validate_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lowest: The value of the smallest node visited thus far.
 * @highest: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
static int validate_avl(const binary_tree_t *tree, int lowest, int highest)
{
	int height[2];

	if (tree != NULL)
	{
		if (tree->n < lowest || tree->n > highest)
			return (0);

		measure_branches(tree, (int *)&height);

		if (LR_BALANCE(height[LEFT], height[RIGHT]))
			return (0);
		else
			return (
				validate_avl(tree->left, lowest, tree->n - 1) &&
				validate_avl(tree->right, tree->n + 1, highest) &&
				is_balanced(tree)
			);
	}
	return (1);
}

/**
 * binary_tree_height - Measures the height of binary tree.
 * @tree: Pointer to root node to measure the height.
 *
 * Return: Tree is NULL, function returns 0, else returns the height.
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int counters[2];

	if (tree == NULL)
		return (0);

	measure_branches(tree, (int *)&counters);

	return (
		MAX(counters[LEFT], counters[RIGHT])
	);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
bool binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (validate_avl(tree, INT_MIN, INT_MAX));
}
