#include "fractol.h"

void check_mouse_change(t_fractol *fractol)
{
	int x;
	int y;

	mlx_mouse_get_pos(fractol->win, &x, &y);
	if (fractol->active_mouse && (fractol->m_x != x || fractol->m_y != y))
		fractol->rwa = 1;
	fractol->m_x = x;
	fractol->m_y = y;
	set_complexe(&fractol->mouse_c, fractol->h_s + fractol->m_x * fractol->pat,
					fractol->v_s - fractol->m_y * fractol->pat);
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
		move_right(fractol);
	if (fractol->keys.k_a_up)
		move_up(fractol, speed);
	if (fractol->keys.k_a_down)
		move_down(fractol, speed);
	if (fractol->active_mouse)
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
	else if (keycode == 53)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
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
	else if (keycode == K_A)
		zoom_in(fractol, fractol->h_size / 2, fractol->v_size / 2);
	else if (keycode == K_I)
		print_info(fractol);
	else if (keycode == 18)
		add_color(fractol);	
	//change_color_aleatoire(fractol, &(fractol->col.in));
	// else if (keycode == 19)
	// 	change_color_aleatoire(fractol, &(fractol->col.out_from));
	// else if (keycode == 20)
	// 	change_color_aleatoire(fractol, &(fractol->col.out_to));
	// else if (keycode == 21)
	// 	swap_color(fractol);
	return (0);
}

int ft_mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == 1)
		fractol->active_mouse = (fractol->active_mouse + 1) % 2;
	if (button == 4)
		zoom_out(fractol, x, y);
	if (button == 5)
		zoom_in(fractol, x, y);
	printf("position : (%d,%d)", x, y);
	printf("%d\n", button);
	return (0);
}
