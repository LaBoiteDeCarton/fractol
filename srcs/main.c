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
	fct->keys.k_space = 0;
	fct->keys.k_t = 0;
}

static void	put_default_arg(t_fct *fct)
{
	fct->h_size = H_LARGE_SIZE;
	fct->v_size = V_LARGE_SIZE;
	malloc_grille(fct);
	init_grille(fct);
	fct->precision = 30;
	fct->escape = 4;
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
	fct->col.palette = NULL;
	fct->col.inside = NULL;
	fct->lissage = 1;
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
	else if (!ft_strncmp(str, "mandelbrot2", 12))
		fct->fract_type = mandelbrot2;
	else if (!ft_strncmp(str, "mandelbrot3", 12))
		fct->fract_type = mandelbrot3;
	else
		handle_error(ERR_FRACTTYPE, fct);
}

static void init_second_arg(char *str, t_fct *fct)
{
	if (!ft_strisdigit(str))
		handle_error(ERR_UINT, fct);
	if (ft_strlen(str) > 4)
		handle_error(ERR_TOOBIG, fct);
	fct->precision = ft_atoi(str);
	if (fct->precision < 0)
		handle_error(ERR_RANGE, fct);
}

static void init_third_arg(char *str, t_fct *fct)
{
	if (!ft_strisdigit(str))
		handle_error(ERR_UINT, fct);
	if (ft_strlen(str) > 4)
		handle_error(ERR_TOOBIG, fct);
	fct->precision = ft_atoi(str);
	if (fct->precision < 0)
		handle_error(ERR_RANGE, fct);
}

// static void	init_arg_coord(char *str1, char *str2, char *str3, t_fct *fct)
// {
// 	if (!ft_strisld(str1) || !ft_strisld(str2) || !ft_strisld(str3))
// 		handle_error(ERR_COORD_TYPE);
// 	fct->h_s = ft_strtold(str1);
// 	fct->v_s = ft_strtold(str2);
// 	fct->pat = ft_strtold(str3);
// }

static void	init_arg_fct(int ac, char **av, t_fct *fct)
{
	if (ac <= 0)
		handle_error(ERR_NOARG, fct);
	if (ac > 3)
		handle_error(ERR_TOOMUCHARG, fct);
	init_first_arg(av[0], fct);
	put_default_arg(fct);
	if (ac > 1)
		init_second_arg(av[1], fct);
	if (ac > 2)
		init_third_arg(av[2], fct);
	// if (ac == 3 || ac == 4)
	// 	handle_error(ERR_COORD2);
	// if (ac > 4)
	// 	init_arg_coord(av[2], av[3], av[4], fct);
}

void	start_mlx(t_fct *fct)
{
	fct->mlx = mlx_init(); //faire des if(!fct->mlx) ??
	if (!fct->mlx)
		handle_error(ERR_MALLOC, fct);
	fct->win = mlx_new_window(fct->mlx, fct->h_size, fct->v_size,
			"fractol - 42 Project");
	if (!fct->win)
		handle_error(ERR_MALLOC, fct);
	fct->img = mlx_new_image(fct->mlx, fct->h_size, fct->v_size);
	if (!fct->img)
		handle_error(ERR_MALLOC, fct);
	fct->addr = mlx_get_data_addr(fct->img, &fct->bits_per_pixel, &fct->line_length,
			&fct->endian);
}

int	main(int ac, char **av)
{
	t_fct	fct;

	fct.mlx = NULL;
	fct.win = NULL;
	fct.img = NULL;
	fct.addr = NULL;
	fct.col_mod = NULL;
	fct.grille = NULL;
	init_arg_fct(ac - 1, av + 1, &fct);
	start_mlx(&fct);
	mlx_hook(fct.win, 2, 1L << 0, ft_key_hook, &fct);
	mlx_hook(fct.win, 3, 1L << 1, ft_key_release, &fct);
	mlx_mouse_hook(fct.win, ft_mouse_hook, &fct);
	mlx_loop_hook(fct.mlx, ft_loop_hook, &fct);
	mlx_loop(fct.mlx);
	return (0);
}
