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

static void controls()
{
	printf("\n---controls---\n");
	printf("MOVE : Key Arrows\nFAST MOVE : Shift + Key Arrows\n");
	printf("ZOOM : Mouse Scroll\nADD PRECISION : Press 'P'\n");
	printf("LESS PRECISIONS : Press ':'\nON/OFF COLOR MENU : Press 'C'\n");
	printf("ON/OFF SMOOTH : Press 'L'\n");
	printf("\n---Inside the color menu---\n");
	printf("Press 1 to select previous color\n");
	printf("Press 2 to select next color\n");
	printf("Press 3 to add a new color\n");
	printf("HOLD the space bar to select the color inside the fractal\n");
	printf("Move your mouse horizontally to change R value of the color\n");
	printf("Move your mouse vertically to change G value of the color\n");
	printf("Scroll your mouse up and down to change B value of the color\n\n");
}

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
	controls();
	mlx_loop(fct.mlx);
	return (0);
}
