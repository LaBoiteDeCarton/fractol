/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:17:44 by dmercadi          #+#    #+#             */
/*   Updated: 2022/01/23 16:17:46 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

static void	creat_color_inside(t_fct *fct, int r, int g, int b)
{
	t_list	*cell;
	t_color *color;

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
	ft_lstadd_front(&(fct->palette.in), cell);
}

static void	addfront_color_palette(t_fct *fct, int r, int g, int b)
{
	t_list	*cell;
	t_color	*col;

	col = (t_color *)malloc(sizeof(t_color));
	if (!col)
		handle_error(ERR_MALLOC, fct);
	put_trgb_color(col, r, g, b);
	cell = ft_lstnew(col);;
	if (!cell)
	{
		free(col);
		handle_error(ERR_MALLOC, fct);
	}
	ft_lstadd_front(&(fct->palette.out), cell);
	fct->palette.count++;
}

static void	create_white_palette(t_fct *fct)
{
	addfront_color_palette(fct, 255, 255, 255);
	creat_color_inside(fct, 0, 0, 0);
}

static void	create_wtob_palette(t_fct *fct)
{
	addfront_color_palette(fct, 255, 255, 255);
	addfront_color_palette(fct, 0, 0, 0);
	creat_color_inside(fct, 0, 0, 0);
}

static void	create_ys_palette(t_fct *fct)
{
	addfront_color_palette(fct, 212, 211, 180);
	addfront_color_palette(fct, 54, 3, 0);
	creat_color_inside(fct, 255, 255, 255);
}

static void	create_med_palette(t_fct *fct)
{
	addfront_color_palette(fct, 114, 172, 240);
	addfront_color_palette(fct, 14, 83, 175);
	creat_color_inside(fct, 255, 255, 255);
	creat_color_inside(fct, 185, 240, 240);
}

static void	create_btow_palette(t_fct *fct)
{
	addfront_color_palette(fct, 0, 0, 0);
	addfront_color_palette(fct, 255, 255, 255);
	creat_color_inside(fct, 255, 255, 255);
}

static void	create_mindf_palette(t_fct *fct)
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

void	create_palette(t_fct *fct)
{
	detsroy_palette(fct);
	if (fct->color_set == white)
		create_white_palette(fct);
	if (fct->color_set == white_to_black)
		create_wtob_palette(fct);
	if (fct->color_set == black_to_white)
		create_btow_palette(fct);
	if (fct->color_set == yang_shi)
		create_ys_palette(fct);
	if (fct->color_set == medical)
		create_med_palette(fct);
	if (fct->color_set == mindf)
		create_mindf_palette(fct);
	fct->palette.count = ft_lstsize(fct->palette.out);
	fct->rw = 1;
}

void	detsroy_palette(t_fct *fct)
{
	if (fct->palette.out)
		ft_lstclear(&(fct->palette.out), &free_col);
	if (fct->palette.in)
		ft_lstclear(&(fct->palette.in), &free_col);
	fct->col_mod = NULL;
	fct->palette.out = NULL;
	fct->palette.in = NULL;
	fct->palette.count = 0;
}

void	switch_palette(t_fct *fct)
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
