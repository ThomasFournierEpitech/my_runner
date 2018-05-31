/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	edit_text(sfColor c, sfVector2f pos, char *str, sfText *text)
{
	sfText_setColor(text, c);
	sfText_setPosition(text, pos);
	sfText_setString(text, str);
}

void	start_menu(win_t *win, menu_t *menu) {
	sfRenderWindow_clear(win->win, sfBlack);
	while (sfRenderWindow_pollEvent(win->win, &win->evt)) {
		test_hitbox(menu[0].button_list, sfMouse_getPositionRenderWindow(win->win), win);
		if (win->evt.type == sfEvtClosed)
			sfRenderWindow_close(win->win);
		if (win->evt.type == sfEvtKeyPressed){
			win->state = 1;
			return;
		}
	}
	manage_button(menu[START].button_list, win);
	draw_buttons(menu[START].button_list, win);
	sfRenderWindow_drawText(win->win, menu[START].text, NULL);
	sfRenderWindow_display(win->win);
}

void go_to_menu(win_t *win, menu_t *menu, hero_t *hero) {
	switch(win->state) {
		case 2:
			start_menu(win, menu);
			break;
		case 3:
			end_menu(win, menu, hero);
			break;
		case 4:
			end_menu(win, menu, hero);
			break;
		default:
			start_menu(win, menu);
			break;
	}
}
