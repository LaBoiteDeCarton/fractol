#include "fractol.h"

int ft_strisdigit(char *str)
{
	while (str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
}