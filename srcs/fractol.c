#include "fractol.h"

void init_arg_fractol(int ac, char **av, t_fractol *fractol)
{
	if (ac <= 0)
		return (handle_error(ERR_NOARG, fractol));
	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		return (handle_error(ERR_MALLOC, fractol));
	if (ft_strncmp(av[0], "mandelbrot", 11))
		fractol->fract_type = mandelbrot;
	else if (ft_strncmp(av[0], "julia", 6))
		fractol->fract_type = julia;
	else
		return (handle_error(ERR_FRACTTYPE, fractol));
}

void display(t_fractol *fractol)
{
	int h;
	int w;
	int pixel;
	int color;
	int i;
	t_complexe *position;


	fractol->suite.z = create_complexe(0,0);
	fractol->img = mlx_new_image(fractol->mlx, fractol->screen_w, fractol->screen_h);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel, &fractol->line_length,
								&fractol->endian);
	h = 0;
	while (h < fractol->screen_h)
	{
		w = 0;
		while (w < fractol->screen_w)
		{
			i = 0;
			color = 0x000000;
			position = create_complexe(fractol->fract_ros.h_s + w * fractol->pat, 
								fractol->fract_ros.v_s - h * fractol->pat);
			while (i < fractol->precision)
			{
				if (mod_complexe(fractol->suite.z) > 2)
				{
					color = 0xFFFFFF;
					break;
				}
				ft_mandelbrot(fractol->suite.z, position);
				i++;
			}
			pixel = (h * fractol->line_length) + (w * 4);
			fractol->addr[pixel] = color;
			free(position);
			fractol->suite.z->img = 0;
			fractol->suite.z->reel = 0;
			w++;
		}
		h++;
	}
	free(fractol->suite.z);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}

void ft_mandelbrot(t_complexe *prec, t_complexe *c)
{
	t_complexe *temp;

	temp = sq_complexe(prec);
	prec->img = temp->img;
	prec->reel = temp->reel;
	free(temp);
	temp = add_complexe(temp, c);
	prec->img = temp->img;
	prec->reel = temp->reel;
	free(temp);
}