/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "include.h"

void	draw_buttons(button_ll_t *list, win_t *win)
{
	button_ll_t *tmp = list->next;

	while (tmp) {
		sfRenderWindow_drawRectangleShape(win->win, tmp->button.shp, NULL);
		if (tmp->button.text)
			sfRenderWindow_drawText(win->win, tmp->button.text, NULL);
		tmp = tmp->next;
	}
}

void	test_click(button_ll_t *list, sfVector2i m_pos, win_t *win)
{
	button_ll_t *tmp = list->next;

	while (tmp) {
		if (tmp->button.state == PASS_OVER) {
			tmp->button.state = CLICK;
		}
		tmp = tmp->next;
	}
}

void	test_declick(button_ll_t *list, sfVector2i m_pos, win_t *win)
{
	button_ll_t *tmp = list->next;
	sfIntRect hitbox;

	while (tmp) {
		if (tmp->button.selected == sfTrue) {
			tmp->button.state = CALL_BACK;
			tmp->button.selected == sfFalse;
		}
		tmp = tmp->next;
	}
}

void	test_hitbox(button_ll_t *list, sfVector2i m_pos, win_t *win)
{
	button_ll_t *tmp = list->next;
	sfIntRect hitbox;

	while (tmp) {
		hitbox = tmp->button.hitbox;
		if (m_pos.x >= hitbox.left && m_pos.x <= hitbox.width &&
		m_pos.y >= hitbox.top && m_pos.y <= hitbox.height)
			tmp->button.state = PASS_OVER;
		else if (tmp->button.state == PASS_OVER) {
			tmp->button.state = OFF;
		}
		tmp = tmp->next;
	}
}

void	manage_button(button_ll_t *list, win_t *win)
{
	button_ll_t *tmp = list->next;

	while (tmp) {
		if (tmp->button.state == PASS_OVER)
			tmp->button.pass_over(&tmp->button);
		if (tmp->button.state == CLICK || tmp->button.selected == sfTrue) {
			tmp->button.click(&tmp->button);
		}
		if (tmp->button.state == CALL_BACK) {
			tmp->button.call_back(win);
			tmp->button.state = OFF;
		}
		if (tmp->button.state == OFF) {
			reset_button(&tmp->button);
		}
		tmp = tmp->next;
	}
}

button_t	create_button(sfTexture *tex,
	sfVector2f pos, sfVector2f size, void (*call_back))
{
	button_t button;
	sfRectangleShape *shp = sfRectangleShape_create();

	sfRectangleShape_setTexture(shp, tex, sfTrue);
	sfRectangleShape_setPosition(shp, pos);
	sfRectangleShape_setSize(shp, size);
	button.call_back = call_back;
	button.pass_over = &fptr_nothing;
	button.click = &fptr_nothing;
	button.shp = shp;
	button.text = sfText_create();
	button.state = OFF;
	button.selected = sfFalse;
	return (button);
}

void	add_button_in_list(button_ll_t	**list, button_t button)
{
	button_ll_t *new = malloc(sizeof(*new));

	new->button = button;
	new->next = (*list)->next;
	(*list)->next = new;
}

button_ll_t	*create_button_ll()
{
	button_ll_t *root = malloc(sizeof(*root));

	root->next = NULL;
}
