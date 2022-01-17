#include "fct.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_trgb_color(t_color *color, int r, int g, int b)
{
	color->b = b;
	color->g = g;
	color->r = r;
	color->t = 0;
}

static void	ft_putcolor_to_pixel(t_color color, t_fct *fct)
{
	fct->addr[fct->pixel] = color.b;
	fct->addr[fct->pixel + 1] = color.g;
	fct->addr[fct->pixel + 2] = color.r;
	fct->addr[fct->pixel + 3] = color.t;
}

void	ft_findcolor_to_pixel(t_fct *fct, unsigned int it, t_complexe z)
{
	t_color	color;
	t_color	*from;
	t_color	*to;
	t_list	*tmp;
	double	i;

	if (it >= fct->precision)
		color = *((t_color *)fct->col.inside->content);
	else if (fct->col.count == 1)
		color = *(t_color *)(fct->col.palette->content);
	else
	{
		i = it;
		if (fct->lissage)
			i = it + 1.0 - log(log2(mod_complexe(z)));
		tmp = fct->col.palette;
		while (i > (double)fct->precision / ((double)(fct->col.count - 1)))
		{
			tmp = tmp->next;
			i -= (double)fct->precision / ((double)(fct->col.count - 1));
		}
		from = (t_color *)tmp->content;
		to = (t_color *)tmp->next->content;
		i = i / ((double)fct->precision / ((double)fct->col.count - 1.0));
		color.r = from->r + (to->r - from->r) * i;
		color.g = from->g + (to->g - from->g) * i;
		color.b = from->b + (to->b - from->b) * i;
		color.t = from->t + (to->t - from->t) * i;
	}
	ft_putcolor_to_pixel(color, fct);
}

void	detsroy_panel_color(t_fct *fct)
{
	if (fct->col.palette)
		ft_lstclear(&(fct->col.palette), free);
	if (fct->col.inside)
		ft_lstclear(&(fct->col.palette), free);
}
