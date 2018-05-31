/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

sfRectangleShape *create_rectangle_shape(sfVector2f pos,
	sfVector2f size, sfTexture *texture)
{
	sfRectangleShape *shp = sfRectangleShape_create();

	sfRectangleShape_setTexture(shp, texture, sfTrue);
	sfRectangleShape_setPosition(shp, pos);
	sfRectangleShape_setSize(shp, size);
	return (shp);
}

sfCircleShape *create_circle_shape(sfVector2f pos,
	float size, sfTexture *texture)
{
	sfCircleShape *shp = sfCircleShape_create();

	sfCircleShape_setTexture(shp, texture, sfTrue);
	sfCircleShape_setPosition(shp, pos);
	sfCircleShape_setRadius(shp, size);
	return (shp);
}
