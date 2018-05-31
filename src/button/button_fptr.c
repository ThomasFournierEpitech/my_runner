/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void click(button_t *button)
{
	sfVector2f scale = {1.05, 1.05};
	sfVector2f scale_text = {1.15, 1.15};
	sfText_setScale(button->text, scale_text);
	sfRectangleShape_setScale(button->shp, scale);
	button->selected = sfTrue;
	return;
}

void pass_over(button_t *button)
{
	sfText_setColor(button->text, sfYellow);
	sfText_setScale(button->text, (sfVector2f){1, 1});
	sfRectangleShape_setScale(button->shp, (sfVector2f){1, 1});
	return;
}

void reset_button(button_t *button)
{
	sfText_setScale(button->text, (sfVector2f){1, 1});
	sfRectangleShape_setScale(button->shp, (sfVector2f){1, 1});
	sfText_setColor(button->text, sfWhite);
	button->selected = sfFalse;
}

void restart_game(win_t *win)
{
	win->state = -42;
}

void infinity_game(win_t *win)
{
	win->state = -84;
}


void exit_cb(win_t *win)
{
	sfRenderWindow_close(win->win);
}

void fptr_nothing(void *win)
{
	return;
}
