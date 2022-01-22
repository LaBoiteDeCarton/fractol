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
	t_color	*to;
	t_list	*tmp;
	double	i;
	double	ecarti;

	if (it >= fct->precision)
		color = *(t_color *)(fct->col.inside->content);
	else if (fct->col.count == 1)
		color = *(t_color *)(fct->col.palette->content);
	else
	{
		i = it;
		if (fct->lissage)
			i = it + 1.0 - log(log2(sqrtl(z.r * z.r + z.i * z.i)));
		tmp = fct->col.palette;
		ecarti = (double)fct->precision / (double)(fct->col.count - 1);
		while (i > ecarti)
		{
			tmp = tmp->next;
			i -= ecarti;
		}
		from = (t_color *)tmp->content;
		to = (t_color *)tmp->next->content;
		i /= ecarti;
		color.r = from->r + (to->r - from->r) * i;
		color.g = from->g + (to->g - from->g) * i;
		color.b = from->b + (to->b - from->b) * i;
		color.t = 0;
	}
	ft_putcolor_to_pixel(color, fct);
}

void	detsroy_panel_color(t_fct *fct)
{
	if (fct->col.palette)
		ft_lstclear(&(fct->col.palette), free);
	if (fct->col.inside)
		ft_lstclear(&(fct->col.palette), free);
	fct->col.count = 0;
}
