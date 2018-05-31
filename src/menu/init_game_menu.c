/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	init_game_menu(win_t *win, menu_t *menu, hero_t *hero)
{
	button_t button;

	menu[GAME].font = sfFont_createFromFile("img/font.ttf");
	menu[GAME].spt = sfSprite_create();
	menu[GAME].speed = 0;
	menu[GAME].img = sfTexture_createFromFile("img/menu.png", NULL);
	menu[GAME].rect = (sfIntRect){0, 0, WIDTH, HEIGHT};
	menu[GAME].pos.x = 0;
	menu[GAME].pos.y = 0;
	menu[GAME].offset = 0;
	menu[GAME].clock.clock = sfClock_create();
	menu[GAME].text = sfText_create();
	menu[GAME].button_list = create_button_ll();
	sfText_setString(menu[GAME].text, my_getstr(hero->score));
	sfText_setFont(menu[GAME].text, menu[GAME].font);
	sfText_setCharacterSize(menu[GAME].text, 40);
	sfText_setColor(menu[GAME].text, sfYellow);
	sfText_setPosition(menu[GAME].text, (sfVector2f){25, HEIGHT - 100});
}
