#include "fractol.h"

int ft_loop_hook(t_fractol *fractol)
{
	int speed;

	speed = 1;
	if (fractol->keys.k_shift || fractol->keys.k_shift2)
		speed = 10;
	if (fractol->redraw)
	{
		calc(fractol);
		fractol->redraw = 0;
	}
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
		move_down(fractol);
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
	return (0);
}

int ft_mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
		zoom_out(fractol, x, y);
	if (button == 5)
		zoom_in(fractol, x, y);
	printf("%d\n", button);
	return (0);
}