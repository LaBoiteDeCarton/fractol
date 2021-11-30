#include "fractol.h"
#include "mlx.h"
#include "libft.h"

static init_second_arg(char *str, fractol)
{
	if (ft_strisdigit(str))
		fractol->ft_atoi(str);
}

static init_first_arg(char *str, t_fractol *fractol)
{
	if (!ft_strncmp(str, "mandelbrot", 11))
		fractol->fract_type = mandelbrot;
	else if (!ft_strncmp(str, "julia", 5))
		fractol->fract_type = julia;
	else
		return (handle_error(ERR_FRACTTYPE, fractol));
}

static void init_arg_fractol(int ac, char **av, t_fractol *fractol)
{
	if (ac <= 0)
		return (handle_error(ERR_NOARG, fractol));
	init_first_arg(av[0],fractol);

}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_fractol *fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		handle_error(ERR_MALLOC);
	init_arg_fractol(ac - 1, av + 1, fractol);
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, 800, 500, "Fractol - 42 Project");
	mlx_pixel_put(fractol->mlx, fractol->win, 10, 10, 255);
	//void *image = mlx_new_image(vars.mlx, 640, 360);
    
    // int pixel_bits;
	// int line_bytes;
	// int endian;
	// char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

	// int color = 0xABCDEF;
	// buffer[0] = (color) & 0xFF;
    // buffer[1] = (color >> 8) & 0xFF;
    // buffer[2] = (color >> 16) & 0xFF;
    // buffer[3] = (color >> 24);
	// mlx_put_image_to_window(mlx, win, image, 0, 0);
	mlx_loop(fractol->mlx);
	return (1);
}