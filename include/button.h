/*
** EPITECH PROJECT, 2017
** rush1
** File description:
**
*/

#ifndef BUTTON_H_
#define BUTTON_H_

button_ll_t	*create_button_ll();
void	add_button_in_list(button_ll_t	**list, button_t button);
button_t	create_button(sfTexture *tex,
	sfVector2f pos, sfVector2f size, void (*call_back));
void	draw_buttons(button_ll_t *list, win_t *win);
void	test_button_call_back(button_ll_t *list, sfVector2i m_pos, win_t *win);
void	manage_button(button_ll_t *list, win_t *win);
void	test_hitbox(button_ll_t *list, sfVector2i m_pos, win_t *win);
void	test_click(button_ll_t *list, sfVector2i m_pos, win_t *win);
void	test_declick(button_ll_t *list, sfVector2i m_pos, win_t *win);

void 	fptr_nothing(void *win);
void exit_cb(win_t *win);
void play_cb(win_t *win);
void pass_over(button_t *button);
void click(button_t *button);
void reset_button(button_t *button);
void restart_game(win_t *win);
void infinity_game(win_t *win);

#endif
