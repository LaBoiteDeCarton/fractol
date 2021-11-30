#ifndef SUITE_H
# define SUITE_H

#include "complexe.h"

typedef struct s_suite	t_suite;

struct s_suite
{
	t_complexe *z;
	t_complexe (* next_fract(t_complexe *));
};

#endif