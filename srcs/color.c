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

void	ft_findcolor_to_pixel(t_fct *fct, int it, t_complexe z)
{
	t_color	color;
	t_color	*from;
	t_color	*to;
	t_list	*tmp;
	long double	i;

	if (it == fct->precision)
		put_trgb_color(&color, 0, 0, 0);
	else if (fct->col.count == 1)
		color = *(t_color *)(fct->col.palette->content);
	else
	{
		i = it + (long double)1 - logl(log2l(mod_complexe(z)));
		tmp = fct->col.palette;
		while (i > (long double)fct->precision / ((long double)fct->col.count - (long double)1.0))
		{
			tmp = tmp->next;
			i -= (long double)fct->precision / ((long double)fct->col.count - (long double)1.0);
		}
		from = (t_color *)tmp->content;
		to = (t_color *)tmp->next->content;
		color.r = from->r + (to->r - from->r) * i / ((long double)fct->precision / ((long double)fct->col.count - (long double)1.0));
		color.g = from->g + (to->g - from->g) * i / ((long double)fct->precision / ((long double)fct->col.count - (long double)1.0));
		color.b = from->b + (to->b - from->b) * i / ((long double)fct->precision / ((long double)fct->col.count - (long double)1.0));
		color.t = 0;
	}
	ft_putcolor_to_pixel(color, fct);
}

void	detsroy_panel_color(t_fct *fct)
{
	if (fct->col.palette)
		ft_lstclear(&(fct->col.palette), free);
}
