#include "fractol.h"

int	create_trgb(t_color color)
{
	return (color.t << 24  | color.r << 16 | color.g << 8 | color.b);
}

void init_grille(t_fractol *fractol)
{
	int x;
	int y;
	
	y = 0;
	while (y < fractol->v_size)
	{
		x = 0;
		while (x < fractol->h_size)
		{
			fractol->grille[y][x].it = -1;
			fractol->grille[y][x].z.r = 0;
			fractol->grille[y][x].z.i = 0;
			x++;
		}
		y++;
	}
}

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

void reset_ligne(t_case *cases, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		cases->it = -1;
		cases++;
		i++;
	}
}
void sub_precision(t_fractol *fractol)
{
	int x;
	int y;

	y = 0;
	while (y < fractol->v_size)
	{
		x = 0;
		while (x < fractol->h_size)
		{
			if (fractol->grille[y][x].it == fractol->precision)
				fractol->grille[y][x].it = -1;
			x++;
		}
		y++;
	}
	fractol->precision -= 1;
	fractol->redraw = 1;
}

void add_precision(t_fractol *fractol)
{
	int x;
	int y;
	t_complexe c;

	y = 0;
	while (y < fractol->v_size)
	{
		x = 0;
		while (x < fractol->h_size)
		{
			if (fractol->grille[y][x].it == fractol->precision)
			{
				set_complexe(&c, fractol->h_s + x * fractol->pat, 
							fractol->v_s - y * fractol->pat);
				next_mandelbrot(&fractol->grille[y][x].z, c);
				if (mod_complexe(fractol->grille[y][x].z) <= 2)
					fractol->grille[y][x].it += 1;
			}
			x++;
		}
		y++;
	}
	fractol->precision += 1;
	fractol->redraw = 1;
}





void ft_calc_mandelbrot(t_complexe *z, t_complexe c, int *it, int it_max)
{
	int i;

	set_complexe(z, 0, 0);
	i = 0;
	while (i < it_max)
	{
		if (mod_complexe(*z) > 2)
			break;
		next_mandelbrot(z, c);
		i++;
	}
	*it = i;
}

void ft_calc_julia(t_complexe *z, t_complexe c, int *it, int it_max)
{
	int i;

	set_complexe(z, c.r, c.i);
	i = 0;
	while (i < it_max)
	{
		if (mod_complexe(*z) > 2)
			break;
		next_mandelbrot(z, c);
		i++;
	}
	*it = i;
}

void calc(t_fractol *fractol)
{
	int x;
	int y;
	int pixel;
	t_complexe c;
	t_color		color;
	int		color_f;

	y = 0;
	while (y < fractol->v_size)
	{
		x = 0;
		while (x < fractol->h_size)
		{
			if (fractol->grille[y][x].it == -1)
			{
				set_complexe(&c, fractol->h_s + x * fractol->pat, 
							fractol->v_s - y * fractol->pat);
				ft_calc_mandelbrot(&(fractol->grille[y][x].z), c, &(fractol->grille[y][x].it), fractol->precision);
			}
			pixel = (y * fractol->line_length) + (x * 4);
			color.r = 255 * ((long double)fractol->grille[y][x].it / (long double)fractol->precision);
			color.g = 255 * ((long double)fractol->grille[y][x].it / (long double)fractol->precision);
			color.b = 255 * ((long double)fractol->grille[y][x].it / (long double)fractol->precision);
			color.t = 0;
			color_f = create_trgb(color);
			fractol->addr[pixel] = (color_f) & 0xFF;;
			fractol->addr[pixel + 1] = (color_f >> 8) & 0xFF;
			fractol->addr[pixel + 2] = (color_f >> 16) & 0xFF;
			fractol->addr[pixel + 3] = (color_f >> 24);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void next_mandelbrot(t_complexe *prec, t_complexe c)
{
	sq_complexe(prec);
	add_complexe(prec, *prec, c);
}
