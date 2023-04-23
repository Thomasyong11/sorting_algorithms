#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 *                      in ascending order using the Cocktail shaker sort
 *                      algorithm.
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 0;
    listint_t *p, *q, *r;

    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;
        for (p = *list; p->next != NULL; p = p->next) {
            if (p->n > p->next->n) {
                q = p->next;
                r = q->next;

                if (p->prev != NULL)
                    p->prev->next = q;
                else
                    *list = q;

                q->prev = p->prev;
                q->next = p;
                p->prev = q;
                p->next = r;

                if (r != NULL)
                    r->prev = p;

                swapped = 1;
                print_list(*list);
            }
        }
        if (swapped == 0)
            break;
        swapped = 0;
        for (p = p->prev; p->prev != NULL; p = p->prev) {
            if (p->n < p->prev->n) {
                q = p->prev;
                r = q->prev;

                if (r != NULL)
                    r->next = p;
                else
                    *list = p;

                p->prev = r;
                p->next = q;
                q->prev = p;
                q->next = r;

                if (r != NULL)
                    r->prev = q;

                swapped = 1;
                print_list(*list);
            }
        }
    } while (swapped);
}
