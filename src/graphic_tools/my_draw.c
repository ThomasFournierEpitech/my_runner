/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	draw_obj(ll_block_t *root, win_t *win)
{
	int i = 0;
	int j = 0;
	sfRectangleShape *shp = NULL;
	ll_block_t *tmp = root->next;

	while (tmp) {
		shp = tmp->shp;
		if (shp) {
			sfRenderWindow_drawRectangleShape(win->win, shp, NULL);
		}
		tmp = tmp->next;
	}
}

void	draw_fire_ball(ll_fire_b_t *root, win_t *win)
{
	int i = 0;
	int j = 0;
	sfCircleShape *shp = NULL;
	ll_fire_b_t *tmp = root->next;

	while (tmp) {
		shp = tmp->shp;
		if (shp) {
			sfRenderWindow_drawCircleShape(win->win, shp, NULL);
		}
		tmp = tmp->next;
	}
}

void	my_draw(win_t *win, map_t *map, obj_t *hero, menu_t *menu)
{
	int i = 0;
	int max = map->parralax[0].nb_layer;

	while (i < max) {
		sfRenderWindow_drawSprite(win->win, map->parralax[0].layers[i], NULL);
		sfRenderWindow_drawSprite(win->win, map->parralax[1].layers[i], NULL);
		i++;
	}
	draw_fire_ball(map->fire_ball, win);
	sfRenderWindow_drawSprite(win->win, hero->spt, NULL);
	draw_obj(map->root, win);
	sfRenderWindow_drawText(win->win, menu[GAME].text, NULL);
	return;
}
