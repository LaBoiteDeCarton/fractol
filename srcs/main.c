#include "fct.h"
#include "mlx.h"
#include "libft.h"

static void	init_keys(t_fct *fct)
{
	fct->keys.k_m = 0;
	fct->keys.k_p = 0;
	fct->keys.k_a_down = 0;
	fct->keys.k_a_left = 0;
	fct->keys.k_a_right = 0;
	fct->keys.k_a_up = 0;
	fct->keys.k_shift = 0;
	fct->keys.k_shift2 = 0;
}

static void	malloc_grille(t_fct *fct)
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

static void	put_default_arg(t_fct *fct)
{
	fct->h_size = H_LARGE_SIZE;
	fct->v_size = V_LARGE_SIZE;
	malloc_grille(fct);
	init_grille(fct);
	fct->precision = 30;
	fct->active_mouse = 0;
	if (fct->fract_type == julia)
		fct->active_mouse = 1;
	fct->m_x = 500;
	fct->m_y = 500;
	fct->rw = 1;
	fct->rwa = 0;
	fct->h_s = -2.25;
	fct->v_s = 1.25;
	fct->color_set = white;
	fct->blue = 0;
	create_panel(fct);
	fct->col_panel_active = 0;
	init_keys(fct);
	fct->pat = 2.75 / fct->v_size;
	set_complexe(&fct->mouse_c, fct->h_s + fct->m_x * fct->pat,
		fct->v_s - fct->m_y * fct->pat);
}

static void	init_first_arg(char *str, t_fct *fct)
{
	if (!ft_strncmp(str, "mandelbrot", 11))
		fct->fract_type = mandelbrot;
	else if (!ft_strncmp(str, "julia", 5))
		fct->fract_type = julia;
	else if (!ft_strncmp(str, "wtf", 3))
		fct->fract_type = wtf;
	else
		handle_error(ERR_FRACTTYPE);
}

static void	init_arg_fct(int ac, char **av, t_fct *fct)
{
	if (ac <= 0)
		handle_error(ERR_NOARG);
	init_first_arg(av[0], fct);
	if (ac > 1)
		handle_error(ERR_TOOMUCHARG);
	put_default_arg(fct);
}

int	main(int ac, char **av)
{
	t_fct	fct;

	init_arg_fct(ac - 1, av + 1, &fct);
	fct.mlx = mlx_init();
	fct.win = mlx_new_window(fct.mlx, fct.h_size, fct.v_size,
			"fractol - 42 Project");
	fct.img = mlx_new_image(fct.mlx, fct.h_size, fct.v_size);
	fct.addr = mlx_get_data_addr(fct.img, &fct.bits_per_pixel, &fct.line_length,
			&fct.endian);
	mlx_hook(fct.win, 2, 1L << 0, ft_key_hook, &fct);
	mlx_hook(fct.win, 3, 1L << 1, ft_key_release, &fct);
	mlx_mouse_hook(fct.win, ft_mouse_hook, &fct);
	mlx_loop_hook(fct.mlx, ft_loop_hook, &fct);
	mlx_loop(fct.mlx);
	return (0);
}
