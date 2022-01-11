#include "fractol.h"

void check_mouse_change(t_fractol *fractol)
{
	int x;
	int y;

	mlx_mouse_get_pos(fractol->win, &x, &y);
	if (fractol->active_mouse && (fractol->m_x != x || fractol->m_y != y))
	{
		fractol->rwa = 1;
		set_complexe(&fractol->mouse_c, fractol->h_s + fractol->m_x * fractol->pat,
					fractol->v_s - fractol->m_y * fractol->pat);
	}
	if (fractol->col_panel_active && (fractol->m_x != x || fractol->m_y != y))
	{
		((t_color *)(*(fractol->col_mod))->content)->r = x * 255 / fractol->h_size;
		((t_color *)(*(fractol->col_mod))->content)->g = y * 255 / fractol->v_size;
		((t_color *)(*(fractol->col_mod))->content)->b = fractol->blue;
		((t_color *)(*(fractol->col_mod))->content)->t = 0;
		fractol->rw = 1;
	}
	fractol->m_x = x;
	fractol->m_y = y;
}

int ft_loop_hook(t_fractol *fractol)
{
	int speed;

	speed = 1;
	if (fractol->keys.k_shift || fractol->keys.k_shift2)
		speed = 10;
	if (fractol->rw || fractol->rwa)
		calc(fractol);
	if (fractol->keys.k_p)
		add_precision(fractol);
	if (fractol->keys.k_m)
		sub_precision(fractol);
	if (fractol->keys.k_a_left)
		move_left(fractol, speed);
	if (fractol->keys.k_a_right)
		move_right(fractol, speed);
	if (fractol->keys.k_a_up)
		move_up(fractol, speed);
	if (fractol->keys.k_a_down)
		move_down(fractol, speed);
	check_mouse_change(fractol);
	return (0);
}

int ft_key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == K_M)
		fractol->keys.k_m = 1;
	else if (keycode == K_P)
		fractol->keys.k_p = 1;
	else if (keycode == K_A_DOWN)
		fractol->keys.k_a_down = 1;
	else if (keycode == K_A_LEFT)
		fractol->keys.k_a_left = 1;
	else if (keycode == K_A_RIGHT)
		fractol->keys.k_a_right = 1;
	else if (keycode == K_A_UP)
		fractol->keys.k_a_up = 1;
	else if (keycode == K_SHIFT)
		fractol->keys.k_shift = 1;
	else if (keycode == K_SHIFT2)
		fractol->keys.k_shift2 = 1;
	else if (keycode == K_ESC)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		//add freeeeee(fractol);
		exit(EXIT_SUCCESS);
	}
	printf("keycode = '%d'\n", keycode);
	return (0);
}

int ft_key_release(int keycode, t_fractol *fractol)
{
	if (keycode == K_M)
		fractol->keys.k_m = 0;
	else if (keycode == K_P)
		fractol->keys.k_p = 0;
	else if (keycode == K_A_DOWN)
		fractol->keys.k_a_down = 0;
	else if (keycode == K_A_LEFT)
		fractol->keys.k_a_left = 0;
	else if (keycode == K_A_RIGHT)
		fractol->keys.k_a_right = 0;
	else if (keycode == K_A_UP)
		fractol->keys.k_a_up = 0;
	else if (keycode == K_SHIFT)
		fractol->keys.k_shift = 0;
	else if (keycode == K_SHIFT2)
		fractol->keys.k_shift2 = 0;
	else if (keycode == K_I)
		print_info(fractol);
	else if (keycode == K_2 && fractol->col_panel_active)
		panel_next(fractol);
	else if (keycode == K_3 && fractol->col_panel_active)
		add_color(fractol);
	else if (keycode == K_C)
		active_color_panel(fractol);
	else if (keycode == K_TAB && !fractol->col_panel_active)
	{
		switch_color(fractol);
		create_panel(fractol);
		fractol->rw = 1;
	}
	return (0);
}

int ft_mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == 1 && fractol->col_panel_active == 0)
		fractol->active_mouse = (fractol->active_mouse + 1) % 2;
	if (button == 4 && fractol->col_panel_active == 0)
		zoom_out(fractol, x, y);
	else if (button == 4)
		blue_down(fractol);
	if (button == 5 && fractol->col_panel_active == 0)
		zoom_in(fractol, x, y);
	else if (button == 5)
		blue_up(fractol);
	printf("position : (%d,%d)", x, y);
	printf("%d\n", button);
	return (0);
}
