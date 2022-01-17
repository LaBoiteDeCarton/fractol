#include "fct.h"

void	calc_z_it_value(t_complexe *z, unsigned int *it, t_fct *fct)
{
	if (fct->fract_type == mandelbrot)
	{
		if (!*it)
			set_complexe(z, 0, 0);
		ft_calc_mandelbrot(z, fct->c, it, fct->precision);
	}
	if (fct->fract_type == julia)
	{
		if (!*it)
			*z = fct->c;
		ft_calc_mandelbrot(z, fct->mouse_c, it, fct->precision);
	}
	if (fct->fract_type == mandelbrot2)
	{
		if (!*it)
			set_complexe(z, 0, 0);
		ft_calc_mandelbrot2(z, fct->c, it, fct->precision);
	}
	if (fct->fract_type == mandelbrot3)
	{
		if (!*it)
			set_complexe(z, 0, 0);
		ft_calc_mandelbrot3(z, fct->c, it, fct->precision);
	}
}

void	ft_calc_mandelbrot(t_complexe *z, t_complexe c, unsigned int *it, unsigned int it_max)
{
	while (*it < it_max)
	{
		if (z->r * z->r + z->i * z->i > 4)
			break ;
		next_mandelbrot(z, c);
		(*it)++;
	}
}

void	next_mandelbrot2(t_complexe *prec, t_complexe c)
{
	sq_complexe(prec);
	sq_complexe(prec);
	add_complexe(prec, *prec, c);
}

void	next_mandelbrot3(t_complexe *prec, t_complexe c)
{
	sq_complexe(prec);
	sq_complexe(prec);
	sq_complexe(prec);
	add_complexe(prec, *prec, c);
}

void	ft_calc_mandelbrot2(t_complexe *z, t_complexe c, unsigned int *it, unsigned int it_max)
{
	while (*it < it_max)
	{
		if (z->r * z->r + z->i * z->i > 4)
			break ;
		next_mandelbrot2(z, c);
		(*it)++;
	}
}

void	ft_calc_mandelbrot3(t_complexe *z, t_complexe c, unsigned int *it, unsigned int it_max)
{
	while (*it < it_max)
	{
		if (z->r * z->r + z->i * z->i > 4)
			break ;
		next_mandelbrot3(z, c);
		(*it)++;
	}
}

void	calc(t_fct *fct)
{
	int	x;
	int	y;

	fct->rw = 0;
	y = 0;
	while (y < fct->v_size)
	{
		x = 0;
		while (x < fct->h_size)
		{
			set_complexe(&(fct->c), fct->h_s + x * fct->pat,
				fct->v_s - y * fct->pat);
			if (fct->rwa)
				fct->grille[y][x].it = 0;
			calc_z_it_value(&(fct->grille[y][x].z), &(fct->grille[y][x].it), fct);
			fct->pixel = (y * fct->line_length) + (x * 4);
			ft_findcolor_to_pixel(fct, fct->grille[y][x].it, fct->grille[y][x].z);
			x++;
		}
		y++;
	}
	fct->rwa = 0;
	mlx_put_image_to_window(fct->mlx, fct->win, fct->img, 0, 0);
}

void	next_mandelbrot(t_complexe *prec, t_complexe c)
{
	sq_complexe(prec);
	add_complexe(prec, *prec, c);
}

void	print_one_color(void *color) //TODELETE
{
	printf("(t, r, g, b) : (%d, %d, %d, %d)\n",
		((t_color *)color)->t,
		((t_color *)color)->r,
		((t_color *)color)->g,
		((t_color *)color)->b);
}

void	print_colors(t_fct *fct) // TO DELETE
{
	printf("outside colors : \n");
	ft_lstiter(fct->col.palette, &print_one_color);
	printf("inside color : \n");
	ft_lstiter(fct->col.inside, &print_one_color);
}

void	print_info(t_fct *fct) //TO DELETE
{
	ft_putendl_fd("Fractal : Mandelbrot", 1);
	ft_putstr_fd("Precision : ", 1);
	ft_putnbr_fd(fct->precision, 1);
	ft_putendl_fd("", 1);
	printf("Pat : %.20Lf\n", fct->pat);
	printf("Position (x,y) : %Lf, %Lf\n", fct->h_s, fct->v_s);
	print_colors(fct);
}
