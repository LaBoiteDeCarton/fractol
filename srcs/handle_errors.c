#include "fractol.h"

void handle_error(char *err)
{
	printf("%s%s", err, EXEC_PROTO);
	exit(0);
}