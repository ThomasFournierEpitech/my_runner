/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	init_menu(win_t *win, menu_t *menu, hero_t *hero)
{
	int i = 0;

	init_start_menu(win, menu);
	init_game_menu(win, menu, hero);
	init_end_menu(win, menu);
}
