/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	refresh_fire_ball(ll_fire_b_t *tmp, map_t *map)
{
	sfVector2f pos;

	sfCircleShape_move((tmp)->shp, (sfVector2f){tmp->speed.x, tmp->speed.y});
	pos = sfCircleShape_getPosition((tmp)->shp);
	if ((pos.x + 10 < 0 || pos.x > WIDTH || pos.y + 10 > HEIGHT - SCALE || pos.y < 0 + SCALE) && tmp->status) {
		tmp->status = 0;
		add_in_free_list(map->free_list, tmp->shp, tmp->free, tmp);
	}

}

void	move_fireball(map_t *map)
{
	int i = 1;
	int j = 0;
	ll_fire_b_t *tmp = map->fire_ball->next;

	while (tmp) {
		refresh_fire_ball(tmp, map);
		tmp = tmp->next;
	}
}
