#include "fct.h"

void	malloc_grille(t_fct *fct)
{
	int	i;

	fct->grille = (t_case **)malloc(sizeof(t_case *) * fct->v_size);
	if (!fct->grille)
		handle_error(ERR_MALLOC);
	i = 0;
	while (i < fct->v_size)
	{
		fct->grille[i] = (t_case *)malloc(sizeof(t_case) * fct->h_size);
		if (!fct->grille[i])
		{
			while (--i >= 0) //bien verifier que le free fait tout frire
				free(fct->grille[i]);
			handle_error(ERR_MALLOC);
		}
		i++;
	}
}

void	free_grille(t_fct *fct)
{
	int	i;

	i = 0;
	while (i < fct->v_size)
	{
		free(fct->grille[i]);
		i++;
	}
	free(fct->grille);
}

void	init_grille(t_fct *fct)
{
	int	x;
	int	y;

	y = 0;
	while (y < fct->v_size)
	{
		x = 0;
		while (x < fct->h_size)
		{
			fct->grille[y][x].it = 0;
			fct->grille[y][x].z.r = 0;
			fct->grille[y][x].z.i = 0;
			x++;
		}
		y++;
	}
}

void	reset_ligne(t_case *cases, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		cases->it = 0;
		cases++;
		i++;
	}
}