#include "sort.h"
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *                     order using the Cocktail shaker sort algorithm
 *
 * @list: doubly linked list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	listint_t *left = *list, *right = *list, *cur = NULL, *tmp = NULL;
	
	while (right->next != NULL)
		right = right->next;
	while (left != right) 
	{
		for (cur = left; cur != right; cur = cur->next) 
		{
			if (cur->n > cur->next->n) 
			{
				tmp = cur->next;
				if (cur->prev != NULL)
					cur->prev->next = tmp;
				else
					*list = tmp;
				tmp->prev = cur->prev;
				cur->next = tmp->next;
				if (tmp->next != NULL)
					tmp->next->prev = cur;
				cur->prev = tmp;
				tmp->next = cur;
				print_list(*list);
			}
		}
		right = cur = cur->prev;
		for (; cur != left; cur = cur->prev) 
		{
			if (cur->n < cur->prev->n) 
			{
				tmp = cur->prev;
				if (cur->next != NULL)
					cur->next->prev = tmp;
				else
					(*list)->prev = tmp;
				tmp->next = cur->next;
				cur->prev = tmp->prev;
				if (tmp->prev != NULL)
					tmp->prev->next = cur;
				else
					*list = cur;
				tmp->prev = cur;
				cur->next = tmp;
				print_list(*list);
			}
		}
		left = cur = cur->next;
	}
}

listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list = NULL, *node = NULL;
	
	while (size-- > 0) 
	{
		node = malloc(sizeof(listint_t));
		if (node == NULL)
			return (NULL);
		node->n = array[size];
		node->prev = NULL;
		node->next = list;
		if (list != NULL)
			list->prev = node;
		list = node;
	}
	return (list);
}

void print_list(const listint_t *list)
{
	if (list == NULL)
		return;
	while (list->prev != NULL)
		list = list->prev;
	printf("%d", list->n);
	while (list->next != NULL) 
	{
		list = list->next;
		printf(", %d", list->n);
	}
	printf("\n");
}
