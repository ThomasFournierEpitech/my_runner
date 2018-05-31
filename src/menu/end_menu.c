/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	end_menu(win_t *win, menu_t *menu, hero_t *hero)
{
	sfColor c;
	sfRenderWindow_clear(win->win, sfBlack);
	while (sfRenderWindow_pollEvent(win->win, &win->evt)) {
		test_hitbox(menu[WIN].button_list, sfMouse_getPositionRenderWindow(win->win), win);
		if (win->evt.type == sfEvtClosed)
			sfRenderWindow_close(win->win);
		if (win->evt.type == sfEvtMouseButtonPressed) {
			test_click(menu[WIN].button_list,
			sfMouse_getPositionRenderWindow(win->win), win);
		}
		if (win->evt.type == sfEvtMouseButtonReleased) {
			test_declick(menu[WIN].button_list,
			sfMouse_getPositionRenderWindow(win->win), win);
		}
	}
	manage_button(menu[WIN].button_list, win);
	draw_buttons(menu[WIN].button_list, win);
	c = (hero->victory == sfTrue) ? sfGreen : sfRed;
	edit_text(c, (sfVector2f){540, 100},
	"SCORE", menu[WIN].text);
	sfText_setCharacterSize(menu[WIN].text, 30);
	sfRenderWindow_drawText(win->win, menu[WIN].text, NULL);
	edit_text(sfYellow, (sfVector2f){650, 80},
	my_getstr(hero->score), menu[WIN].text);
	sfText_setCharacterSize(menu[WIN].text, 50);
	sfRenderWindow_drawText(win->win, menu[WIN].text, NULL);
	sfRenderWindow_display(win->win);
}
