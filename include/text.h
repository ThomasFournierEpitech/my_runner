/*
** EPITECH PROJECT, 2017
** rush1
** File description:
**
*/

#ifndef TEXT_H_
#define TEXT_H_

sfText *create_exit_text(sfFont *font, sfVector2f b_pos,
sfVector2f size, char *str);
sfVector2f	center_text(sfVector2f b_pos, sfVector2f size,
int len, int c_size);
sfText *create_restart_text(sfFont *font, sfVector2f b_pos,
sfVector2f size, char *str);

#endif
