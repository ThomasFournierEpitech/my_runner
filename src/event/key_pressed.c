/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	key_pressed(win_t *win, map_t *map, hero_t *hero)
{
	if (win->evt.key.code == sfKeySpace) {
		hero->hero->speed.y = (-(hero->hunger / 100) * 5) - 6;
		sfMusic_play(win->wing.music);
		if (hero->hunger >= 66 && hero->hunger - 1.5 < 66) {
			sfSprite_setTexture(hero->hero->spt, hero->img_y, sfTrue);
			sfSprite_setTextureRect(hero->hero->spt, hero->hero->rect);
		}
		if (hero->hunger >= 33 && hero->hunger - 1.5 < 33) {
			sfSprite_setTexture(hero->hero->spt, hero->img_r, sfTrue);
			sfSprite_setTextureRect(hero->hero->spt, hero->hero->rect);
		}
		if (hero->hunger > 0)
			hero->hunger -= 1.5;
		hero->score -= 10;
	}
	return;
}
