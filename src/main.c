#include "window.h"
#include "card_stack.h"

int main(void)
{
	window_init();

	cards_init();
	card_stack stacks[7];
	for(int i = 0; i < 7; i++)
		stacks[i] = card_stack_create(i + 1, i);

	while(window_is_running()) {
		window_clear((rgba_t){0, 0, 0, 1});
		for(int i = 0; i < 7; i++)
			card_stack_draw(stacks[i]);

		window_display();
	}

	window_terminate();

	return 0;
}
