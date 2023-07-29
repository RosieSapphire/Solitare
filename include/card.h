#ifndef CARD_H
#define CARD_H

#include <stdbool.h>

enum suit {
	SUIT_SPADE,
	SUIT_CLUB,
	SUIT_HEART,
	SUIT_DIAMOND,
	SUIT_COUNT,
};

typedef struct {
	enum suit suit;
	int num;
	bool is_visible;
} card;

void cards_init(void);
void card_draw(card c, int i);

#endif /* CARD_H */
