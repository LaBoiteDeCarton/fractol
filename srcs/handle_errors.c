/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:17:21 by dmercadi          #+#    #+#             */
/*   Updated: 2022/01/23 16:17:23 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

void	free_col(void *col)
{
	free((t_color *)col);
}

void	handle_error(char *err, t_fct *fct)
{
	freee(fct);
	printf("%s\n%s\n", err, EXEC_PROTO);
	exit(0);
}

void	freee(t_fct *fct)
{
	if (fct->win)
	{
		mlx_destroy_image(fct->mlx, fct->img);
		mlx_destroy_window(fct->mlx, fct->win);
	}
	detsroy_palette(fct);
	if (fct->grille)
		free_grille(fct);
}
