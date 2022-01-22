#include "fct.h"

void	move_down(t_fct *fct, int y)
{
	int		i;
	t_case	**save;

	save = NULL;
	save = (t_case **)malloc(sizeof(t_case *) * y);
	if (!save)
		handle_error(ERR_MALLOC, fct);
	fct->v_s -= fct->pat * y;
	i = 0;
	while (i < y)
	{
		save[i] = fct->grille[i];
		i++;
	}
	ft_memmove(fct->grille, fct->grille + y, sizeof(t_case **) * (fct->v_size - y));
	i = 0;
	while (i < y)
	{
		fct->grille[fct->v_size - 1 - i] = save[i];
		reset_ligne(fct->grille[fct->v_size - 1 - i], fct->h_size);
		i++;
	}
	fct->rw = 1;
}

void	move_up(t_fct *fct, int y)
{
	int		i;
	t_case	**save;

	save = NULL;
	save = (t_case **)malloc(sizeof(t_case *) * y);
	if (!save)
		handle_error(ERR_MALLOC, fct);
	fct->v_s += fct->pat * y;
	i = 0;
	while (i < y)
	{
		save[i] = fct->grille[fct->v_size - 1 - i];
		i++;
	}
	ft_memmove(fct->grille + y, fct->grille, sizeof(t_case **) * (fct->v_size - y));
	i = 0;
	while (i < y)
	{
		fct->grille[i] = save[y - 1 - i];
		reset_ligne(fct->grille[i], fct->h_size);
		i++;
	}
	fct->rw = 1;
}

void	move_left(t_fct *fct, int speed)
{
	int	i;
	int	j;

	fct->h_s -= fct->pat * speed;
	i = 0;
	while (i < fct->v_size)
	{
		j = fct->h_size - 1;
		while (j >= speed)
		{
			fct->grille[i][j] = fct->grille[i][j - speed]; 
			j--;
		}
		while (j >= 0)
		{	
			fct->grille[i][j].it = 0;
			j--;
		}
		i++;
	}
	fct->rw = 1;
}

void	move_right(t_fct *fct, int speed)
{
	int	i;
	int	j;

	fct->h_s += fct->pat * speed;
	i = 0;
	while (i < fct->v_size)
	{
		j = 0;
		while (j < fct->h_size - speed)
		{
			fct->grille[i][j] = fct->grille[i][j + speed];
			j++;
		}
		while (j < fct->h_size)
		{
			fct->grille[i][j].it = 0;
			j++;
		}
		i++;
	}
	fct->rw = 1;
}
