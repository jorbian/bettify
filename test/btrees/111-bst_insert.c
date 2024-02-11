#include "binary_trees.h"

/**
 * calculate_dest - calculate if the new node goes to the left or the right
 * (or neither, i.e. NULL)
 * @curr_node: the current root node
 * @new_val: the value for the new node that's about to be created
 *
 * Return: A pointer to the node the new one will be attatched to.
*/
static bst_t *calculate_dest(bst_t *curr_node, int new_val)
{
	if (curr_node == NULL)
		return (NULL);

	if (new_val < curr_node->n)
		return (curr_node->left);
	else
		return (curr_node->right);
}

/**
 * place_node - actually put the node wherever it ultimately goes
 * @parent: the parent node we're adding a left or right node to
 * @val: the value for the new node
 * @dest: which it's supposed to be
 *
 * Return: A pointer to the new node
*/
static bst_t *place_node(bst_t *parent, int val, bst_t *dest)
{
	binary_tree_t *new;

	new = binary_tree_node(parent, val);
		if (new == NULL)
			return (NULL);

	return (dest = new);
}
/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *destination;

	if (tree == NULL)
		return (NULL);

	destination = calculate_dest(*tree, value);

	if (destination != NULL)
		return (bst_insert(&destination, value));

	return (place_node(*tree, value, destination));
}
