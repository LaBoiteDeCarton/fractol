#include "fct.h"

void	calc_z_it_value(t_complexe *z, int *it, t_fct *fct)
{
	if (fct->fract_type == mandelbrot)
	{
		if (!*it)
			set_complexe(z, 0, 0);
		ft_calc_mandelbrot(z, fct->c, it, fct);
	}
	else if (fct->fract_type == julia)
	{
		if (!*it)
			*z = fct->c;
		ft_calc_mandelbrot(z, fct->mouse_c, it, fct);
	}
	else if (fct->fract_type == mandelbrot2)
	{
		if (!*it)
			set_complexe(z, 0, 0);
		ft_calc_mandelbrot2(z, fct->c, it, fct);
	}
	else if (fct->fract_type == mandelbrot3)
	{
		if (!*it)
			set_complexe(z, 0, 0);
		ft_calc_mandelbrot3(z, fct->c, it, fct);
	}
}

void	ft_calc_mandelbrot(t_complexe *z, t_complexe c, int *it, t_fct *fct)
{
	long double		tmp;
	long double		tmp2;
	long double		tmp3;
	int	it_max;
	unsigned int	escape;

	it_max = fct->precision;
	escape = fct->escape;
	while (*it < it_max)
	{
		tmp2 = z->r * z->r;
		tmp3 = z->i * z->i;
		if (tmp2 + tmp3 > escape)
			break ;
		tmp = z->r;
		z->r = tmp2 - tmp3 + c.r;
		z->i = z->i * tmp * 2. + c.i;
		(*it)++;
	}
}

void	next_mandelbrot(t_complexe *prec, t_complexe c)
{
	sq_complexe(prec);
	add_complexe(prec, *prec, c);
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

void	ft_calc_mandelbrot2(t_complexe *z, t_complexe c, int *it, t_fct *fct)
{
	while (*it < fct->precision)
	{
		if (z->r * z->r + z->i * z->i > fct->escape)
			break ;
		next_mandelbrot2(z, c);
		(*it)++;
	}
}

void	ft_calc_mandelbrot3(t_complexe *z, t_complexe c, int *it, t_fct *fct)
{
	while (*it < fct->precision)
	{
		if (z->r * z->r + z->i * z->i > fct->escape)
			break ;
		next_mandelbrot3(z, c);
		(*it)++;
	}
}

void	calc(t_fct *fct)
{
	t_case	**ligne;
	t_case	*cell;

	fct->rw = 0;
	ligne = fct->grille;
	fct->c.i = fct->v_s;
	fct->pixel = 0;
	while (*ligne)
	{
		cell = *ligne;
		fct->c.r = fct->h_s;
		while (cell->it >= 0)
		{
			if (fct->rwa)
				cell->it = 0;
			calc_z_it_value(&(cell->z), &(cell->it), fct);
			ft_findcolor_to_pixel(fct, cell->it, cell->z);
			fct->c.r += fct->pat;
			cell++;
			fct->pixel += 4;
		}
		fct->c.i -= fct->pat;
		ligne++;
	}
	fct->rwa = 0;
	mlx_put_image_to_window(fct->mlx, fct->win, fct->img, 0, 0);
}
