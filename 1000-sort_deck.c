#include "deck.h"
#include <stdlib.h>
#include <string.h>

int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = (*(deck_node_t **)card1)->card;
    const card_t *c2 = (*(deck_node_t **)card2)->card;

    if (c1->kind != c2->kind)
        return (c1->kind - c2->kind);

    return (strcmp(c1->value, c2->value));
}

void sort_deck(deck_node_t **deck)
{
    size_t i;
    deck_node_t *node;
    deck_node_t **nodes;

    if (!deck || !*deck || !(*deck)->next)
        return;

    nodes = malloc(sizeof(*nodes) * 52);
    if (!nodes)
        return;

    for (i = 0, node = *deck; node; node = node->next, i++)
        nodes[i] = node;

    qsort(nodes, 52, sizeof(*nodes), compare_cards);

    for (i = 0; i < 52; i++)
    {
        nodes[i]->prev = i == 0 ? NULL : nodes[i - 1];
        nodes[i]->next = i == 51 ? NULL : nodes[i + 1];
    }

    *deck = nodes[0];
    free(nodes);
}
