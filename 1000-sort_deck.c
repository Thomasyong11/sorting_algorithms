#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

/**
 * compare_cards - Compare two cards
 * @card1: First card to compare
 * @card2: Second card to compare
 *
 * Return: Positive number if card1 > card2, negative number if card1 < card2,
 *         zero if card1 = card2
 */
int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = *(const card_t **)card1;
    const card_t *c2 = *(const card_t **)card2;

    int val1, val2;

    if (c1->kind != c2->kind)
        return (c1->kind - c2->kind);

    switch (c1->value[0])
    {
        case 'A':
            val1 = 1;
            break;
        case '1':
            val1 = 10;
            break;
        case 'J':
            val1 = 11;
            break;
        case 'Q':
            val1 = 12;
            break;
        case 'K':
            val1 = 13;
            break;
        default:
            val1 = c1->value[0] - '0';
            break;
    }

    switch (c2->value[0])
    {
        case 'A':
            val2 = 1;
            break;
        case '1':
            val2 = 10;
            break;
        case 'J':
            val2 = 11;
            break;
        case 'Q':
            val2 = 12;
            break;
        case 'K':
            val2 = 13;
            break;
        default:
            val2 = c2->value[0] - '0';
            break;
    }

    return (val1 - val2);
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    int i;
    deck_node_t *node = *deck;
    card_t *cards[52];

    for (i = 0; i < 52; i++)
    {
        cards[i] = (card_t *)node->card;
        node = node->next;
    }

    qsort(cards, 52, sizeof(card_t *), compare_cards);

    node = *deck;
    for (i = 0; i < 52; i++)
    {
        node->card = cards[i];
        node = node->next;
    }
}
