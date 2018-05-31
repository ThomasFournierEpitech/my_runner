/*
** EPITECH PROJECT, 2017
** rush1
** File description:
**
*/

#ifndef MENU_H_
#define MENU_H_

int	lose_menu(win_t *win, menu_t *menu);
void	end_menu(win_t *win, menu_t *menu, hero_t *hero);
void	init_menu(win_t *win, menu_t *menu, hero_t *hero);
void	init_start_menu(win_t *win, menu_t *menu);
void	init_end_menu(win_t *win, menu_t *menu);
void	init_game_menu(win_t *win, menu_t *menu, hero_t *hero);

#endif
