/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

sfVector2f	center_text(sfVector2f b_pos, sfVector2f size, int len, int c_size)
{
	sfVector2f new = {0, 600};
	sfVector2f offset = {0, 0};
	int rest = 0;

	//len = (len < 0) ? 0 : len;
	if (len > size.x || c_size > size.y)
		return (b_pos);
	offset.x = size.x / 2 - len / 2;
	printf("%d\n", len);
	new.x = b_pos.x + offset.x;
	rest = size.y - c_size;
	offset.y = rest / 2;
	new.y = b_pos.y + offset.y - c_size / 2;

	return (new);
}
