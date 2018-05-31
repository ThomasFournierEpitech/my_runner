/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

char	*my_strcpy(char *dst, char *src)
{
	int i = 0;
	int n = my_strlen(src);

	while (i < n) {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	load_block(map_t *map, int fd)
{
	char *s = NULL;
	int i = 0;

	s = get_next_line(fd);
	while (s) {
		map->map[i] = malloc(sizeof(char) * (map->w + 1));
		map->map[i][map->w] = '\0';
		map->map[i] = my_strcpy(map->map[i], s);
		free(s);
		i++;
		s = get_next_line(fd);
	}
}

char	**create_model(int fd, int w, int h)
{
	char *s = NULL;
	int i = 0;
	char **map = malloc(sizeof(*map) * (h + 1));

	map[h] = NULL;
	s = get_next_line(fd);
	while (s) {
		map[i] = malloc(sizeof(char) * (w + 1));
		map[i][w] = '\0';
		map[i] = my_strcpy(map[i], s);
		free(s);
		i++;
		s = get_next_line(fd);
	}
	return (map);
}

void	load_model(map_t *map, char *filename, int num)
{
	int fd = open(filename, O_RDONLY);
	char **arg = NULL;
	char *s = NULL;

	s = get_next_line(fd);
	arg = my_str_to_word_array(s, ',');
	free(s);
	map->w = my_getnbr(arg[0]);
	map->h = my_getnbr(arg[1]);
	map->speed = my_getnbr(arg[2]);
	map->model[num] = create_model(fd, map->w, map->h);
	close(fd);
}

void	load_infinite_map(map_t *map)
{
	map->nb_model = 10;
	map->model = malloc(sizeof(*map->model) * (map->nb_model + 1));
	map->model[map->nb_model] = NULL;
	load_model(map, "infinity/model0", 0);
	load_model(map, "infinity/model1", 1);
	load_model(map, "infinity/model2", 2);
	load_model(map, "infinity/model3", 3);
	load_model(map, "infinity/model4", 4);
	load_model(map, "infinity/model5", 5);
	load_model(map, "infinity/model6", 6);
	load_model(map, "infinity/model7", 7);
	load_model(map, "infinity/model8", 8);
	load_model(map, "infinity/model9", 9);
	map->map = map->model[map->act_model];
	map->root = create_root();
	load_ll_block(map->root, 0, 33, map);
	map->pos = 32;
}
void	load_map(char *filename, map_t *map)
{
	map->nb_model = 2;
	map->model = malloc(sizeof(*map->model) * (map->nb_model + 1));
	map->model[map->nb_model] = NULL;
	load_model(map, "infinity/model0", 0);
	load_model(map, filename, 1);
	map->map = map->model[map->act_model];
	map->root = create_root();
	map->act_model = 0;
	load_ll_block(map->root, 0, 33, map);
	map->pos = 32;
}
