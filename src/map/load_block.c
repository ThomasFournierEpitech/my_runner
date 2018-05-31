/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	create_block(ll_block_t *root,
	sfRectangleShape *shp, block_type_t type,
	block_resilience_t resilience)
{
	ll_block_t *new = malloc(sizeof(*new));

	new->shp = shp;
	new->next = root->next;
	new->prev = root;
	new->type = type;
	new->resilience = resilience;
	new->free = &free_block;
	new->status = 1;
	if (root->next)
		root->next->prev = new;
	root->next = new;
}

ll_block_t	*create_root()
{
	ll_block_t *root = malloc(sizeof(*root));

	root->shp = NULL;
	root->next = NULL;
	root->prev = NULL;
	root->type = NOTHING;
	return (root);
}

void free_block(ll_block_t *block)
{
	if (!block)
		return;
	sfRectangleShape_destroy(block->shp);
	block->shp = NULL;
	if (block->next)
		block->next->prev = block->prev;
	if (block->prev)
		block->prev->next = block->next;
	free(block);
	block = NULL;
}

void	load_new_block(ll_block_t *root,
	int start, map_t *map)
{
	int i = 0;
	int j = start;
	char c = map->map[0][start];
	sfVector2f pos;
	sfIntRect rect;
	sfRectangleShape *shp = NULL;

	pos.x = WIDTH;
	while (i < map->h) {
		c = map->map[i][j];
		pos.y = i * SCALE;
		if (c == 'x') {
			rect = (sfIntRect){0, 0, 16, 16};
			shp = create_rectangle_shape(pos, (sfVector2f){SCALE,SCALE}, map->config.bloc);
			create_block(root, shp, OBSTACLE, UNBREAKABLE);
		}
		if (c == 'v') {
			rect = (sfIntRect){0, 0, 1, 1};
			shp = create_rectangle_shape(pos, (sfVector2f){SCALE,SCALE}, map->config.nothing);
			create_block(root, shp, OBSTACLE, UNBREAKABLE);
		}
		if (c == 'h') {
			rect = (sfIntRect){0, 0, 28, 28};
			shp = create_rectangle_shape(pos, (sfVector2f){SCALE,SCALE}, map->config.wings);
			create_block(root, shp, WINGS, UNBREAKABLE);
		}
		if (c == 'o') {
			rect = (sfIntRect){0, 0, 16, 16};
			shp = create_rectangle_shape(pos, (sfVector2f){SCALE,SCALE}, map->config.breakable);
			create_block(root, shp, OBSTACLE, BREAKABLE);
		}
		i++;
	}
}

void	load_ll_block(ll_block_t *root,
	int start, int height, map_t *map)
{
	int i = 0;
	int j = start;
	char c = map->map[0][start];
	sfVector2f pos;
	sfIntRect rect;
	sfRectangleShape *shp = NULL;

	while (i < map->h && j < map->w) {
		c = map->map[i][j];
		pos.x = j * SCALE;
		pos.y = i * SCALE;
		if (c == 'x') {
			rect = (sfIntRect){0, 0, 16, 16};
			shp = create_rectangle_shape(pos, (sfVector2f){SCALE,SCALE}, map->config.bloc);
			create_block(root, shp, OBSTACLE, UNBREAKABLE);
		}
		if (c == 'v') {
			rect = (sfIntRect){0, 0, 1, 1};
			shp = create_rectangle_shape(pos, (sfVector2f){SCALE,SCALE}, map->config.nothing);
			create_block(root, shp, OBSTACLE, UNBREAKABLE);
		}
		if (c == 'h') {
			rect = (sfIntRect){0, 0, 28, 28};
			shp = create_rectangle_shape(pos, (sfVector2f){SCALE,SCALE}, map->config.wings);
			create_block(root, shp, WINGS, UNBREAKABLE);
		}
		if (c == 'o') {
			rect = (sfIntRect){0, 0, 16, 16};
			shp = create_rectangle_shape(pos, (sfVector2f){SCALE,SCALE}, map->config.breakable);
			create_block(root, shp, OBSTACLE, BREAKABLE);
		}
		j++;
		if (j == height + start || j == map->w) {
			j = start;
			i++;
		}
	}
}
