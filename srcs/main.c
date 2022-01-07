#include "fractol.h"
#include "mlx.h"
#include "libft.h"

static void	init_keys(t_fractol *fractol)
{
	fractol->keys.k_m = 0;
	fractol->keys.k_p = 0;
	fractol->keys.k_a_down = 0;
	fractol->keys.k_a_left = 0;
	fractol->keys.k_a_right = 0;
	fractol->keys.k_a_up = 0;
	fractol->keys.k_shift = 0;
	fractol->keys.k_shift2 = 0;
}

void malloc_grille(t_fractol *fractol)
{
	int i;
	fractol->grille = (t_case **)malloc(sizeof(t_case *) * fractol->v_size);
	if (!fractol->grille)
		handle_error(ERR_MALLOC);
	i = 0;
	while (i < fractol->v_size)
	{
		fractol->grille[i] = (t_case *)malloc(sizeof(t_case) * fractol->h_size);
		if (!fractol->grille[i])
		{
			while (--i >= 0) //bien verifier que le free fait tout frire
				free(fractol->grille[i]);
			handle_error(ERR_MALLOC);
		}
		i++;
	}
}

static void put_default_arg(t_fractol *fractol)
{
	fractol->h_size = H_LARGE_SIZE;
	fractol->v_size = V_LARGE_SIZE;
	malloc_grille(fractol);
	init_grille(fractol);
	fractol->precision = 30;
	fractol->active_mouse = 0;
	if (fractol->fract_type == julia)
		fractol->active_mouse = 1;
	fractol->m_x = 1000;
	fractol->m_y = 500;
	fractol->rw = 1;
	fractol->rwa = 0;
	fractol->h_s = -2.25;
	fractol->v_s = 1.25;
	t_color *first;
	first = malloc(sizeof(t_color));
	first->r = 255;
	first->g = 255;
	first->b = 255;
	first->t = 0;
	fractol->col.palette = ft_lstnew(first);
	fractol->col.count = 1;
	init_keys(fractol);
	fractol->pat = 2.75 / fractol->v_size;	
	set_complexe(&fractol->mouse_c, fractol->h_s + fractol->m_x * fractol->pat,
					fractol->v_s - fractol->m_y * fractol->pat);
}

static void init_first_arg(char *str, t_fractol *fractol)
{
	if (!ft_strncmp(str, "mandelbrot", 11))
		fractol->fract_type = mandelbrot;
	else if (!ft_strncmp(str, "julia", 5))
		fractol->fract_type = julia;
	else if (!ft_strncmp(str, "wtf", 3))
		fractol->fract_type = wtf;
	else
		handle_error(ERR_FRACTTYPE);
}

static void init_arg_fractol(int ac, char **av, t_fractol *fractol)
{
	if (ac <= 0)
		handle_error(ERR_NOARG);
	init_first_arg(av[0],fractol);
	if (ac > 1)
		handle_error(ERR_TOOMUCHARG);
	put_default_arg(fractol);
}



int main(int ac, char **av)
{
	t_fractol fractol;

	init_arg_fractol(ac - 1, av + 1, &fractol);
	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, fractol.h_size, fractol.v_size, "Fractol - 42 Project");
	fractol.img = mlx_new_image(fractol.mlx, fractol.h_size, fractol.v_size);
	fractol.addr = mlx_get_data_addr(fractol.img, &fractol.bits_per_pixel, &fractol.line_length,
								&fractol.endian);
	mlx_hook(fractol.win, 2, 1L<<0, ft_key_hook, &fractol);
	mlx_hook(fractol.win, 3, 1L<<1, ft_key_release, &fractol);
	mlx_mouse_hook(fractol.win, ft_mouse_hook, &fractol);
	mlx_loop_hook(fractol.mlx, ft_loop_hook, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
