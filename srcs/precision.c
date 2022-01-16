#include "fct.h"

void	sub_precision(t_fct *fct)
{
	int	x;
	int	y;

	if (fct->precision)
		fct->precision -= 1;
	y = 0;
	while (y < fct->v_size)
	{
		x = 0;
		while (x < fct->h_size)
		{
			if (fct->grille[y][x].it == fct->precision)
			{
				set_complexe(&(fct->c), fct->h_s + x * fct->pat,
					fct->v_s - y * fct->pat);
				calc_z_it_value(&(fct->grille[y][x].z), &(fct->grille[y][x].it), fct);
			}
			x++;
		}
		y++;
	}
	fct->rw = 1;
}

void	add_precision(t_fct *fct)
{
	fct->precision += 1;
	fct->rw = 1;
}
