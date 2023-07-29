#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>
#include "color.h"

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

void window_init(void);
void window_set_is_running(bool is_running);
bool window_is_running(void);
bool window_mouse_down_left(void);
bool window_mouse_down_right(void);
void window_mouse_pos_get(int *out);
void window_clear(rgba_t c);
void window_display(void);
void window_terminate(void);

#endif
