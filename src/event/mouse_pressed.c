/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	mouse_pressed_game(win_t *win, map_t *map)
{
	map->fire_b_gen = sfTrue;
}

void	mouse_pressed(win_t *win, map_t *map)
{
	if (win->state == 1)
		mouse_pressed_game(win, map);
}
