#include "binary_trees.h"

/**
 * get_right - retrieve the right hand child node
 * @node: pointer to the node that's being looked at
 *
 * Return: A double pointer to the node on the side needed
*/
static binary_tree_t **get_right(binary_tree_t *node)
{
	return (&(node->right));
}

/**
 * insert_node - insert a node on the right or the right slot of the parent
 * @parent: the parent node being added to
 * @value: the value that will be stored in the new node.
 * @get_side: function pointer to the function that will dereference
 * needed side on parent node.
 *
 * Return: Pointer to the newly added node.
*/
static binary_tree_t *insert_node(
	binary_tree_t *parent, int value,
	binary_tree_t **(*get_side)(binary_tree_t *)
)
{
	binary_tree_t *new, *temp;
	binary_tree_t **parent_side;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	parent_side = get_side(parent);
	temp = *parent_side;

	if (temp != NULL)
		temp->parent = new;

	*parent_side = new;

	return (new);
}

/**
 * binary_tree_insert_right - insert a new node on a binary tree on right
 * @parent: parent node to the tree being added to
 * @value: the value of the new node
 *
 * Return: A pointer to the new node that was just added.
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	return (insert_node(parent, value, get_right));
}
