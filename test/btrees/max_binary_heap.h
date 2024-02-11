#ifndef MAX_BINARY_HEAP_H
#define MAX_BINARY_HEAP_H

#include "binary_trees.h"

typedef struct binary_tree_s heap_t;

int binary_tree_is_heap(const binary_tree_t *tree);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);

#endif
