/*
** EPITECH PROJECT, 2017
** rush1
** File description:
**
*/

#ifndef GAME_H_
#define GAME_H_

#define SCALE 40

void	go_to_game(win_t *win, map_t *map, hero_t *hero, menu_t *menu);
void	init_parralax(parralax_t *parralax, int n, sfVector2f start);
void 	 my_draw(win_t *win, map_t *map, obj_t *hero, menu_t *menu);
void	move_parallax(parralax_t *parralax);
obj_t	*create_obj(obj_t *obj, char *path, sfVector2f pos, sfIntRect rect);
void	hero_animation(obj_t *hero, map_t *map);
void   load_map(char *filename, map_t *map);
int	my_getnbr(char *str);
char	*my_strcpy(char *dst, char *src);
void	load_obj(map_t *map);
void	go_to_menu(win_t *win, menu_t *menu, hero_t *hero);
void	edit_text(sfColor c, sfVector2f pos, char *str, sfText *text);
sfRectangleShape *create_rectangle_shape(sfVector2f pos,
	sfVector2f size, sfTexture *texture);
void	load_ll_block(ll_block_t *root,
	int start, int height, map_t *map);
void free_block(ll_block_t *block);
ll_block_t	*create_root();
void	load_new_block(ll_block_t *root,
	int start, map_t *map);
void	load_model(map_t *map, char *filename, int num);
void	load_infinite_map(map_t *map);
void	create_fire_ball(ll_fire_b_t *root, sfCircleShape *shp,
	sfVector2f speed);
ll_fire_b_t	*create_fire_ball_root();
void free_fire_ball(ll_fire_b_t *block);
void	mouse_relased(win_t *win, map_t *map);
sfCircleShape *create_circle_shape(sfVector2f pos,
	float size, sfTexture *texture);
void	mouse_pressed(win_t *win, map_t *map);
void	mouse_released(win_t *win, map_t *map);
void	generate_fire_ball(map_t *map, hero_t *hero, sfVector2i mouse_pos);
void	mouse_pressed_game(win_t *win, map_t *map);
void	mouse_released_game(win_t *win, map_t *map);
void	move_fireball(map_t *map);
void	check_fb_colision(map_t *map);
block_type_t check_colision_block(sfVector2f pos, ll_block_t *tmp, float offset);
void	free_list(void *list);
void	free_block_tmp(ll_block_t *root);
void	free_fire_ball_tmp(ll_fire_b_t *root);
ll_free_t	*create_free_list_root();
void	add_in_free_list(ll_free_t *root,
void *shp, void (*free_fptr), void *free_this);
void my_free_list(ll_free_t *free_list);



#endif
