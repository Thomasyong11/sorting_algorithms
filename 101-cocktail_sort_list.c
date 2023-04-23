#include "sort.h"
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *                     order using the Cocktail shaker sort algorithm
 *
 * @list: doubly linked list of integers
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;

		for (temp = *list; temp->next != NULL; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				temp->next->prev = temp->prev;
				if (temp->prev)
					temp->prev->next = temp->next;
				else
					*list = temp->next;
				temp->prev = temp->next;
				temp->next = temp->next->next;
				temp->prev->next = temp;
				if (temp->next)
					temp->next->prev = temp;
				swapped = 1;
				print_list(*list);
			}
		}
		if (swapped == 0)
			break;

		swapped = 0;

		for (temp = temp->prev; temp->prev != NULL; temp = temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				temp->prev->next = temp->next;
				if (temp->next)
					temp->next->prev = temp->prev;
				temp->next = temp->prev;
				temp->prev = temp->prev->prev;
				temp->next->prev = temp;
				if (temp->prev)
					temp->prev->next = temp;
				else
					*list = temp;
				swapped = 1;
				print_list(*list);
			}
		}
		} while (swapped);
}
