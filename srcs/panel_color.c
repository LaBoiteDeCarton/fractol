#include "fct.h"

static void	creat_color_inside(t_fct *fct, int r, int g, int b)
{
	t_list	*cell;
	t_color *color;

	color = NULL;
	color = malloc(sizeof(t_color));
	if (!color)
		handle_error(ERR_MALLOC, fct);
	put_trgb_color(color, r, g, b);
	cell = ft_lstnew(color);
	if (!cell)
	{
		free(color);
		handle_error(ERR_MALLOC, fct);
	}
	fct->col.inside = cell;
}

void	addfront_color_palette(t_fct *fct, int r, int g, int b)
{
	t_list	*cell;
	t_color	*col;

	col = NULL;
	col = malloc(sizeof(t_color));
	if (!col)
		handle_error(ERR_MALLOC, fct);
	put_trgb_color(col, r, g, b);
	cell = NULL;
	cell = ft_lstnew(col);;
	if (!cell)
	{
		free(col);
		handle_error(ERR_MALLOC, fct);
	}
	ft_lstadd_front(&(fct->col.palette), cell);
	fct->col.count++; //attention reinit a 0 a chaque effaement please
}

static void	create_white_panel(t_fct *fct)
{
	addfront_color_palette(fct, 255, 255, 255);
	creat_color_inside(fct, 0, 0, 0);
}

static void	create_wtob_panel(t_fct *fct)
{
	addfront_color_palette(fct, 255, 255, 255);
	addfront_color_palette(fct, 0, 0, 0);
	creat_color_inside(fct, 0, 0, 0);
}

static void	create_ys_panel(t_fct *fct)
{
	addfront_color_palette(fct, 212, 211, 180);
	addfront_color_palette(fct, 54, 3, 0);
	creat_color_inside(fct, 255, 255, 255);
}

static void	create_med_panel(t_fct *fct)
{
	addfront_color_palette(fct, 114, 172, 240);
	addfront_color_palette(fct, 14, 83, 175);
	creat_color_inside(fct, 255, 255, 255);
	creat_color_inside(fct, 185, 240, 240);
}

static void	create_btow_panel(t_fct *fct)
{
	addfront_color_palette(fct, 0, 0, 0);
	addfront_color_palette(fct, 255, 255, 255);
	creat_color_inside(fct, 255, 255, 255);
}

static void	create_mindf_panel(t_fct *fct)
{
	addfront_color_palette(fct, 250, 248, 255);
	addfront_color_palette(fct, 24, 144, 21);
	addfront_color_palette(fct, 101, 82, 175);
	addfront_color_palette(fct, 146, 7, 15);
	addfront_color_palette(fct, 230, 51, 15);
	addfront_color_palette(fct, 217, 240, 15);
	addfront_color_palette(fct, 9, 231, 155);
	addfront_color_palette(fct, 211, 36, 240);
	creat_color_inside(fct, 251, 96, 115);
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
	t_list	*cell;

	if (!fct->keys.k_space)
	{
		color = NULL;
		color = (t_color *)malloc(sizeof(t_color));
		if (!color)
			handle_error(ERR_MALLOC, fct);
		put_trgb_color(color, 255, 255, 255);
		cell = NULL;
		cell = ft_lstnew(color);
		if (!cell)
		{
			free(color);
			handle_error(ERR_MALLOC, fct);
		}
		ft_lstinsert_after(&fct->col_mod, cell);
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
