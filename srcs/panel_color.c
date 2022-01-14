#include "fct.h"

static void	create_white_panel(t_fct *fct)
{
	t_color	*col;

	col = malloc(sizeof(t_color));
	if (!col)
	{
		freee(fct);
		handle_error(ERR_MALLOC);
	}
	put_trgb_color(col, 255, 255, 255);
	fct->col.palette = ft_lstnew(col);
	fct->col.count = 1;
}

static void	create_wtob_panel(t_fct *fct)
{
	t_color	*col1;
	t_color	*col2;

	col1 = malloc(sizeof(t_color));
	if (!col1)
	{
		freee(fct);
		handle_error(ERR_MALLOC);
	}
	col2 = malloc(sizeof(t_color));
	if (!col2)
	{
		free(col1);
		freee(fct);
		handle_error(ERR_MALLOC);
	}
	put_trgb_color(col1, 255, 255, 255);
	put_trgb_color(col2, 0, 0, 0);
	fct->col.palette = ft_lstnew(col1);
	ft_lstadd_back(&(fct->col.palette), ft_lstnew(col2));
	fct->col.count = 2;
}

static void	create_btow_panel(t_fct *fct)
{
	t_color	*col1;
	t_color	*col2;

	col1 = malloc(sizeof(t_color));
	if (!col1)
	{
		freee(fct);
		handle_error(ERR_MALLOC);
	}
	col2 = malloc(sizeof(t_color));
	if (!col2)
	{
		free(col1);
		freee(fct);
		handle_error(ERR_MALLOC);
	}
	put_trgb_color(col1, 255, 255, 255);
	put_trgb_color(col2, 0, 0, 0);
	fct->col.palette = ft_lstnew(col2);
	ft_lstadd_back(&(fct->col.palette), ft_lstnew(col1));
	fct->col.count = 2;
}

void	create_panel(t_fct *fct)
{
	detsroy_panel_color(fct);
	if (fct->color_set == white)
		create_white_panel(fct);
	if (fct->color_set == white_to_black)
		create_wtob_panel(fct);
	if (fct->color_set == black_to_white)
		create_btow_panel(fct);
}

void	active_color_panel(t_fct *fct)
{
	if (fct->col_panel_active == 1)
		fct->col_panel_active = 0;
	else
	{
		fct->col_panel_active = 1;
		fct->active_mouse = 0;
		fct->col_mod = &(fct->col.palette);
		mlx_mouse_move(fct->win,
			((t_color *)(*(fct->col_mod))->content)->r * fct->h_size / 255,
			((t_color *)(*(fct->col_mod))->content)->g * fct->v_size / 255);
		fct->blue = ((t_color *)(*(fct->col_mod))->content)->b;
	}
}

void	switch_color(t_fct *fct)
{
	if (fct->color_set == white)
		fct->color_set = white_to_black;
	else if (fct->color_set == white_to_black)
		fct->color_set = black_to_white;
	else if (fct->color_set == black_to_white)
		fct->color_set = white;
}

void	panel_next(t_fct *fct)
{
	if ((*(fct->col_mod))->next)
		fct->col_mod = &((*(fct->col_mod))->next);
	mlx_mouse_move(fct->win,
		((t_color *)(*(fct->col_mod))->content)->r * fct->h_size / 255,
		((t_color *)(*(fct->col_mod))->content)->g * fct->v_size / 255);
	fct->blue = ((t_color *)(*(fct->col_mod))->content)->b;
}

void	panel_add_color(t_fct *fct)
{
	t_color	*color;

	color = malloc(sizeof(t_color)); //check les mallocs reussi
	put_trgb_color(color, 255, 255, 255);
	ft_lstinsert_after(fct->col_mod, ft_lstnew(color));
	fct->col.count++;
	fct->rw = 1;
}

void	panel_blue_down(t_fct *fct)
{
	if (fct->blue > 20)
		fct->blue -= 20;
	((t_color *)(*(fct->col_mod))->content)->b = fct->blue;
	fct->rw = 1;
}

void	panel_blue_up(t_fct *fct)
{
	if (fct->blue < 235)
		fct->blue += 20;
	((t_color *)(*(fct->col_mod))->content)->b = fct->blue;
	fct->rw = 1;
}
