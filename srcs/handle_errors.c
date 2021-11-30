#include "fractol.h"

void handle_error(char *err, t_fractol *fractol)
{
	if (fractol)
		free(fractol);
	printf("%s%s", err, EXEC_PROTO);
	exit(0);
}