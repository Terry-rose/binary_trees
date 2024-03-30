#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes,
 *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *temp1 = first, *temp2 = second;

    if (first == NULL || second == NULL)
        return (NULL);

    while (temp1 != temp2)
    {
        temp1 = (temp1 == NULL) ? second : temp1->parent;
        temp2 = (temp2 == NULL) ? first : temp2->parent;
    }

    return ((binary_tree_t *)temp1);
}

