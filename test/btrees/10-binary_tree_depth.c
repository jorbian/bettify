#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of node in binary tree.
 * @tree: Pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, returnw 0, else return the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
