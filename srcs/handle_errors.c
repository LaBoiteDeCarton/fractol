#include "fct.h"

void	handle_error(char *err)
{
	printf("%s\n%s\n", err, EXEC_PROTO);
	exit(0);
}

void	freee(t_fct *fct)
{
	detsroy_panel_color(fct);
	free_grille(fct);
}
