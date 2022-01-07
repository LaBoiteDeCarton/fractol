#include "fractol.h"

void zoom_out(t_fractol *fractol, int x, int y)
{
	long double perc;
	long double new_pat;
	long double largeur_extrait;

	new_pat = fractol->pat * 1.8;
	largeur_extrait = (new_pat - fractol->pat) * fractol->h_size;
	perc = (long double)x / fractol->h_size;
	fractol->h_s -= perc * largeur_extrait;
	largeur_extrait = (new_pat - fractol->pat) * fractol->v_size;
	perc = (long double)y /fractol->v_size;
	fractol->v_s += perc * largeur_extrait;
	fractol->pat = new_pat;
	fractol->rw = 1;
	init_grille(fractol);
}

void zoom_in(t_fractol *fractol, int x, int y)
{
	long double perc;
	long double new_pat;
	long double largeur_extrait;

	new_pat = fractol->pat / 1.8;
	largeur_extrait = (fractol->pat - new_pat) * fractol->h_size;
	perc = (long double)x / fractol->h_size;
	fractol->h_s += perc * largeur_extrait;
	largeur_extrait = (fractol->pat - new_pat) * fractol->v_size;
	perc = (long double)y / fractol->v_size;
	fractol->v_s -= perc * largeur_extrait;
	fractol->pat = new_pat;
	fractol->rw = 1;
	init_grille(fractol);
}

// void zoom_in(t_fractol *fractol, int x, int y)
// {
// 	(void)x;
// 	int i;
// 	int j;
// 	t_case *save;

// 	i = y - 1;
// 	while (i > 0)
// 	{
// 		save = fractol->grille[0];
// 		ft_memmove(fractol->grille, fractol->grille + 1, sizeof(t_case **) * i);
// 		fractol->grille[i] = save;
// 		reset_ligne(fractol->grille[i], fractol->h_size - 1);
// 		i--;
// 		j = 0;
// 		while (j <= x)
// 		{
// 			if (x % 2 == j % 2)
// 				fractol->grille[i][j] = fractol->grille[i][j + ((x - j) / 2)];
// 			else
// 				fractol->grille[i][j].it = -1;
// 			j++;
// 		}
// 		j = fractol->h_size - 1;
// 		while (j > x)
// 		{
// 			if (x % 2 == j % 2)
// 				fractol->grille[i][j] = fractol->grille[i][j - ((j - x) / 2)];
// 			else
// 				fractol->grille[i][j].it = -1;
// 			j--;
// 		}
// 		i--;
// 	}
// 	while (j <= x)
// 		{
// 			if (x % 2 == j % 2)
// 				fractol->grille[y][j] = fractol->grille[y][j + ((x - j) / 2)];
// 			else
// 				fractol->grille[y][j].it = -1;
// 			j++;
// 		}
// 		j = fractol->h_size - 1;
// 		while (j > x)
// 		{
// 			if (x % 2 == j % 2)
// 				fractol->grille[y][j] = fractol->grille[y][j - ((j - x) / 2)];
// 			else
// 				fractol->grille[y][j].it = -1;
// 			j--;
// 		}
// 	i = y + 1;
// 	while (i < fractol->v_size - 1)
// 	{
// 		save = fractol->grille[fractol->v_size - 1];
// 		ft_memmove(fractol->grille + i + 1, fractol->grille + i, sizeof(t_case *) * (fractol->v_size - 1 - i));
// 		fractol->grille[i] = save;
// 		reset_ligne(fractol->grille[i], fractol->h_size - 1);
// 		i++;
// 		j = 0;
// 		while (j < x)
// 		{
// 			if (x % 2 == j % 2)
// 				fractol->grille[i][j] = fractol->grille[i][j + ((x - j) / 2)];
// 			else
// 				fractol->grille[i][j].it = -1;
// 			j++;
// 		}
// 		j = fractol->h_size - 1;
// 		while (j > x)
// 		{
// 			if (x % 2 == j % 2)
// 				fractol->grille[i][j] = fractol->grille[i][j - ((j - x) / 2)];
// 			else
// 				fractol->grille[i][j].it = -1;
// 			j--;
// 		}
// 		i++;
// 	}
// 	fractol->v_s -= fractol->pat * (y / 2);
// 	fractol->h_s += fractol->pat * (x / 2);
// 	fractol->pat /= 2;
// 	fractol->rw_sc = 4;
// 	fractol->rw = 1;
// }
// void	zoom_in(t_fractol *fractol, int x, int y)
// {
// 	t_case *save;
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < fractol->v_size)
// 	{
// 		if (i % 2 == 1)
// 			reset_ligne(fractol->grille[i], fractol->h_size);
// 		else if (i < fractol->v_size)
// 		{
// 			save = fractol->grille[i];
// 			fractol->grille[i] = fractol->grille[(y + i) / 2];
// 			fractol->grille[y / 2 + (i / 2)] = save;
// 			j = 0;
// 			while (j < fractol->h_size)
// 			{
// 				if (j % 2 == 1)
// 					fractol->grille[i][j].it = -1;
// 				else
// 					fractol->grille[i][j] = fractol->grille[i][(x + j) / 2];
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	fractol->v_s -= fractol->pat * (y / 2);
// 	fractol->h_s += fractol->pat * (x / 2);
// 	fractol->pat /= 2;
// 	fractol->rw = 1;
// }