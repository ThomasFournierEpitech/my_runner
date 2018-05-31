/*
** EPITECH PROJECT, 2017
** rush1
** File description:
**
*/

#ifndef STRUCTURE_H_
#define STRUCTURE_H_

typedef enum block_type_s
{
	END,
	OBSTACLE,
	WINGS,
	NOTHING,
} block_type_t;

typedef enum block_resilience_s
{
	UNBREAKABLE,
	BREAKABLE
} block_resilience_t;

typedef struct ll_block_s
{
	sfRectangleShape *shp;
 	block_type_t type;
	block_resilience_t resilience;
	int status;
	struct ll_block_s *next;
	struct ll_block_s *prev;
	void (*free)(struct ll_block_s *);
} ll_block_t;

typedef enum state {
	OFF,
	PASS_OVER,
	CLICK,
	CALL_BACK
} state_t;

typedef struct clck_s
{
	sfClock *clock;
	sfTime time;
	float sec;
} clck_t;

typedef struct music_s
{
	sfMusic *music;
	int vol;
} music_t;

typedef struct config_s
{
	sfTexture *bloc;
	sfTexture *breakable;
	sfTexture *wings;
	sfTexture *fireball;
	sfTexture *nothing;
} config_t;

typedef struct win_s
{
	sfRenderWindow *win;
	sfVideoMode mode;
	sfEvent evt;
	int state;
	int nb_menu;
	clck_t clock;
	clck_t time;
	music_t music;
	music_t wing;
} win_t;


typedef struct global_s global_t;

typedef struct button_s
{
	sfRectangleShape *shp;
	sfIntRect hitbox;
	sfText *text;
	state_t state;
	void (*call_back)(void *);
	void (*pass_over)(void *);
	void (*click)(void *);
	sfBool selected;

} button_t;

typedef struct button_ll_s
{
	button_t button;
	struct button_ll_s *next;
} button_ll_t;

typedef struct menu_s
{
	sfSprite *spt;
	sfTexture *img;
	sfIntRect rect;
	sfVector2f pos;
	sfText *text;
	sfFont *font;
	float speed;
	int offset;
	button_ll_t *button_list;
	clck_t clock;
} menu_t;

typedef struct parallax_s
{
	int nb_layer;
	float *speed;
	sfSprite **layers;
	sfIntRect rect;
	sfVector2f pos;
	sfTexture *img;
	clck_t clock;
} parralax_t;


typedef struct obj_s
{
	sfSprite *spt;
	sfTexture *img;
	sfIntRect rect;
	sfVector2f offset;
	sfVector2f pos;
	sfVector2f speed;
	sfText *text;
	sfFont *font;
	int state;
	clck_t clock;
} obj_t;

typedef struct ll_free_s
{
	void *shp;
	void *free_this;
	void (*free)(struct ll_free_s *);
	struct ll_free_s *next;
	struct ll_free_s *prev;
} ll_free_t;

typedef struct ll_fire_b_s
{
	sfCircleShape *shp;
	sfVector2f speed;
	int status;
	clck_t clock;
	void (*free)(struct ll_fire_b_s *);
	struct ll_fire_b_s *next;
	struct ll_fire_b_s *prev;
} ll_fire_b_t;

typedef struct map_s
{
	parralax_t *parralax;
	char **map;
	char ***model;
	int nb_model;
	int act_model;
	int w;
	int h;
	float gravity;
	int pos;
	int count;
	float speed;
	ll_block_t *root;
	ll_fire_b_t *fire_ball;
	ll_free_t *free_list;
	sfBool fire_b_gen;
	config_t config;
} map_t;

typedef struct body_s
{
	sfVector2f fb_origin;
} body_t;

typedef struct hero_s
{
	obj_t *hero;
	float score;
	sfBool victory;
	sfTexture *img_b;
	sfTexture *img_y;
	sfTexture *img_r;
	body_t body;
	float hunger;
} hero_t;

typedef struct info_menu_s
{
	obj_t *hero;
	sfTexture *img_b;
	sfTexture *img_y;
	sfTexture *img_r;
	float hunger;
} info_menu_t;


typedef struct global_s
{
	win_t *win;
	menu_t *menu;
	map_t *map;
	hero_t *hero;
} global_t;


#endif /*STRUCTURE_H_*/
