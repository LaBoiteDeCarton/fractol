#include "fct.h"

static void	creat_color_inside(t_fct *fct, int r, int g, int b)
{
	t_color *color;

	color = malloc(sizeof(t_color));
	if (!color)
	{
		freee(fct);
		handle_error(ERR_MALLOC);
	}
	put_trgb_color(color, r, g, b);
	fct->col.inside = ft_lstnew(color);
}

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
	creat_color_inside(fct, 0, 0, 0);
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
	creat_color_inside(fct, 0, 0, 0);
}

static void	create_ys_panel(t_fct *fct)
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
	put_trgb_color(col1, 54, 3, 0);
	put_trgb_color(col2, 212, 211, 180);
	fct->col.palette = ft_lstnew(col1);
	ft_lstadd_back(&(fct->col.palette), ft_lstnew(col2));
	fct->col.count = 2;
	creat_color_inside(fct, 255, 255, 255);
}

static void	create_med_panel(t_fct *fct)
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
	put_trgb_color(col1, 14, 83, 175);
	put_trgb_color(col2, 114, 172, 240);
	fct->col.palette = ft_lstnew(col1);
	ft_lstadd_back(&(fct->col.palette), ft_lstnew(col2));
	fct->col.count = 2;
	creat_color_inside(fct, 185, 240, 240);
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
	creat_color_inside(fct, 255, 255, 255);
}

static void	create_mindf_panel(t_fct *fct)
{
	t_color	*col1;
	t_color	*col2;
	t_color *col3;
	t_color *col4;
	t_color *col5;
	t_color *col6;
	t_color *col7;
	t_color *col8;

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
	col3 = malloc(sizeof(t_color));
	col4 = malloc(sizeof(t_color));
	col5 = malloc(sizeof(t_color));
	col6 = malloc(sizeof(t_color));
	col7 = malloc(sizeof(t_color));
	col8 = malloc(sizeof(t_color));
	put_trgb_color(col1, 250, 248, 255);
	put_trgb_color(col2, 24, 144, 215);
	put_trgb_color(col3, 101, 82, 175);
	put_trgb_color(col4, 146, 7, 15);
	put_trgb_color(col5, 230, 51, 15);
	put_trgb_color(col6, 217, 240, 15);
	put_trgb_color(col7, 9, 231, 155);
	put_trgb_color(col8, 211, 36, 240);
	fct->col.palette = ft_lstnew(col1);
	ft_lstadd_back(&(fct->col.palette), ft_lstnew(col2));
	ft_lstadd_back(&(fct->col.palette), ft_lstnew(col3));
	ft_lstadd_back(&(fct->col.palette), ft_lstnew(col4));
	ft_lstadd_back(&(fct->col.palette), ft_lstnew(col5));
	ft_lstadd_back(&(fct->col.palette), ft_lstnew(col6));
	ft_lstadd_back(&(fct->col.palette), ft_lstnew(col7));
	ft_lstadd_back(&(fct->col.palette), ft_lstnew(col8));
	fct->col.count = 8;
	creat_color_inside(fct, 251, 96, 115); // faire une affectation simple
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
	if (fct->color_set == yang_shi)
		create_ys_panel(fct);
	if (fct->color_set == medical)
		create_med_panel(fct);
	if (fct->color_set == mindf)
		create_mindf_panel(fct);
	fct->rw = 1;
}

void	active_color_panel(t_fct *fct)
{
	if (fct->col_panel_active == 1)
		fct->col_panel_active = 0;
	else
	{
		fct->col_panel_active = 1;
		fct->active_mouse = 0;
		fct->col_mod = fct->col.palette;
		mlx_mouse_move(fct->win,
			((t_color *)(fct->col_mod)->content)->r * fct->h_size / 255,
			((t_color *)(fct->col_mod)->content)->g * fct->v_size / 255);
	}
}

void	switch_color(t_fct *fct)
{
	if (fct->color_set == white)
		fct->color_set = white_to_black;
	else if (fct->color_set == white_to_black)
		fct->color_set = black_to_white;
	else if (fct->color_set == black_to_white)
		fct->color_set = yang_shi;
	else if (fct->color_set == yang_shi)
		fct->color_set = medical;
	else if (fct->color_set == medical)
		fct->color_set = mindf;
	else if (fct->color_set == mindf)
		fct->color_set = white;
}

// void panel_color_aleatoire(t_fct *fct, t_color *col)
// {
// 	col->r = (int)(col->r + 10 * M_PI * 179 / 43) % 255;
// 	col->g = (int)(col->g + 130 * 32 * M_PI / 110) % 255;
// 	col->b = (int)(col->b * 67 + 68 * M_PI / 71) % 255;
// 	fct->rw = 1;
// }

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

	if (!fct->keys.k_space)
	{
		color = malloc(sizeof(t_color));
		if (!color)
		{
			freee(fct);
			handle_error(ERR_MALLOC);
		}
		put_trgb_color(color, 255, 255, 255);
		ft_lstinsert_after(&fct->col_mod, ft_lstnew(color));
		fct->col.count++;
		fct->rw = 1;
	}
}

void	panel_color_inside(t_fct *fct)
{
	if (fct->col_panel_active && !fct->keys.k_space)
	{
		fct->col_mod = fct->col.inside;
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
