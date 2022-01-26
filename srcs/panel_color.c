#include "fct.h"

void	affiche_panel(t_fct *fct)
{
	int i;
	int j;
	int k;
	int pixel;
	void *img;
	void *add;
	int bpp;
	int sl;
	int end;

	if (fct->col_panel_active)
	{
		i = 0;
		while (i < fct->palette.count)
		{
			img = mlx_new_image(fct->mlx, 40, 20);
			if (!img)
				handle_error(ERR_MALLOC, fct);
			add = mlx_get_data_addr(img, &bpp, &sl, &end);
			k = 0;
			while (k < 20)
			{
				j = 0;
				while (j < 40)
				{
					pixel = k * sl + j * (bpp / 8);
					if (j < 2 || j > 37 || k < 2 || k > 17)
					{
						if (fct->i_cm == i)
							ft_putcolor_to_pixel(new_color(235, 235, 235), add, pixel);
						else
							ft_putcolor_to_pixel(new_color(30, 30, 30), add, pixel);
					}
					else
						ft_putcolor_to_pixel(*(t_color *)(ft_lstnieme(fct->palette.out, i)->content), add, pixel);
					j++;
				}
				k++;
			}
			mlx_put_image_to_window(fct->mlx, fct->win, img,
					80 + (i % 12) * 80,
					40 + 50 * (i / 12));
			mlx_destroy_image(fct->mlx, img);
			i++;
		}
	}
}

void	active_color_panel(t_fct *fct)
{
	if (fct->col_panel_active == 1)
		fct->col_panel_active = 0;
	else
	{
		fct->col_panel_active = 1;
		fct->active_mouse = 0;
		fct->col_mod = (t_color *)(ft_lstnieme(fct->palette.out, fct->i_cm)->content);
		mlx_mouse_move(fct->win,
			fct->col_mod->r * fct->h_size / 255,
			fct->col_mod->g * fct->v_size / 255);
	}
	fct->rw = 1;
}

void	panel_next(t_fct *fct)
{
	if (fct->i_cm + 1 < fct->palette.count)
		fct->i_cm++;
	fct->col_mod = (t_color *)(ft_lstnieme(fct->palette.out, fct->i_cm)->content);
	mlx_mouse_move(fct->win,
		fct->col_mod->r * fct->h_size / 255,
		fct->col_mod->g * fct->v_size / 255);
	fct->rw = 1;
}

void	panel_prev(t_fct *fct)
{
	if (fct->i_cm > 0)
		fct->i_cm--;
	fct->col_mod = (t_color *)(ft_lstnieme(fct->palette.out, fct->i_cm)->content);
	mlx_mouse_move(fct->win,
		fct->col_mod->r * fct->h_size / 255,
		fct->col_mod->g * fct->v_size / 255);
	fct->rw = 1;
}

void	panel_add_color(t_fct *fct)
{
	t_color	*color;
	t_list	*cell;

	if (!fct->keys.k_space && fct->palette.count < 156)
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
		if (!fct->i_cm)
			ft_lstinsert_after(&fct->palette.out, cell);
		else
			ft_lstinsert_after(&(ft_lstnieme(fct->palette.out, fct->i_cm - 1)->next), cell);
		fct->palette.count++;
		fct->rw = 1;
	}
}

void	panel_del_color(t_fct *fct)
{
	if (!fct->keys.k_space && fct->palette.count > 1)
	{
		if (fct->i_cm <= 0)
			ft_lstdelfront(&fct->palette.out);
		else
		{
			ft_lstdelfront(&(ft_lstnieme(fct->palette.out, fct->i_cm - 1)->next));
			fct->i_cm--;
		}
		fct->palette.count--;
		fct->col_panel_active = 0;
		active_color_panel(fct);
	}
}

void	panel_color_inside(t_fct *fct)
{
	if (fct->col_panel_active && !fct->keys.k_space)
	{
		fct->col_mod = (t_color *)fct->palette.in->content;
		mlx_mouse_move(fct->win,
			fct->col_mod->r * fct->h_size / 255,
			fct->col_mod->g * fct->v_size / 255);
		fct->keys.k_space = 1;
	}
}

void	panel_blue_down(t_fct *fct)
{
	fct->col_mod->b -= 20  * (fct->col_mod->b >= 20);
	fct->rw = 1;
}

void	panel_blue_up(t_fct *fct)
{
	fct->col_mod->b += 20  * (fct->col_mod->b <= 235);
	fct->rw = 1;
}