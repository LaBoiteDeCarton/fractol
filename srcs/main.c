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

int	close_fractol(int keycode, t_fractol *fractol)
{
	(void)keycode;
	mlx_clear_window(fractol->mlx, fractol->win);
	return (0);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_fractol fractol;

	fractol.precision = 1;
	init_arg_fractol(ac - 1, av + 1, &fractol);
	fractol.screen_w = 900;
	fractol.screen_h = 600;
	fractol.fract_ros.h_s = -2;
	fractol.fract_ros.v_s = 1;
	fractol.fract_ros.h_e = 1;
	fractol.fract_ros.v_e = -1;
	fractol.pat = (fractol.fract_ros.h_e -  fractol.fract_ros.h_s) / fractol.screen_w;
	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, fractol.screen_w, fractol.screen_h, "Fractol - 42 Project");
	display(&fractol);
	mlx_hook(fractol.win, 2, 1L<<0, close_fractol, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}