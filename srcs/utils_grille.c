/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_grille.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:17:57 by dmercadi          #+#    #+#             */
/*   Updated: 2022/01/23 16:17:58 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

void	malloc_grille(t_fct *fct)
{
	int	i;

	fct->grille = (t_case **)malloc(sizeof(t_case *) * (fct->v_size + 1));
	if (!fct->grille)
		handle_error(ERR_MALLOC, fct);
	i = 0;
	while (i < fct->v_size)
	{
		fct->grille[i] = NULL;	
		fct->grille[i] = (t_case *)malloc(sizeof(t_case) * (fct->h_size + 1));
		if (!fct->grille[i])
		{
			while (--i >= 0)
				free(fct->grille[i]);
			handle_error(ERR_MALLOC, fct);
		}
		fct->grille[i][fct->h_size].it = -1;
		i++;
	}
	fct->grille[fct->v_size] = NULL;
}

void	free_grille(t_fct *fct)
{
	int	i;

	i = 0;
	while (i <= fct->v_size)
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
