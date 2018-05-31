/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

int	check_fb_col_with_block(ll_block_t *tmp_b, ll_fire_b_t *fire_ball, map_t *map)
{
		ll_fire_b_t *tmp_fb = fire_ball->next;
		sfVector2f fb_pos;
		sfVector2f b_pos = sfRectangleShape_getPosition(tmp_b->shp);
		block_type_t value;
		ll_fire_b_t *save;

		while (tmp_fb) {
			fb_pos = sfCircleShape_getPosition(tmp_fb->shp);
			value = check_colision_block(fb_pos, tmp_b, FB_SIZE);
			save = tmp_fb->next;
			if (value == OBSTACLE && tmp_b->resilience == BREAKABLE && tmp_b->status){
				tmp_b->status = 0;
				add_in_free_list(map->free_list, tmp_b->shp, tmp_b->free, tmp_b);
			}
			if (value == OBSTACLE && tmp_fb->status && tmp_b->resilience == UNBREAKABLE){
				tmp_fb->status = 0;
				add_in_free_list(map->free_list, tmp_fb->shp, tmp_fb->free, tmp_fb);
			}
			tmp_fb = save;
		}
		return (0);
}

void	check_fb_colision(map_t *map)
{
	ll_block_t *tmp_b = map->root->next;
	ll_block_t *save = tmp_b;

	while (tmp_b) {
		save = tmp_b->next;
		check_fb_col_with_block(tmp_b, map->fire_ball, map);
		tmp_b = save;
	}
}
