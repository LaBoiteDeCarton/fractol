#include "fractol.h"

void move_down(t_fractol *fractol, int y)
{
	int i;
	t_case **save;

	save = (t_case **)malloc(sizeof(t_case *) * y);
	fractol->v_s -= fractol->pat * y;
	i = 0;
	while (i < y)
	{
		save[i] = fractol->grille[i];
		i++;
	}
	ft_memmove(fractol->grille, fractol->grille + y, sizeof(t_case **) * (fractol->v_size - y));
	i = 0;
	while (i < y)
	{
		fractol->grille[fractol->v_size - 1 - i] = save[i];
		reset_ligne(fractol->grille[fractol->v_size - 1 - i], fractol->h_size);
		i++;
	}
	fractol->rw = 1;
}

void		move_up(t_fractol *fractol, int y)
{
	int i;
	t_case **save;

	save = (t_case **)malloc(sizeof(t_case *) * y);
	fractol->v_s += fractol->pat * y;
	i = 0;
	while (i < y)
	{
		save[i] = fractol->grille[fractol->v_size - 1 - i];
		i++;
	}
	ft_memmove(fractol->grille + y, fractol->grille, sizeof(t_case **) * (fractol->v_size - y));
	i = 0;
	while (i < y)
	{
		fractol->grille[i] = save[y - 1 - i];
		reset_ligne(fractol->grille[i], fractol->h_size);
		i++;
	}
	fractol->rw = 1;
}

void		move_left(t_fractol *fractol, int speed)
{
	int i;
	int j;

	fractol->h_s -= fractol->pat * speed;
	i = 0;
	while (i < fractol->v_size)
	{
		j = fractol->h_size - 1;
		while (j >= speed)
		{
			fractol->grille[i][j] = fractol->grille[i][j-speed]; 
			j--;
		}
		while (j >= 0)
		{	
			fractol->grille[i][j].it = -1;
			j--;
		}
		i++;
	}
	fractol->rw = 1;
}

void		move_right(t_fractol *fractol, int speed)
{
	int i;
	int j;

	fractol->h_s += fractol->pat * speed;
	i = 0;
	while (i < fractol->v_size)
	{
		j = 0;
		while (j < fractol->h_size - speed)
		{
			fractol->grille[i][j] = fractol->grille[i][j + speed]; 
			j++;
		}
		while (j < fractol->h_size)
		{
			fractol->grille[i][j].it = -1;
			j++;
		}
		i++;
	}
	fractol->rw = 1;
}