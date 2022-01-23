/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:17:03 by dmercadi          #+#    #+#             */
/*   Updated: 2022/01/23 16:17:05 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

void	calc_z_it_value(t_complexe *z, int *it, t_fct *fct)
{
	if (fct->fract_type == julia)
	{
		if (!*it)
			*z = fct->c;
		calc_mandelbrot(z, fct->mouse_c, it, fct);
	}
	else if (fct->fract_type == mandelbrot)
	{
		if (!*it)
			set_complexe(z, 0, 0);
		calc_mandelbrot(z, fct->c, it, fct);
	}
	else if (fct->fract_type == mandelbrot2)
	{
		if (!*it)
			set_complexe(z, 0, 0);
		calc_mandelbrot2(z, fct->c, it, fct);
	}
	else if (fct->fract_type == mandelbrot3)
	{
		if (!*it)
			set_complexe(z, 0, 0);
		calc_mandelbrot3(z, fct->c, it, fct);
	}
}

void	calc_mandelbrot(t_complexe *z, t_complexe c, int *it, t_fct *fct)
{
	long double		tmp;
	long double		tmp2;
	long double		tmp3;
	int				it_max;
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

void	calc_mandelbrot2(t_complexe *z, t_complexe c, int *it, t_fct *fct)
{
	long double		tmp;
	long double		tmp2;
	long double		tmp3;
	int				it_max;
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
		z->r = tmp2 - tmp3;
		z->i = z->i * tmp * 2.;
		tmp = z->r;
		z->r = z->r * z->r - z->i * z->i + c.r;
		z->i = z->i * tmp * 2. + c.i;
		(*it)++;
	}
}

void	calc_mandelbrot3(t_complexe *z, t_complexe c, int *it, t_fct *fct)
{
	long double		tmp;
	long double		tmp2;
	long double		tmp3;
	int				it_max;
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
		z->r = tmp2 - tmp3;
		z->i = z->i * tmp * 2.;
		tmp = z->r;
		z->r = z->r * z->r - z->i * z->i;
		z->i = z->i * tmp * 2.;
		tmp = z->r;
		z->r = z->r * z->r - z->i * z->i + c.r;
		z->i = z->i * tmp * 2. + c.i;
		(*it)++;
	}
}

void	calc(t_fct *fct)
{
	t_case	**ligne;
	t_case	*cell;

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
	mlx_put_image_to_window(fct->mlx, fct->win, fct->img, 0, 0);
}
