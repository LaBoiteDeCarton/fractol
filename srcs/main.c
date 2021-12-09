#include "fractol.h"
#include "mlx.h"
#include "libft.h"

static void	init_keys(t_fractol *fractol)
{
	fractol->keys.k_m = 0;
	fractol->keys.k_p = 0;
	fractol->keys.k_a_down = 0;
	fractol->keys.k_a_left = 0;
	fractol->keys.k_a_right = 0;
	fractol->keys.k_a_up = 0;
}

static void put_default_arg(t_fractol *fractol)
{
	fractol->h_size = H_MEDIUM_SIZE;
	fractol->v_size = V_MEDIUM_SIZE;
	fractol->precision = 10;
	fractol->redraw = 1;
	fractol->h_s = -2.25;
	fractol->v_s = 3.25;
	fractol->h_e = 1.25;
	fractol->v_e = -1;
	init_keys(fractol);
	fractol->pat = (fractol->h_e -  fractol->h_s) / fractol->v_size;	
}

static void init_first_arg(char *str, t_fractol *fractol)
{
	if (!ft_strncmp(str, "mandelbrot", 11))
		fractol->fract_type = mandelbrot;
	else if (!ft_strncmp(str, "julia", 5))
		fractol->fract_type = julia;
	else
		handle_error(ERR_FRACTTYPE);
}

static void init_arg_fractol(int ac, char **av, t_fractol *fractol)
{
	if (ac <= 0)
		handle_error(ERR_NOARG);
	init_first_arg(av[0],fractol);
	if (ac > 1)
		handle_error(ERR_TOOMUCHARG);
	put_default_arg(fractol);
}

int ft_loop_hook(t_fractol *fractol)
{
	if (fractol->redraw)
	{
		display(fractol);
		fractol->redraw = 0;
	}
	if (fractol->keys.k_a_left)
		move_left(fractol);
	if (fractol->keys.k_a_right)
		move_right(fractol);
	if (fractol->keys.k_a_up)
		move_up(fractol);
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
	{
		if (fractol->precision > 0)
			fractol->precision -= 1;
		fractol->redraw = 1;
		fractol->keys.k_m = 0;
	}
	else if (keycode == K_P)
	{
		fractol->precision += 1;
		fractol->redraw = 1;
		fractol->keys.k_p = 0;
	}
	else if (keycode == K_A_DOWN)
		fractol->keys.k_a_down = 0;
	else if (keycode == K_A_LEFT)
		fractol->keys.k_a_left = 0;
	else if (keycode == K_A_RIGHT)
		fractol->keys.k_a_right = 0;
	else if (keycode == K_A_UP)
		fractol->keys.k_a_up = 0;
	return (0);
}

int ft_mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == 5)
		zoom_out(fractol, x, y);
	if (button == 4)
		zoom_in(fractol, x, y);
	printf("%d\n", button);
	return (0);
}

int main(int ac, char **av)
{
	t_fractol fractol;

	init_arg_fractol(ac - 1, av + 1, &fractol);
	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, fractol.h_size, fractol.v_size, "Fractol - 42 Project");
	display(&fractol);
	mlx_hook(fractol.win, 2, 1L<<0, ft_key_hook, &fractol);
	mlx_hook(fractol.win, 3, 1L<<1, ft_key_release, &fractol);
	mlx_mouse_hook(fractol.win, ft_mouse_hook, &fractol);
	mlx_loop_hook(fractol.mlx, ft_loop_hook, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}