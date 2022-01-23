#include "fct.h"

void	active_color_panel(t_fct *fct)
{
	if (fct->col_panel_active == 1)
		fct->col_panel_active = 0;
	else
	{
		fct->col_panel_active = 1;
		fct->active_mouse = 0;
		fct->col_mod = fct->palette.out;
		mlx_mouse_move(fct->win,
			((t_color *)(fct->col_mod)->content)->r * fct->h_size / 255,
			((t_color *)(fct->col_mod)->content)->g * fct->v_size / 255);
	}
}

void	panel_next(t_fct *fct)
{
	if (fct->col_mod->next)
		fct->col_mod = fct->col_mod->next;
	mlx_mouse_move(fct->win,
		((t_color *)(fct->col_mod)->content)->r * fct->h_size / 255,
		((t_color *)(fct->col_mod)->content)->g * fct->v_size / 255);
}

void	panel_add_color(t_fct *fct)
{
	t_color	*color;
	t_list	*cell;

	if (!fct->keys.k_space)
	{
		color = (t_color *)malloc(sizeof(t_color));
		if (!color)
			handle_error(ERR_MALLOC, fct);
		put_trgb_color(color, 255, 255, 255);
		cell = ft_lstnew(color);
		if (!cell)
		{
			free(color);
			handle_error(ERR_MALLOC, fct);
		}
		ft_lstinsert_after(&fct->col_mod, cell);
		fct->palette.count++;
		fct->rw = 1;
	}
}

void	panel_color_inside(t_fct *fct)
{
	if (fct->col_panel_active && !fct->keys.k_space)
	{
		fct->col_mod = fct->palette.in;
		mlx_mouse_move(fct->win,
			((t_color *)(fct->col_mod)->content)->r * fct->h_size / 255,
			((t_color *)(fct->col_mod)->content)->g * fct->v_size / 255);
		fct->keys.k_space = 1;
	}
}

void	panel_blue_down(t_fct *fct)
{
	((t_color *)(fct->col_mod)->content)->b -= 20  * (((t_color *)(fct->col_mod)->content)->b >= 20);
	fct->rw = 1;
}

void	panel_blue_up(t_fct *fct)
{
	((t_color *)(fct->col_mod)->content)->b += 20  * (((t_color *)(fct->col_mod)->content)->b <= 235);
	fct->rw = 1;
}