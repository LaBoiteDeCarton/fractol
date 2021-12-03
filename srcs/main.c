#include "fractol.h"
#include "mlx.h"
#include "libft.h"

static void init_second_arg(char *str, t_fractol *fractol)
{
	if (ft_strisdigit(str))
		fractol->precision = ft_atoi(str);
	else
		handle_error(ERR_BAD2ARG);
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
		init_second_arg(av[1], fractol);

}

int	key_hook(int keycode, t_fractol *fractol)
{
	(void)keycode;
	(void)fractol;
	printf("Hello from key_hook!\n");
	return (0);
}

int ft_key_hook(int keycode, t_fractol *fractol)
{
	(void)fractol;
	if (keycode == 123)
		fractol->h_s = fractol->h_s - 50 * fractol->pat; //move to function
	else if (keycode == 124)
		fractol->h_s = fractol->h_s + 50 * fractol->pat;
	else if (keycode == 125)
		move_to_down(fractol);
	else if (keycode == 126)
		fractol->v_s = fractol->v_s + 50 * fractol->pat;
	else if (keycode == 12)
	{
		fractol->pat = fractol->pat / 2; // zoom to function
		// fractol->v_s = fractol->v_s + fractol->v_size / 4;
		// fractol->h_s = fractol->h_s + fractol->h_size / 4;
	} 
	else if (keycode == 13)
	{
		fractol->pat = fractol->pat * 2;
		// fractol->v_s = fractol->v_s - fractol->v_size / 4;
		// fractol->h_s = fractol->h_s - fractol->h_size / 4;
	} 
	if (keycode == 53)
		mlx_destroy_window(fractol->mlx, fractol->win);
	// else
	// 	display(fractol);
	printf("keycode = '%d'\n", keycode);
	return (0);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_fractol fractol;

	fractol.precision = 1;
	init_arg_fractol(ac - 1, av + 1, &fractol);
	fractol.v_size = 900;
	fractol.h_size = 600;
	fractol.h_s = -2;
	fractol.v_s = 1;
	fractol.h_e = 1;
	fractol.v_e = -1;
	fractol.pat = (fractol.h_e -  fractol.h_s) / fractol.v_size;
	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, fractol.v_size, fractol.h_size, "Fractol - 42 Project");
	display(&fractol);
	mlx_key_hook(fractol.win, ft_key_hook, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}