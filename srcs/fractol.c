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

void move_down(t_fractol *fractol)
{
	int i;
	int color;
	int pixel;
	t_complexe position;

	fractol->v_s = fractol->v_s - fractol->pat;
	ft_memmove(fractol->addr, fractol->addr + fractol->line_length, (fractol->v_size - 1) * fractol->line_length);
	i = 0;
	while (i < fractol->h_size)
	{
		set_complexe(&position, fractol->h_s + i * fractol->pat, 
							fractol->v_s - (fractol->v_size - 1) * fractol->pat);
		pixel = ((fractol->v_size - 1) * fractol->line_length) + (i * 4);
		color = calc_mandelbrot(position, fractol->precision);
		fractol->addr[pixel] = (color) & 0xFF;;
		fractol->addr[pixel + 1] = (color >> 8) & 0xFF;
		fractol->addr[pixel + 2] = (color >> 16) & 0xFF;
		fractol->addr[pixel + 3] = (color >> 24);
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void		move_up(t_fractol *fractol)
{
	int i;
	int color;
	int pixel;
	t_complexe position;

	fractol->v_s = fractol->v_s + fractol->pat;
	ft_memmove(fractol->addr + fractol->line_length, fractol->addr, (fractol->v_size - 1) * fractol->line_length);
	i = 0;
	while (i < fractol->h_size)
	{
		set_complexe(&position, fractol->h_s + i * fractol->pat, 
							fractol->v_s);
		pixel = (i * 4);
		color = calc_mandelbrot(position, fractol->precision);
		fractol->addr[pixel] = (color) & 0xFF;;
		fractol->addr[pixel + 1] = (color >> 8) & 0xFF;
		fractol->addr[pixel + 2] = (color >> 16) & 0xFF;
		fractol->addr[pixel + 3] = (color >> 24);
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void		move_left(t_fractol *fractol)
{
	int i;
	int color;
	int pixel;
	t_complexe position;

	fractol->h_s = fractol->h_s - fractol->pat;
	ft_memmove(fractol->addr + 4, fractol->addr, fractol->v_size * fractol->line_length - 4);
	i = 0;
	while (i < fractol->v_size)
	{
		set_complexe(&position, fractol->h_s, 
							fractol->v_s - i * fractol->pat);
		pixel = (i * fractol->line_length);
		color = calc_mandelbrot(position, fractol->precision);
		fractol->addr[pixel] = (color) & 0xFF;;
		fractol->addr[pixel + 1] = (color >> 8) & 0xFF;
		fractol->addr[pixel + 2] = (color >> 16) & 0xFF;
		fractol->addr[pixel + 3] = (color >> 24);
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void		move_right(t_fractol *fractol)
{
	int i;
	int color;
	int pixel;
	t_complexe position;

	fractol->h_s = fractol->h_s + fractol->pat;
	ft_memmove(fractol->addr, fractol->addr + 4, fractol->v_size * fractol->line_length - 4);
	i = 0;
	while (i < fractol->v_size)
	{
		set_complexe(&position, fractol->h_s + fractol->pat * fractol->h_size, 
							fractol->v_s - i * fractol->pat);
		pixel = (i * fractol->line_length + fractol->line_length - 4);
		color = calc_mandelbrot(position, fractol->precision);
		fractol->addr[pixel] = (color) & 0xFF;;
		fractol->addr[pixel + 1] = (color >> 8) & 0xFF;
		fractol->addr[pixel + 2] = (color >> 16) & 0xFF;
		fractol->addr[pixel + 3] = (color >> 24);
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void zoom_out(t_fractol *fractol, int x, int y)
{
	long double perc;
	long double new_pat;
	long double largeur_extrait;

	new_pat = fractol->pat * 1.1;
	largeur_extrait = (new_pat - fractol->pat) * fractol->h_size;
	perc = (long double)x / fractol->h_size;
	fractol->h_s -= perc * largeur_extrait;
	largeur_extrait = (new_pat - fractol->pat) * fractol->v_size;
	perc = (long double)y /fractol->v_size;
	fractol->v_s += perc * largeur_extrait;
	fractol->pat = new_pat;
	fractol->redraw = 1;
}

void zoom_in(t_fractol *fractol, int x, int y)
{
	long double perc;
	long double new_pat;
	long double largeur_extrait;

	new_pat = fractol->pat / 1.1;
	largeur_extrait = (fractol->pat - new_pat) * fractol->h_size;
	perc = (long double)x / fractol->h_size;
	fractol->h_s += perc * largeur_extrait;
	largeur_extrait = (fractol->pat - new_pat) * fractol->v_size;
	perc = (long double)y / fractol->v_size;
	fractol->v_s -= perc * largeur_extrait;
	fractol->pat = new_pat;
	fractol->redraw = 1;
}

int	create_trgb(t_color color)
{
	return (color.t << 24  | color.r << 16 | color.g << 8 | color.b);
}

void display(t_fractol *fractol)
{
	int v;
	int h;
	int pixel;
	int i;
	int color_f;
	t_color color;
	t_complexe position;

	fractol->img = mlx_new_image(fractol->mlx, fractol->h_size, fractol->v_size);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, &fractol->line_length,
								&fractol->endian);
	v = 0;
	while (v < fractol->v_size)
	{
		h = 0;
		while (h < fractol->h_size)
		{
			set_complexe(&position, fractol->h_s + h * fractol->pat, 
							fractol->v_s - v * fractol->pat);
			pixel = (v * fractol->line_length) + (h * 4);
			i = calc_mandelbrot(position, fractol->precision);
			color.r = 255 * i / fractol->precision;
			color.g = 255 * i / fractol->precision;
			color.b = 255;
			color.t = 0;
			color_f = create_trgb(color);
			fractol->addr[pixel] = (color_f) & 0xFF;;
			fractol->addr[pixel + 1] = (color_f >> 8) & 0xFF;
			fractol->addr[pixel + 2] = (color_f >> 16) & 0xFF;
			fractol->addr[pixel + 3] = (color_f >> 24);
			h++;
		}
		v++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

			// fractol->addr[pixel] = (color) & 0xFF;;
			// fractol->addr[pixel + 1] = (color >> 8) & 0xFF;
			// fractol->addr[pixel + 2] = (color >> 16) & 0xFF;
			// fractol->addr[pixel + 3] = (color >> 24);

void next_mandelbrot(t_complexe *prec, t_complexe c)
{
	sq_complexe(prec);
	add_complexe(prec, *prec, c);
}

void my_put_color_pixel()
{
	
}

int		calc_mandelbrot(t_complexe c, int it)
{
	int 		i;
	//int 		color;
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
	// switch (i)
	// {
	// case 0:
	// 	color = 0x000000;
	// 	break;
	// case 1:
	// 	color = 0x876792;
	// 	break;
	// case 2:
	// 	color = 0xA782F9;
	// 	break;
	// case 3:
	// 	color = 0xDDD673;
	// 	break;
	// case 4:
	// 	color = 0x0983B3;
	// 	break;
	// case 5:
	// 	color = 0xBAFD37;
	// 	break;
	// case 6:
	// 	color = 0xBD8FE8;
	// 	break;
	// case 7:
	// 	color = 0x87A7A6;
	// 	break;
	// case 8:
	// 	color = 0x97ABFF;
	// 	break;
	// case 9:
	// 	color = 0x37687B;
	// 	break;
	// case 10:
	// 	color = 0xAFA47A;
	// 	break;
	// case 11:
	// 	color = 0x2798B3;
	// 	break;
	// case 12:
	// 	color = 0x283FFB;
	// 	break;
	// case 13:
	// 	color = 0x987D98;
	// 	break;
	// case 14:
	// 	color = 0xED7E7D;
	// 	break;
	// default:
	// 	color = 0x000000;
	// 	break;
	// }
	return (i);
}