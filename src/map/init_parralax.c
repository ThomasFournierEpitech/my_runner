/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	init_parralax(parralax_t *parralax, int n, sfVector2f start)
{
	int i = 0;
	char text[8][100] = {"layers/sky.png", "layers/clouds_1.png", "layers/clouds_2.png",
	"layers/rocks.png", "layers/ground_1.png", "layers/ground_2.png",
	"layers/ground_3.png", "layers/plant.png"};
	float sp[8] = {0, 0.1, 0.1, 0.2, 0.5, 1.5, 4, 5};

	parralax[n].nb_layer = 8;
	parralax[n].layers = malloc(sizeof(*parralax[n].layers) * parralax[n].nb_layer);
	parralax[n].speed = malloc(sizeof(*parralax[n].speed) * parralax[n].nb_layer);
	parralax[n].rect = (sfIntRect){0, 0, WIDTH, HEIGHT};
	parralax[n].pos = (sfVector2f)start;
	while (i < parralax[n].nb_layer) {
		parralax[n].layers[i] = sfSprite_create();
		sfSprite_setPosition(parralax[n].layers[i], parralax[n].pos);
		parralax[n].img = sfTexture_createFromFile(text[i], NULL);
		sfSprite_setTextureRect(parralax[n].layers[i], parralax[n].rect);
		sfSprite_setTexture(parralax[n].layers[i], parralax[n].img, sfTrue);
		parralax[n].speed[i] = sp[i];
		i++;
	}
}
