/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	move_parallax(parralax_t *parralax)
{
	int max = parralax[0].nb_layer;
	int i = 0;
	int n = 0;
	sfVector2f pos;

	while (n < 2) {
		pos = sfSprite_getPosition(parralax[n].layers[i]);
		if (pos.x <= -1280)
			sfSprite_setPosition(parralax[n].layers[i],
			(sfVector2f){1280 - parralax[n].speed[i], 0});
		else
			sfSprite_move(parralax[n].layers[i], (sfVector2f){-parralax[n].speed[i], 0});
		i++;
		if (i == max) {
			n++;
			i = 0;
		}
	}
}
