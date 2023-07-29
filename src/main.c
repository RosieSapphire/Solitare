#include "window.h"
#include "card_stack.h"

int main(void)
{
	window_init();

	cards_init();
	card_stack stack_test = card_stack_create(5);

	while(window_is_running()) {
		window_clear((rgba_t){0, 0, 0, 1});
		card_stack_draw(stack_test);
		window_display();
	}

	window_terminate();

	return 0;
}
