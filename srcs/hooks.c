/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:17:28 by dmercadi          #+#    #+#             */
/*   Updated: 2022/01/23 16:17:29 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

int	ft_loop_hook(t_fct *fct)
{
	int	speed;

	speed = 1;
	if (fct->keys.k_shift || fct->keys.k_shift2)
		speed = 10;
	if (fct->rw || fct->rwa)
	{
		calc(fct);
		fct->rw = 0;
		fct->rwa = 0;
	}
	if (fct->keys.k_p)
		add_precision(fct);
	if (fct->keys.k_m)
		sub_precision(fct);
	if (fct->keys.k_a_left)
		move_left(fct, speed);
	if (fct->keys.k_a_right)
		move_right(fct, speed);
	if (fct->keys.k_a_up)
		move_up(fct, speed);
	if (fct->keys.k_a_down)
		move_down(fct, speed);
	check_mouse_change(fct);
	return (0);
}

int	ft_key_hook(int keycode, t_fct *fct)
{
	if (keycode == K_M)
		fct->keys.k_m = 1;
	else if (keycode == K_P)
		fct->keys.k_p = 1;
	else if (keycode == K_A_DOWN)
		fct->keys.k_a_down = 1;
	else if (keycode == K_A_LEFT)
		fct->keys.k_a_left = 1;
	else if (keycode == K_A_RIGHT)
		fct->keys.k_a_right = 1;
	else if (keycode == K_A_UP)
		fct->keys.k_a_up = 1;
	else if (keycode == K_SHIFT)
		fct->keys.k_shift = 1;
	else if (keycode == K_SHIFT2)
		fct->keys.k_shift2 = 1;
	else if (keycode == K_SPACE && fct->col_panel_active)
		panel_color_inside(fct);
	else if (keycode == K_ESC)
	{
		freee(fct);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static void ft_key_release_actions(int keycode, t_fct *fct)
{
	if (keycode == K_L)
		fct->lissage = (fct->lissage + 1) % 2;
	else if (keycode == K_SPACE && fct->col_panel_active)
	{
		fct->col_panel_active = 0;
		fct->keys.k_space = 0;
		active_color_panel(fct);
	}
	else if (keycode == K_1 && fct->col_panel_active)
		panel_prev(fct);
	else if (keycode == K_2 && fct->col_panel_active)
		panel_next(fct);
	else if (keycode == K_3 && fct->col_panel_active)
		panel_add_color(fct);
	else if (keycode == K_4 && fct->col_panel_active)
		panel_del_color(fct);
	else if (keycode == K_C)
		active_color_panel(fct);
	else if (keycode == K_TAB && !fct->col_panel_active)
		switch_palette(fct);
	fct->rw = 1;
}

int	ft_key_release(int keycode, t_fct *fct)
{
	if (keycode == K_M)
		fct->keys.k_m = 0;
	else if (keycode == K_P)
		fct->keys.k_p = 0;
	else if (keycode == K_A_DOWN)
		fct->keys.k_a_down = 0;
	else if (keycode == K_A_LEFT)
		fct->keys.k_a_left = 0;
	else if (keycode == K_A_RIGHT)
		fct->keys.k_a_right = 0;
	else if (keycode == K_A_UP)
		fct->keys.k_a_up = 0;
	else if (keycode == K_SHIFT)
		fct->keys.k_shift = 0;
	else if (keycode == K_SHIFT2)
		fct->keys.k_shift2 = 0;
	ft_key_release_actions(keycode, fct);
	return (0);
}

int	ft_mouse_hook(int button, int x, int y, t_fct *fct)
{
	if (button == 1 && fct->col_panel_active == 0)
		fct->active_mouse = (fct->active_mouse + 1) % 2;
	if (button == 4 && fct->col_panel_active == 0)
		zoom_out(fct, x, y);
	else if (button == 4)
		panel_blue_down(fct);
	if (button == 5 && fct->col_panel_active == 0)
		zoom_in(fct, x, y);
	else if (button == 5)
		panel_blue_up(fct);
	return (0);
}
