/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	set_menu(win_t *win, menu_t *menu)
{
	menu[WIN].font = sfFont_createFromFile("img/font.ttf");
	menu[WIN].spt = sfSprite_create();
	menu[WIN].speed = 0;
	menu[WIN].img = sfTexture_createFromFile("img/menu.png", NULL);
	menu[WIN].rect = (sfIntRect){0, 0, WIDTH, HEIGHT};
	menu[WIN].pos.x = 0;
	menu[WIN].pos.y = 0;
	menu[WIN].offset = 0;
	menu[WIN].clock.clock = sfClock_create();
	menu[WIN].text = sfText_create();
	menu[WIN].button_list = create_button_ll();
	sfText *text = sfText_create();
	sfText_setFont(menu[WIN].text, menu[WIN].font);
}

void	set_button_exit(win_t *win, menu_t *menu,
	sfVector2f b_pos, sfVector2f size)
{
	button_t button;

	button = create_button(sfTexture_createFromFile("img/button.png", NULL),
	b_pos, size, &exit_cb);
	button.text = create_exit_text(menu[WIN].font, b_pos, size, "EXIT");
	button.hitbox = (sfIntRect){b_pos.x, b_pos.y, b_pos.x + size.x, b_pos.y + size.y};
	button.pass_over = (void *)&pass_over;
	button.click = (void *)&click;
	add_button_in_list(&menu[WIN].button_list, button);
}

void	set_button_restart(win_t *win, menu_t *menu,
	sfVector2f b_pos, sfVector2f size)
{
	button_t button;

	button = create_button(sfTexture_createFromFile("img/button.png", NULL),
	b_pos, size, &restart_game);
	button.text = create_restart_text(menu[WIN].font, b_pos, size, "RESTART");
	button.hitbox = (sfIntRect){b_pos.x, b_pos.y, b_pos.x + size.x, b_pos.y + size.y};
	button.pass_over = (void *)&pass_over;
	button.click = (void *)&click;
	add_button_in_list(&menu[WIN].button_list, button);
}

void	set_background(win_t *win, menu_t *menu)
{
	button_t button;

	button = create_button(menu[WIN].img,
	(sfVector2f){0, 0}, (sfVector2f){WIDTH, HEIGHT}, &fptr_nothing);
	button.hitbox = (sfIntRect){0, 0, WIDTH, HEIGHT};
	add_button_in_list(&menu[WIN].button_list, button);
}

void	set_button_infinity(win_t *win, menu_t *menu,
	sfVector2f b_pos, sfVector2f size)
{
	button_t button;

	button = create_button(sfTexture_createFromFile("img/button.png", NULL),
	b_pos, size, &infinity_game);
	button.text = create_restart_text(menu[WIN].font, b_pos, size, "INFINITY");
	button.hitbox = (sfIntRect){b_pos.x, b_pos.y, b_pos.x + size.x, b_pos.y + size.y};
	button.pass_over = (void *)&pass_over;
	button.click = (void *)&click;
	add_button_in_list(&menu[WIN].button_list, button);
}

void	init_end_menu(win_t *win, menu_t *menu)
{
	button_t button;
	sfVector2f b_pos = {500, 600};
	sfVector2f size = {300, 80};

	set_menu(win, menu);
	set_button_exit(win, menu, b_pos, size);
	b_pos.y -= 350;
	set_button_restart(win, menu, b_pos, size);
	b_pos.y += 100;
	set_button_infinity(win, menu, b_pos, size);
	set_background(win, menu);
}
