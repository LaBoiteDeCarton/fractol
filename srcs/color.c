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

void	put_trgb_color(t_color *color, int r, int g, int b)
{
	color->b = b;
	color->g = g;
	color->r = r;
	color->t = 0;
}

static void	ft_putcolor_to_pixel(t_color color, t_fct *fct)
{
	int	pixel;

	pixel = fct->pixel;
	fct->addr[pixel++] = color.b;
	fct->addr[pixel++] = color.g;
	fct->addr[pixel++] = color.r;
	fct->addr[pixel] = color.t;
}

void	ft_findcolor_to_pixel(t_fct *fct, int it, t_complexe z)
{
	t_color	color;
	t_color	*from;
	t_list	*tmp;
	double	i;
	double	ecarti;

	if (it >= fct->precision)
		color = *(t_color *)(fct->palette.in->content);
	else if (fct->palette.count == 1)
		color = *(t_color *)(fct->palette.out->content);
	else
	{
		i = it;
		if (fct->lissage)
			i = it + 1.0 - log(log2(sqrtl(z.r * z.r + z.i * z.i)));
		tmp = fct->palette.out;
		ecarti = (double)fct->precision / (double)(fct->palette.count - 1);
		while (i > ecarti)
		{
			tmp = tmp->next;
			i -= ecarti;
		}
		from = (t_color *)tmp->content;
		i /= ecarti;
		color.r = from->r + (((t_color *)tmp->next->content)->r - from->r) * i;
		color.g = from->g + (((t_color *)tmp->next->content)->g - from->g) * i;
		color.b = from->b + (((t_color *)tmp->next->content)->b - from->b) * i;
		color.t = 0;
	}
	ft_putcolor_to_pixel(color, fct);
}
