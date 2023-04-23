#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 *
 * @list: Double pointer to the head node of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *start = *list, *end = NULL, *tmp = NULL;
    int swapped = 0;

    if (!list || !(*list) || !((*list)->next))
        return;

    do {
        swapped = 0;

        /* Traverse from left to right */
        while (start->next != end) {
            if (start->n > start->next->n) {
                tmp = start->next;
                start->next = tmp->next;
                if (tmp->next)
                    tmp->next->prev = start;
                tmp->prev = start->prev;
                tmp->next = start;
                if (start->prev)
                    start->prev->next = tmp;
                else
                    *list = tmp;
                start->prev = tmp;
                swapped = 1;
                print_list(*list);
            } else {
                start = start->next;
            }
        }

        /* If no swaps, list is already sorted */
        if (!swapped)
            break;

        swapped = 0;
        end = start;

        /* Traverse from right to left */
        while (start != NULL && start != end) {
            if (start->n < start->prev->n) {
                tmp = start->prev;
                start->prev = tmp->prev;
                if (tmp->prev)
                    tmp->prev->next = start;
                tmp->next = start->next;
                tmp->prev = start;
                if (start->next)
                    start->next->prev = tmp;
                start->next = tmp;
                swapped = 1;
                print_list(*list);
            } else {
                start = start->prev;
            }
        }

        start = end->prev;
    } while (swapped);
}
