/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	init_window(win_t *win)
{
	win->mode.width = WIDTH;
	win->mode.height = HEIGHT;
	win->mode.bitsPerPixel = 32;
	win->state = 1;
	win->nb_menu = 0;
	win->win = sfRenderWindow_create(win->mode, "My_runner", 0 |
	sfClose, NULL);
	win->clock.clock = sfClock_create();
	win->time.clock = sfClock_create();
	win->music.music = sfMusic_createFromFile("music.ogg");
	win->music.vol = 15;
	win->wing.music = sfMusic_createFromFile ("wings.ogg");
	sfMusic_setVolume (win->wing.music, 40);
	sfRenderWindow_setKeyRepeatEnabled(win->win, sfFalse);
	sfRenderWindow_setFramerateLimit(win->win, 90);
}

void	init_map(win_t *win, map_t *map, char *filename, sfBool infinity)
{
	parralax_t *parralax = malloc(sizeof(*parralax) * 2);

	init_parralax(parralax, 0, (sfVector2f){0, 0});
	init_parralax(parralax, 1, (sfVector2f){1280, 0});
	map->gravity = 0.6;
	map->parralax = parralax;
	map->pos = 0;
	map->count = 0;
	map->act_model = 0;
	map->config = create_config();
	if (infinity)
		load_infinite_map(map);
	else
		load_map(filename, map);
	map->fire_ball = create_fire_ball_root();
	map->fire_b_gen = sfFalse;
	map->free_list = create_free_list_root();
}

void	init_hero(obj_t *obj, hero_t *hero)
{
	obj->offset = (sfVector2f){80, 0};
	obj->speed = (sfVector2f){0, 0};
	obj->state = 1;
	obj->clock.clock = sfClock_create();
	sfSprite_setOrigin (obj->spt, (sfVector2f) {40, 40});
	hero->hero = obj;
	hero->hunger = 100;
	hero->img_b = sfTexture_createFromFile("img/hero_b.png", NULL);
	hero->img_y = sfTexture_createFromFile("img/hero_y.png", NULL);
	hero->img_r = sfTexture_createFromFile("img/hero_r.png", NULL);
	hero->score = 0;
}

int start_game(char *filename, sfBool infinity)
{
	win_t *win = malloc(sizeof(*win));
	menu_t *menu = malloc(sizeof(*menu) * NB_MENU);
	map_t *map = malloc(sizeof(*map));
	hero_t *hero = malloc(sizeof(*hero));
	obj_t *obj = create_obj(obj, "img/hero_b.png",
	(sfVector2f){WIDTH / 2 - 55, HEIGHT / 2 - 55},
	(sfIntRect){0, 0, 80, 80});

	init_window(win);
	init_map(win, map, filename, infinity);
	init_hero(obj, hero);
	init_menu(win, menu, hero);
	sfMusic_setVolume(win->music.music, win->music.vol);
	sfMusic_setLoop(win->music.music, sfTrue);
	sfMusic_play(win->music.music);
	while (sfRenderWindow_isOpen(win->win)) {
		if (win->state == 1)
			go_to_game(win, map, hero, menu);
		if (win->state > 1)
			go_to_menu(win, menu, hero);
		if (win->state == -42) {
			menu = malloc(sizeof(*menu) * NB_MENU);
			map = malloc(sizeof(*map));
			hero = malloc(sizeof(*hero));
			obj = create_obj(obj, "img/hero_b.png",
			(sfVector2f){WIDTH / 2 - 55, HEIGHT / 2 - 55},
			(sfIntRect){0, 0, 80, 80});
			init_map(win, map, filename, sfFalse);
			init_hero(obj, hero);
			init_menu(win, menu, hero);
			win->state = 2;
		}
		if (win->state == -84) {
			menu = malloc(sizeof(*menu) * NB_MENU);
			map = malloc(sizeof(*map));
			hero = malloc(sizeof(*hero));
			obj = create_obj(obj, "img/hero_b.png",
			(sfVector2f){WIDTH / 2 - 55, HEIGHT / 2 - 55},
			(sfIntRect){0, 0, 80, 80});
			init_map(win, map, filename, sfTrue);
			init_hero(obj, hero);
			init_menu(win, menu, hero);
			win->state = 2;
		}
	}
	sfMusic_stop(win->music.music);
	sfMusic_stop(win->wing.music);
	sfMusic_destroy(win->music.music);
	sfMusic_destroy(win->wing.music);
	return (0);
}
