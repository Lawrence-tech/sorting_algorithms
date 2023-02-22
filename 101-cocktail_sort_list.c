#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 *                     in ascending order using the Cocktail shaker sort
 *                     algorithm
 * @list: doubly linked list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right, *curr;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	left = *list;
	right = *list;
	curr = *list;
	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		while (right->next != NULL)
		{
			if (right->n > right->next->n)
			{
				if (right == *list)
					*list = right->next;
				swap_nodes(right, right->next, list);
				swapped = 1;
				print_list(*list);
			}
			else
				right = right->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (left->prev != NULL)
		{
			if (left->n < left->prev->n)
			{
				if (left == *list)
					*list = left->prev;
				swap_nodes(left->prev, left, list);
				swapped = 1;
				print_list(*list);
			}
			else
				left = left->prev;
		}
		curr = curr->prev;
		right = curr;
		left = curr;
        }
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @node1: first node to swap
 * @node2: second node to swap
 * @list: pointer to the list
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *prev_node1, *prev_node2, *next_node1, *next_node2;

	prev_node1 = node1->prev;
	prev_node2 = node2->prev;
	next_node1 = node1->next;
	next_node2 = node2->next;

	if (prev_node1 != NULL)
		prev_node1->next = node2;
	if (next_node2 != NULL)
		next_node2->prev = node1;

	node1->prev = node2;
	node2->next = node1;
	node2->prev = prev_node1;
	node1->next = next_node2;

	if (prev_node2 == node1)
		prev_node2 = node2;
	else if (prev_node2 != NULL)
		prev_node2->next = node1;

	if (next_node1 == node2)
		next_node1 = node1;
	else if (next_node1 != NULL)
		next_node1->prev = node2;

	node1->prev = prev_node2;
	node2->next = next_node1;

	if (*list == node1)
		*list = node2;
	else if (*list == node2)
		*list = node1;
}

