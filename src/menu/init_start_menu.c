/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void play_cb(win_t *win)
{
	printf("oui\n");
	win->state = 1;
}

void	init_start_menu(win_t *win, menu_t *menu)
{
	button_t button;

	menu[START].font = sfFont_createFromFile("img/font.ttf");
	menu[START].spt = sfSprite_create();
	menu[START].speed = 0;
	menu[START].img = sfTexture_createFromFile("img/menu.png", NULL);
	menu[START].rect = (sfIntRect){0, 0, WIDTH, HEIGHT};
	menu[START].pos.x = 0;
	menu[START].pos.y = 0;
	menu[START].offset = 0;
	menu[START].clock.clock = sfClock_create();
	menu[START].text = sfText_create();
	menu[START].button_list = create_button_ll();
	button = create_button(menu[START].img,
	(sfVector2f){0, 0}, (sfVector2f){WIDTH, HEIGHT}, &play_cb);
	button.hitbox = (sfIntRect){0, 0, WIDTH, HEIGHT};
	add_button_in_list(&menu[START].button_list, button);
	sfText_setString(menu[START].text, "Press any key to play");
	sfText_setFont(menu[START].text, menu[START].font);
	sfText_setCharacterSize(menu[START].text, 50);
	sfText_setColor(menu[START].text, sfYellow);
	sfText_setPosition(menu[START].text, (sfVector2f){450, 100});
}
