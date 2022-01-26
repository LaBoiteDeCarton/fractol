#include "fct.h"

void	check_mouse_change(t_fct *fct)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(fct->win, &x, &y);
	x = x * (x > 0);
	x = x * (x < fct->h_size) + fct->h_size * (x >= fct->h_size);
	y = y * (y > 0);
	y = y * (y < fct->v_size) + fct->v_size * (y >= fct->v_size);
	if (fct->active_mouse && (fct->m_x != x || fct->m_y != y))
	{
		fct->rwa = 1;
		set_complexe(&fct->mouse_c, fct->h_s + fct->m_x * fct->pat,
			fct->v_s - fct->m_y * fct->pat);
	}
	else if (fct->col_panel_active && (fct->m_x != x || fct->m_y != y))
	{
		fct->col_mod->r = x * 255 / fct->h_size;
		fct->col_mod->g = y * 255 / fct->v_size;
		fct->rw = 1;
	}
	fct->m_x = x;
	fct->m_y = y;
}