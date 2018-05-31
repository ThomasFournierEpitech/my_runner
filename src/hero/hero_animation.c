/*
** EPITECH PROJECT, 2017
** open_a_herodow
** File description:
** 1st function
*/

#include "include.h"

void	hero_animation(obj_t *hero, map_t *map)
{
	hero->clock.time = sfClock_getElapsedTime(hero->clock.clock);
	hero->clock.sec = hero->clock.time.microseconds / 1000000.0;
	if (hero->clock.sec <= 0.17)
		return;
	hero->rect.left += hero->offset.x;
	if (hero->rect.left == 240)
		hero->rect.left = 0;
	sfSprite_setTextureRect(hero->spt, hero->rect);
	sfClock_restart(hero->clock.clock);
	return;
}
