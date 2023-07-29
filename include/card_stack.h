#ifndef CARD_STACK_H
#define CARD_STACK_H

#include "card.h"

typedef struct {
	unsigned int num_cards;
	card *cards;
} card_stack;

card_stack card_stack_create(int num_cards);
void card_stack_draw(card_stack s);

#endif /* CARD_STACK_H */
