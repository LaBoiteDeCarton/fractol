/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:17:34 by dmercadi          #+#    #+#             */
/*   Updated: 2022/01/23 16:17:35 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"
#include "mlx.h"
#include "libft.h"

static void	start_mlx(t_fct *fct)
{
	fct->mlx = mlx_init();
	if (!fct->mlx)
		handle_error(ERR_MALLOC, fct);
	fct->win = mlx_new_window(fct->mlx, fct->h_size, fct->v_size,
			"fractol - 42 Project");
	if (!fct->win)
		handle_error(ERR_MALLOC, fct);
	fct->img = mlx_new_image(fct->mlx, fct->h_size, fct->v_size);
	if (!fct->img)
		handle_error(ERR_MALLOC, fct);
	fct->addr = mlx_get_data_addr(fct->img, &fct->bits_per_pixel,
			&fct->line_length, &fct->endian);
}

int	main(int ac, char **av)
{
	t_fct	fct;

	init_arg_fct(ac - 1, av + 1, &fct);
	start_mlx(&fct);
	mlx_hook(fct.win, 2, 1L << 0, ft_key_hook, &fct);
	mlx_hook(fct.win, 3, 1L << 1, ft_key_release, &fct);
	mlx_mouse_hook(fct.win, ft_mouse_hook, &fct);
	mlx_loop_hook(fct.mlx, ft_loop_hook, &fct);
	mlx_loop(fct.mlx);
	return (0);
}
