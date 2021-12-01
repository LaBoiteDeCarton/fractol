#include "fractol.h"

void add_complexe(t_complexe *z, t_complexe z1, t_complexe z2)
{
	set_complexe(z, z1.reel + z2.reel, z1.img + z2.img);
}

void sq_complexe(t_complexe *z)
{
	set_complexe(z, (z->reel * z->reel) - (z->img * z->img), z->img * z->reel * 2);
}

void set_complexe(t_complexe *z, long double reel, long double img)
{
	z->reel = reel;
	z->img = img;
}

long double mod_complexe(t_complexe z)
{
	return (sqrtl(powl(z.reel, 2.0) + powl(z.img, 2.0)));
}

void ft_print_complexe(t_complexe z)
{
	printf("%Lf + %LfZ\n", z.reel, z.img);
}