#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "binary_trees.h"

typedef struct binary_tree_s avl_t;

avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);

#endif
