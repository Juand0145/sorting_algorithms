#include "sort.h"

/**
 * swap - Function that allow us to swap the nodes
 * @list: Pointer to the list that its being sorted
 * @node: The position of the node to swap
 */
void swap(listint_t **list, listint_t *node)
{
	listint_t *node_next = node->next;
	listint_t *node_prev = node->prev;

	node_next->prev = node->prev;

	if (node_prev != NULL)
		node_prev->next = node_next;

	else
		*list = node_next;

	node->prev = node_next;
	node->next = node_next->next;
	node->prev->next = node;

	node_next = node->next;
	node_prev = node->prev;

	if (node_next != NULL)
		node_next->prev = node;
}

/**
 * cocktail_sort_list - ] also known as bidirectional bubble sort,
 * cocktail sort, shaker sort (which can also refer to a variant of
 * selection sort), ripple sort, shuffle sort, or shuttle sort, is an
 * extension of bubble sort.
 * @list: The list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int loop = 1;
	listint_t *node = *list;

	if (!list || (!*list))
		return;

	while (loop)
	{
		loop = 0;
		while (node->next != NULL)
		{
			if (node->next->n < node->n)
			{
				swap(list, node);
				loop = 1;
				print_list(*list);
			}
			else
				node = node->next;
		}
		if (loop == 0)
			break;
		loop = 0;
		while (node->prev != NULL)
		{
			if (node->prev->n > node->n)
			{
				swap(list, node->prev);
				loop = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
