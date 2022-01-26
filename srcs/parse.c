#include "fct.h"

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
	fct->active_mouse = 0;
	if (fct->fract_type == julia)
		fct->active_mouse = 1;
	fct->m_x = 500;
	fct->m_y = 500;
	fct->rw = 1;
	fct->rwa = 0;
	fct->h_s = -2.25 + 0.25 * (fct->fract_type == julia);
	fct->v_s = 1.25 + 0.1 * (fct->fract_type == julia);
	fct->color_set = white;
	fct->lissage = 1;
	fct->i_cm = 0;
	create_palette(fct);
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

static int	parse_intarg(char *str, t_fct *fct)
{
	int ret;

	if (!ft_strisdigit(str))
		handle_error(ERR_UINT, fct);
	if (ft_strlen(str) > 4)
		handle_error(ERR_TOOBIG, fct);
	ret = ft_atoi(str);
	if (ret < 0)
		handle_error(ERR_RANGE, fct);
	return (ret);
}

void	init_arg_fct(int ac, char **av, t_fct *fct)
{
	fct->mlx = NULL;
	fct->win = NULL;
	fct->img = NULL;
	fct->addr = NULL;
	fct->col_mod = NULL;
	fct->grille = NULL;
	fct->palette.in = NULL;
	fct->palette.out = NULL;
	if (ac <= 0)
		handle_error(ERR_NOARG, fct);
	if (ac > 2)
		handle_error(ERR_TOOMUCHARG, fct);
	init_first_arg(av[0], fct);
	put_default_arg(fct);
	if (ac > 1)
		fct->precision = parse_intarg(av[1], fct);
}