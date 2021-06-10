#include "sort.h"

/**
 * insertion_sort_list - is a simple sorting algorithm
 * that builds the final sorted array (or list) one item at a time.
 * @list: Pointer to the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = (*list)->next;
	listint_t *next_node = NULL;

	if (list == NULL)
		return;

	while (node)
	{
		next_node = node->next;

		while (node->prev && node->n < node->prev->n)
		{
			node->prev->next = node->next;

			if (node->next)
				node->next->prev = node->prev;

			node->next = node->prev;
			node->prev = node->next->prev;
			node->next->prev = node;

			if (node->prev == NULL)
				*list = node;

			else
				node->prev->next = node;

			print_list(*list);
		}
		node = next_node;
	}
}
