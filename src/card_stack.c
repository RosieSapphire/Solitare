#include "card_stack.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

card_stack card_stack_create(int num_cards)
{
	card_stack stack;
		
	stack.num_cards = num_cards;
	stack.cards = malloc(sizeof(card) * num_cards);
	for(int i = 0; i < num_cards; i++) {
		enum suit s = rand() % 4;
		int n = 1 + (rand() % 10);
		stack.cards[i] = (card){s, n, true};
	}

	return stack;
}

void card_stack_draw(card_stack s)
{
	for(unsigned int i = 0; i < s.num_cards; i++)
		card_draw(s.cards[i], i);
}
