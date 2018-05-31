/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	create_fire_ball(ll_fire_b_t *root, sfCircleShape *shp,
	sfVector2f speed)
{
	ll_fire_b_t *new = malloc(sizeof(*new));

	new->shp = shp;
	new->next = root->next;
	new->prev = root;
	new->speed = speed;
	new->free = &free_fire_ball;
	new->status = 1;
	if (root->next)
		root->next->prev = new;
	root->next = new;
}

ll_fire_b_t	*create_fire_ball_root()
{
	ll_fire_b_t *root = malloc(sizeof(*root));

	root->shp = NULL;
	root->next = NULL;
	root->prev = NULL;
	root->clock.clock = sfClock_create();
	return (root);
}

void	free_fire_ball(ll_fire_b_t *block)
{
	if (block->next)
		block->next->prev = block->prev;
	if (block->prev)
		block->prev->next = block->next;
	free(block);
}

void	generate_fire_ball(map_t *map, hero_t *hero, sfVector2i mouse_pos)
{
	sfVector2f pos = sfSprite_getPosition(hero->hero->spt);
	sfVector2f speed = {1, 0};
	sfCircleShape *shp = NULL;
	float m = 0;
	float distance = 0;
	sfVector2f vec = {mouse_pos.x - pos.x, mouse_pos.y - pos.y};

	distance = sqrtf(powf(vec.x, 2) + powf(vec.y, 2));
	if (distance == 0)
		return;
	speed.x = (vec.x / distance) * 15;
	speed.y = (vec.y / distance) * 15;
	shp = create_circle_shape(pos, FB_SIZE / 2, map->config.fireball);
	create_fire_ball(map->fire_ball, shp, speed);
}
