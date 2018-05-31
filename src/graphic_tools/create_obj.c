/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

obj_t	*create_obj(obj_t *obj, char *path, sfVector2f pos, sfIntRect rect)
{
	obj = malloc(sizeof(*obj));
	obj->spt = sfSprite_create();
	obj->img = sfTexture_createFromFile(path, NULL);
	obj->rect = rect;
	obj->pos = pos;
	sfSprite_setPosition(obj->spt, obj->pos);
	sfSprite_setTexture(obj->spt, obj->img, sfTrue);
	sfSprite_setTextureRect(obj->spt, obj->rect);
	return (obj);
}
