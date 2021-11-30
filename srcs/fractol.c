#include "fractol.h"

void init_arg_fractol(int ac, char **av, t_fractol *fractol)
{
	if (ac <= 0)
		return (handle_error(ERR_NOARG, fractol));
	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		return (handle_error(ERR_MALLOC, fractol));
	if (ft_cmpstr(av[0], "mandelbrot"))
		fractol->fract_type = mandelbrot;
	else if (ft_cmpstr(av[0], "julia"))
		fractol->fract_type = julia;
	else
		return (handle_error(ERR_FRACTTYPE, fractol));
}