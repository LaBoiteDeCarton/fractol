#include "fractol.h"
#define min(a,b) (a<=b?a:b)

int	create_trgb(t_color color)
{
	return (color.t << 24  | color.r << 16 | color.g << 8 | color.b);
}

void put_trgb_color(t_color *color, int trgb)
{
	color->b = trgb;
	color->g = trgb << 8;
	color->r = trgb << 16;
	color->t = trgb << 24;
}

void change_color_aleatoire(t_fractol *fractol, t_color *col)
{
	col->r = (int)(col->r + 10 * M_PI * 179 / 43) % 255;
	col->g = (int)(col->g + 130 * 32 * M_PI / 110) % 255;
	col->b = (int)(col->b * 67 + 68 * M_PI / 71) % 255;
	fractol->rw = 1;
}

void swap_color(t_fractol *fractol)
{
	t_color tmp;

	tmp = fractol->col.out_from;
	fractol->col.out_from = fractol->col.out_to;
	fractol->col.out_to = tmp;
	fractol->rw = 1;
}

void ft_putcolor_to_pixel(t_fractol *fractol, int it, t_complexe z)
{
	t_color color;
	(void)z;
	long double i;

	if (it == fractol->precision)
	{
		color.r = fractol->col.in.r;
		color.g = fractol->col.in.g;
		color.b = fractol->col.in.b;
		color.t = fractol->col.in.t;
	}
	else
	{
		i = it + (long double)1 - logl(log2l(mod_complexe(z)));
		color.r = fractol->col.out_from.r + (fractol->col.out_to.r - fractol->col.out_from.r) * i / fractol->precision;
		color.g = fractol->col.out_from.g + (fractol->col.out_to.g - fractol->col.out_from.g) * i / fractol->precision;
		color.b = fractol->col.out_from.b + (fractol->col.out_to.b - fractol->col.out_from.b) * i / fractol->precision;
		color.t = 0;
	}
	fractol->addr[fractol->pixel] = color.b;
	fractol->addr[fractol->pixel + 1] = color.g;
	fractol->addr[fractol->pixel + 2] = color.r;
	fractol->addr[fractol->pixel + 3] = color.t;
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
	while (i < size)
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
	fractol->rw = 1;
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
				set_complexe(&c, fractol->h_s + x * fractol->pat, //setcomplexe(fractol,x,y);
							fractol->v_s - y * fractol->pat);
				next_mandelbrot(&fractol->grille[y][x].z, c); //fractol->fct(fractol, y, x)
				if (mod_complexe(fractol->grille[y][x].z) <= 2)
					fractol->grille[y][x].it += 1;
			}
			x++;
		}
		y++;
	}
	fractol->precision += 1;
	fractol->rw = 1;
}

void next_wtf(t_complexe *prec, t_complexe c)
{
	sq_complexe(prec);
	add_complexe(prec, *prec, c);
	sq_complexe(prec);
}

void ft_calc_wtf(t_complexe *z, t_complexe c, int *it, int it_max)
{
	int i;

	i = 0;
	while (i < it_max)
	{
		if (mod_sq_complexe(*z) > 200)
			break;
		next_wtf(z, c);
		i++;
	}
	*it = i;
}

void calc_z_it_value(t_complexe *z, int *it, t_fractol* fractol)
{
	t_complexe c;

	if (fractol->fract_type == mandelbrot)
	{
		set_complexe(z, 0, 0);
		ft_calc_mandelbrot(z, fractol->c, it, fractol->precision);
	}
	if (fractol->fract_type == julia)
	{
		*z = fractol->c;
		set_complexe(&c, fractol->h_s + fractol->m_x * fractol->pat,
					fractol->v_s - fractol->m_y * fractol->pat);
		ft_calc_mandelbrot(z, c, it, fractol->precision);
	}
	if (fractol->fract_type == wtf)
	{
		*z = fractol->c;
		set_complexe(&c, fractol->h_s + fractol->m_x * fractol->pat,
					fractol->v_s - fractol->m_y * fractol->pat);
		ft_calc_wtf(z, c, it, fractol->precision);
	}
}

void ft_calc_mandelbrot(t_complexe *z, t_complexe c, int *it, int it_max)
{
	int i;

	i = 0;
	while (i < it_max)
	{
		if (mod_sq_complexe(*z) > 200)
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

	fractol->rw = 0;
	y = 0;
	while (y < fractol->v_size)
	{
		x = 0;
		while (x < fractol->h_size)
		{
			if (fractol->grille[y][x].it == -1 || fractol->fract_type == julia || fractol->fract_type == wtf)
			{
				set_complexe(&(fractol->c), fractol->h_s + x * fractol->pat, 
					fractol->v_s - y * fractol->pat);
				//ft_calc_mandelbrot(&(fractol->grille[y][x].z), c, &(fractol->grille[y][x].it), fractol->precision);
				calc_z_it_value(&(fractol->grille[y][x].z), &(fractol->grille[y][x].it), fractol);
			}
			fractol->pixel = (y * fractol->line_length) + (x * 4);
			ft_putcolor_to_pixel(fractol, fractol->grille[y][x].it, fractol->grille[y][x].z);
			x++;
		}
		y++;
	}
	fractol->rwa = 0;
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void next_mandelbrot(t_complexe *prec, t_complexe c)
{
	sq_complexe(prec);
	add_complexe(prec, *prec, c);
}

void		print_info(t_fractol *fractol)
{
	ft_putendl_fd("Fractal : Mandelbrot", 1);
	ft_putstr_fd("Precision : ", 1);
	ft_putnbr_fd(fractol->precision, 1);
	ft_putendl_fd("",1);
	printf("Position (x,y) : %Lf, %Lf\n", fractol->h_s, fractol->v_s);
}