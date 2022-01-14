#include "fct.h"

void	handle_error(char *err)
{
	printf("%s%s", err, EXEC_PROTO);
	exit(0);
}

void	free_grille(t_fct *fct)
{
	int	i;

	i = 0;
	while (i < fct->v_size)
	{
		free(fct->grille[i]);
		i++;
	}
	free(fct->grille);
}

void	freee(t_fct *fct)
{
	detsroy_panel_color(fct);
	free_grille(fct);
}
