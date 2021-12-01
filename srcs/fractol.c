#include "fractol.h"

void init_arg_fractol(int ac, char **av, t_fractol *fractol)
{
	if (ac <= 0)
		return (handle_error(ERR_NOARG));
	if (!fractol)
		return (handle_error(ERR_MALLOC));
	if (ft_strncmp(av[0], "mandelbrot", 11))
		fractol->fract_type = mandelbrot;
	else if (ft_strncmp(av[0], "julia", 6))
		fractol->fract_type = julia;
	else
		return (handle_error(ERR_FRACTTYPE));
}

void display(t_fractol *fractol)
{
	int h;
	int w;
	int pixel;
	int color;
	t_complexe position;

	fractol->img = mlx_new_image(fractol->mlx, fractol->screen_w, fractol->screen_h);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, &fractol->line_length,
								&fractol->endian);
	h = 0;
	while (h < fractol->screen_h)
	{
		w = 0;
		while (w < fractol->screen_w)
		{
			set_complexe(&position, fractol->fract_ros.h_s + w * fractol->pat, 
							fractol->fract_ros.v_s - h * fractol->pat);
			pixel = (h * fractol->line_length) + (w * 4);
			color = calc_mandelbrot(position, fractol->precision);
			fractol->addr[pixel] = color;
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

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

void next_mandelbrot(t_complexe *prec, t_complexe c)
{
	sq_complexe(prec);
	add_complexe(prec, *prec, c);
}

int		calc_mandelbrot(t_complexe c, int it)
{
	int 		i;
	int 		color;
	t_complexe	z;


	set_complexe(&z, 0, 0);
	i = 0;
	while (i < it)
	{
		if (mod_complexe(z) > 2)
			break;
		next_mandelbrot(&z, c);
		i++;
	}
	switch (i)
	{
	case 0:
		color = 0x000000;
		break;
	case 1:
		color = 0x111111;
		break;
	case 2:
		color = 0x222222;
		break;
	case 3:
		color = 0x333333;
		break;
	case 4:
		color = 0x444444;
		break;
	case 5:
		color = 0x555555;
		break;
	case 6:
		color = 0x666666;
		break;
	case 7:
		color = 0x777777;
		break;
	case 8:
		color = 0x888888;
		break;
	case 9:
		color = 0x999999;
		break;
	case 10:
		color = 0xAAAAAA;
		break;
	case 11:
		color = 0xBBBBBB;
		break;
	case 12:
		color = 0xCCCCCC;
		break;
	case 13:
		color = 0xDDDDDD;
		break;
	case 14:
		color = 0xEEEEEE;
		break;
	default:
		color = 0x000000;
		break;
	}
	return (color);
}