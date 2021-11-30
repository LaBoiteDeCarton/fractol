#include "fractol.h"

t_complexe	*add_complexe(t_complexe *z1, t_complexe *z2)
{
	return (create_complexe(z1->reel + z2->reel, z1->img + z2->img));
}

t_complexe *sq_complexe(t_complexe *z)
{
	return (create_complexe((z->reel * z->reel) - (z->img * z->img), z->img * z->reel * 2));
}

t_complexe *create_complexe(long double reel, long double img)
{
	t_complexe *new_z;
	new_z = (t_complexe *)malloc(sizeof(t_complexe));
	if (!new_z)
		return (NULL);
	new_z->reel = reel;
	new_z->img = img;
	return (new_z);
}

long double mod_complexe(t_complexe *z)
{
	return (sqrtl(powl(z->reel, 2.0) + powl(z->img, 2.0)));
}