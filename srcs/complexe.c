#include "fractol.h"

void add_complexe(t_complexe *z, t_complexe z1, t_complexe z2)
{
	set_complexe(z, z1.r + z2.r, z1.i + z2.i);
}

void sq_complexe(t_complexe *z)
{
	set_complexe(z, (z->r * z->r) - (z->i * z->i), z->i * z->r * 2);
}

void set_complexe(t_complexe *z, long double r, long double i)
{
	z->r = r;
	z->i = i;
}

long double mod_complexe(t_complexe z)
{
	return (sqrtl(powl(z.r, 2.0) + powl(z.i, 2.0)));
}

void ft_print_complexe(t_complexe z)
{
	printf("%Lf + %LfZ\n", z.r, z.i);
}