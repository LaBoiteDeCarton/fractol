#include "fct.h"

void	calc_z_it_value(t_complexe *z, unsigned int *it, t_fct *fct)
{
	if (fct->fract_type == mandelbrot)
	{
		if (!*it)
			set_complexe(z, 0, 0);
		ft_calc_mandelbrot(z, fct->c, it, fct->precision);
	}
	if (fct->fract_type == julia)
	{
		if (!*it)
			*z = fct->c;
		ft_calc_mandelbrot(z, fct->mouse_c, it, fct->precision);
	}
}

// void change_color_aleatoire(t_fct *fct, t_color *col)
// {
// 	col->r = (int)(col->r + 10 * M_PI * 179 / 43) % 255;
// 	col->g = (int)(col->g + 130 * 32 * M_PI / 110) % 255;
// 	col->b = (int)(col->b * 67 + 68 * M_PI / 71) % 255;
// 	fct->rw = 1;
// }

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

void	ft_calc_mandelbrot(t_complexe *z, t_complexe c, unsigned int *it, unsigned int it_max)
{
	while (*it < it_max)
	{
		if (z->r * z->r + z->i * z->i > 4)
			break ;
		next_mandelbrot(z, c);
		(*it)++;
	}
}

void	calc(t_fct *fct)
{
	int	x;
	int	y;

	fct->rw = 0;
	y = 0;
	while (y < fct->v_size)
	{
		x = 0;
		while (x < fct->h_size)
		{
			set_complexe(&(fct->c), fct->h_s + x * fct->pat,
				fct->v_s - y * fct->pat);
			if (fct->rwa)
				fct->grille[y][x].it = 0;
			calc_z_it_value(&(fct->grille[y][x].z), &(fct->grille[y][x].it), fct);
			fct->pixel = (y * fct->line_length) + (x * 4);
			ft_findcolor_to_pixel(fct, fct->grille[y][x].it, fct->grille[y][x].z);
			x++;
		}
		y++;
	}
	fct->rwa = 0;
	mlx_put_image_to_window(fct->mlx, fct->win, fct->img, 0, 0);
}

void	next_mandelbrot(t_complexe *prec, t_complexe c)
{
	sq_complexe(prec);
	add_complexe(prec, *prec, c);
}

void	print_one_color(void *color)
{
	printf("(r, g, b) : (%d, %d, %d)\n",
		((t_color *)color)->r,
		((t_color *)color)->g,
		((t_color *)color)->b);
}

void	print_colors(t_fct *fct)
{
	printf("outside colors : \n");
	ft_lstiter(fct->col.palette, &print_one_color);
	printf("inside color : \n");
	ft_lstiter(fct->col.inside, &print_one_color);
}

void	print_info(t_fct *fct) //TO DELETE
{
	ft_putendl_fd("Fractal : Mandelbrot", 1);
	ft_putstr_fd("Precision : ", 1);
	ft_putnbr_fd(fct->precision, 1);
	ft_putendl_fd("", 1);
	printf("Position (x,y) : %Lf, %Lf\n", fct->h_s, fct->v_s);
	print_colors(fct);
}
