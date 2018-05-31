/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

config_t	create_config()
{
	config_t new;
	sfIntRect rect;

	rect = (sfIntRect){0, 0, 16, 16};
	new.bloc = sfTexture_createFromFile("img/bloc.png", &rect);
	new.breakable = sfTexture_createFromFile("img/breakable.png", &rect);
	rect = (sfIntRect){0, 0, 28, 28};
	new.wings = sfTexture_createFromFile("img/feather.png", &rect);
	rect = (sfIntRect){0, 0, 1, 1};
	new.nothing = sfTexture_createFromFile("img/feather.png", &rect);
	rect = (sfIntRect){0, 0, 17, 17};
	new.fireball = sfTexture_createFromFile("img/fireball.png", &rect);
	return (new);
}
