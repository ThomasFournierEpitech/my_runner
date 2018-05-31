/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	update_score(win_t *win, map_t *map, hero_t *hero, menu_t *menu)
{
	hero->score += map->speed / 10;
	sfText_setString(menu[GAME].text, my_getstr(hero->score));
	sfClock_restart(win->time.clock);
}

void	refresh_block(ll_block_t *tmp, map_t *map)
{
	sfVector2f pos;

	sfRectangleShape_move((tmp)->shp, (sfVector2f){-map->speed, 0});
	pos = sfRectangleShape_getPosition((tmp)->shp);
	if (pos.x + SCALE < 0 && tmp->status) {
		tmp->status = 0;
		add_in_free_list(map->free_list, tmp->shp, tmp->free, tmp);
	}
}

void	move_block(map_t *map)
{
	int i = 1;
	int j = 0;
	ll_block_t *tmp = map->root->next;
	ll_block_t *save = NULL;

	while (tmp) {
		save = tmp->next;
		refresh_block(tmp, map);
		tmp = save;
	}
}

void	waiting_screen(map_t *map, hero_t *hero, win_t *win, menu_t *menu)
{
	my_draw(win, map, hero->hero, menu);
	sfRenderWindow_display(win->win);
	sfClock_restart(win->clock.clock);
	win->clock.time = sfClock_getElapsedTime(win->clock.clock);
	win->clock.sec = win->clock.time.microseconds / 1000000.0;
	while (win->clock.sec < 1.2) {
		win->clock.time = sfClock_getElapsedTime(win->clock.clock);
		win->clock.sec = win->clock.time.microseconds / 1000000.0;
	}
	while (sfRenderWindow_pollEvent(win->win, &win->evt));
}

block_type_t check_colision_block(sfVector2f pos, ll_block_t *tmp, float offset)
{
	sfVector2f pos_bloc = sfRectangleShape_getPosition(tmp->shp);
	int i = 0;
	int j = 0;

	while (i < 2) {
		if (pos.x + j * offset > pos_bloc.x && pos.x + j * offset < pos_bloc.x + SCALE &&
			pos.y + i * offset > pos_bloc.y && pos.y + i * offset < pos_bloc.y + SCALE)
				return (tmp->type);
		j++;
		if (j == 2) {
			i++;
			j = 0;
		}
	}
	return (NOTHING);
}

int	check_colision(map_t *map, hero_t *hero, win_t *win, menu_t *menu)
{
	ll_block_t *tmp = map->root->next;
	block_type_t value;
	int i = 0;
	int j = 0;
	sfVector2f pos = {(hero->hero->pos.x - 10),
	(hero->hero->pos.y - 10)};

	while (tmp) {
		value = check_colision_block(pos, tmp, 20);
		if (value != NOTHING)
			break;
		tmp = tmp->next;
	}
	switch (value) {
		case NOTHING:
			break;
		case OBSTACLE:
			win->state = 4;
			hero->victory = sfFalse;
			waiting_screen(map, hero, win, menu);
			return (1);
		case END:
			win->state = 3;
			hero->victory = sfTrue;
			waiting_screen(map, hero, win, menu);
			return (1);
		case WINGS:
			hero->hunger = 100;
			sfSprite_setTexture(hero->hero->spt, hero->img_b, sfTrue);
			sfSprite_setTextureRect(hero->hero->spt, hero->hero->rect);
			if (tmp->status) {
				tmp->status = 0;
				add_in_free_list(map->free_list, tmp->shp, tmp->free, tmp);
			}
			hero->score += 1000;


	}
	return (0);
}

void go_to_game(win_t *win, map_t *map, hero_t *hero, menu_t *menu)
{
	sfRenderWindow_clear(win->win, sfBlack);
	if (map->count >= SCALE) {
		map->count = map->count - SCALE;
		map->pos += 1;
		if (map->pos >= map->w || ((map->act_model == 0) && map->pos >= 33)) {
			map->pos = 0;
			map->act_model = (rand() % (map->nb_model - 1)) + 1;
			map->map = map->model[map->act_model];
		}
		load_new_block(map->root, map->pos, map);
	}
	while (sfRenderWindow_pollEvent(win->win, &win->evt)) {
		if (win->evt.type == sfEvtClosed)
			sfRenderWindow_close(win->win);
		if (win->evt.type == sfEvtKeyPressed) {
			key_pressed(win, map, hero);
		}
		if (win->evt.type == sfEvtMouseButtonPressed) {
			mouse_pressed_game(win, map);
		}
		if (win->evt.type == sfEvtMouseButtonReleased) {
			mouse_released_game(win, map);
		}
	}
	win->clock.time = sfClock_getElapsedTime(win->clock.clock);
	win->clock.sec = win->clock.time.microseconds / 1000000.0;
	if (win->clock.sec > 0.01) {
		map->fire_ball->clock.time = sfClock_getElapsedTime(map->fire_ball->clock.clock);
		map->fire_ball->clock.sec = map->fire_ball->clock.time.microseconds / 1000000.0;
		if (map->fire_b_gen == sfTrue && map->fire_ball->clock.sec > 0.15) {
			generate_fire_ball(map, hero, sfMouse_getPositionRenderWindow(win->win));
			sfClock_restart(map->fire_ball->clock.clock);
		}
		move_parallax(map->parralax);
		check_fb_colision(map);
		move_block(map);
		move_fireball(map);
		map->count += map->speed;
		update_score(win, map, hero, menu);
		if (hero->hero->speed.y < 20)
			hero->hero->speed.y += map->gravity;
		sfSprite_move(hero->hero->spt, (sfVector2f){hero->hero->speed.x, hero->hero->speed.y});
		hero->hero->pos = sfSprite_getPosition(hero->hero->spt);
		if(check_colision(map, hero, win, menu))
			return;
		sfClock_restart(win->clock.clock);
		my_free_list(map->free_list);
	}
	hero_animation(hero->hero, map);
	my_draw(win, map, hero->hero, menu);
	sfRenderWindow_display(win->win);
	return;
}
