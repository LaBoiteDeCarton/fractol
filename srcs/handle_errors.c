#include "fct.h"

void	handle_error(char *err, t_fct *fct)
{
	freee(fct);
	printf("%s\n%s\n", err, EXEC_PROTO);
	exit(0);
}

void	freee(t_fct *fct)
{
	mlx_destroy_window(fct->mlx, fct->win); //checker si on doit dell'image
	detsroy_panel_color(fct);
	free_grille(fct);
}
