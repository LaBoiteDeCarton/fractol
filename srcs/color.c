/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:16:50 by dmercadi          #+#    #+#             */
/*   Updated: 2022/01/23 16:16:53 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

t_color	new_color(int r, int g, int b)
{
	t_color color;

	put_trgb_color(&color, r, g, b);
	return (color);
}

void	put_trgb_color(t_color *color, int r, int g, int b)
{
	color->b = b;
	color->g = g;
	color->r = r;
	color->t = 0;
}

void	ft_putcolor_to_pixel(t_color color, char *addr, int pixel)
{
	addr[pixel++] = color.b;
	addr[pixel++] = color.g;
	addr[pixel++] = color.r;
	addr[pixel] = 0;
}

static t_color	smooth_color(t_color from, t_color to, double i)
{
	t_color color;

	color.r = from.r + (to.r - from.r) * i;
	color.g = from.g + (to.g - from.g) * i;
	color.b = from.b + (to.b - from.b) * i;
	return (color);
}

void	ft_findcolor_to_pixel(t_fct *fct, double it, t_complexe z)
{
	t_color	color;
	t_color	*from;
	t_list	*tmp;
	double	ecarti;

	if ((int)it >= fct->precision)
		color = *(t_color *)(fct->palette.in->content);
	else if (fct->palette.count == 1)
		color = *(t_color *)(fct->palette.out->content);
	else
	{
		if (fct->lissage)
			it = it + 1.0 - log(log2(sqrt(z.r * z.r + z.i * z.i)));
		tmp = fct->palette.out;
		ecarti = (double)fct->precision / (double)(fct->palette.count - 1);
		while (it > ecarti)
		{
			tmp = tmp->next;
			it -= ecarti;
		}
		from = (t_color *)tmp->content;
		it /= ecarti;
		color = smooth_color(*(t_color *)tmp->content,*(t_color *)tmp->next->content, it);
	}
	ft_putcolor_to_pixel(color, fct->addr, fct->pixel);
}
