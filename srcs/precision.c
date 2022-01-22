#include "fct.h"

void	sub_precision(t_fct *fct)
{
	if (fct->precision)
		fct->precision -= 1;
	fct->rw = 1;
}

void	add_precision(t_fct *fct)
{
	if (fct->precision < INT32_MAX)
		fct->precision += 1;
	fct->rw = 1;
}
