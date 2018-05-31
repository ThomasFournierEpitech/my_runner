/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

sfVector2f exit_pos(sfVector2f b_pos)
{
	sfVector2f pos = b_pos;

	sfVector2f offset = {119, 16};

	pos.x += offset.x;
	pos.y += offset.y;
	return (pos);
}

sfText *create_exit_text(sfFont *font, sfVector2f b_pos, sfVector2f size, char *str)
{
	sfText *text = sfText_create();
	sfVector2f pos;
	int c_size = 30;

	sfText_setFont(text, font);
	sfText_setColor(text, sfWhite);
	sfText_setString(text, str);
	pos = exit_pos(b_pos);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, 30);
	return (text);
}


sfVector2f restart_pos(sfVector2f b_pos)
{
	sfVector2f pos = b_pos;

	sfVector2f offset = {92, 16};

	pos.x += offset.x;
	pos.y += offset.y;
	return (pos);
}

sfText *create_restart_text(sfFont *font, sfVector2f b_pos,
sfVector2f size, char *str)
{
	sfText *text = sfText_create();
	sfVector2f pos;
	int c_size = 30;

	sfText_setFont(text, font);
	sfText_setColor(text, sfWhite);
	sfText_setString(text, str);
	pos = restart_pos(b_pos);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, 30);
	return (text);
}
