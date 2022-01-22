#include "fct.h"

void	zoom_out(t_fct *fct, int x, int y)
{
	long double	perc;
	long double	new_pat;
	long double	largeur_extrait;

	if (fct->keys.k_shift2)
		new_pat = fct->pat * 2.2;
	else
		new_pat = fct->pat * 1.1;
	largeur_extrait = (new_pat - fct->pat) * fct->h_size;
	perc = (long double)x / fct->h_size;
	fct->h_s -= perc * largeur_extrait;
	largeur_extrait = (new_pat - fct->pat) * fct->v_size;
	perc = (long double)y / fct->v_size;
	fct->v_s += perc * largeur_extrait;
	fct->pat = new_pat;
	fct->rwa = 1;
}

void	zoom_in(t_fct *fct, int x, int y)
{
	long double	perc;
	long double	new_pat;
	long double	largeur_extrait;

	if (fct->keys.k_shift2)
		new_pat = fct->pat / 2.2;
	else
		new_pat = fct->pat / 1.1;
	largeur_extrait = (fct->pat - new_pat) * fct->h_size;
	perc = (long double)x / fct->h_size;
	fct->h_s += perc * largeur_extrait;
	largeur_extrait = (fct->pat - new_pat) * fct->v_size;
	perc = (long double)y / fct->v_size;
	fct->v_s -= perc * largeur_extrait;
	fct->pat = new_pat;
	fct->rwa = 1;
}

// void zoom_in(t_fct *fct, int x, int y)
// {
// 	(void)x;
// 	int i;
// 	int j;
// 	t_case *save;

// 	i = y - 1;
// 	while (i > 0)
// 	{
// 		save = fct->grille[0];
// 		ft_memmove(fct->grille, fct->grille + 1, sizeof(t_case **) * i);
// 		fct->grille[i] = save;
// 		reset_ligne(fct->grille[i], fct->h_size - 1);
// 		i--;
// 		j = 0;
// 		while (j <= x)
// 		{
// 			if (x % 2 == j % 2)
// 				fct->grille[i][j] = fct->grille[i][j + ((x - j) / 2)];
// 			else
// 				fct->grille[i][j].it = -1;
// 			j++;
// 		}
// 		j = fct->h_size - 1;
// 		while (j > x)
// 		{
// 			if (x % 2 == j % 2)
// 				fct->grille[i][j] = fct->grille[i][j - ((j - x) / 2)];
// 			else
// 				fct->grille[i][j].it = -1;
// 			j--;
// 		}
// 		i--;
// 	}
// 	while (j <= x)
// 		{
// 			if (x % 2 == j % 2)
// 				fct->grille[y][j] = fct->grille[y][j + ((x - j) / 2)];
// 			else
// 				fct->grille[y][j].it = -1;
// 			j++;
// 		}
// 		j = fct->h_size - 1;
// 		while (j > x)
// 		{
// 			if (x % 2 == j % 2)
// 				fct->grille[y][j] = fct->grille[y][j - ((j - x) / 2)];
// 			else
// 				fct->grille[y][j].it = -1;
// 			j--;
// 		}
// 	i = y + 1;
// 	while (i < fct->v_size - 1)
// 	{
// 		save = fct->grille[fct->v_size - 1];
// 		ft_memmove(fct->grille + i + 1, fct->grille + i, sizeof(t_case *) * (fct->v_size - 1 - i));
// 		fct->grille[i] = save;
// 		reset_ligne(fct->grille[i], fct->h_size - 1);
// 		i++;
// 		j = 0;
// 		while (j < x)
// 		{
// 			if (x % 2 == j % 2)
// 				fct->grille[i][j] = fct->grille[i][j + ((x - j) / 2)];
// 			else
// 				fct->grille[i][j].it = -1;
// 			j++;
// 		}
// 		j = fct->h_size - 1;
// 		while (j > x)
// 		{
// 			if (x % 2 == j % 2)
// 				fct->grille[i][j] = fct->grille[i][j - ((j - x) / 2)];
// 			else
// 				fct->grille[i][j].it = -1;
// 			j--;
// 		}
// 		i++;
// 	}
// 	fct->v_s -= fct->pat * (y / 2);
// 	fct->h_s += fct->pat * (x / 2);
// 	fct->pat /= 2;
// 	fct->rw_sc = 4;
// 	fct->rw = 1;
// }
// void	zoom_in(t_fct *fct, int x, int y)
// {
// 	t_case *save;
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < fct->v_size)
// 	{
// 		if (i % 2 == 1)
// 			reset_ligne(fct->grille[i], fct->h_size);
// 		else if (i < fct->v_size)
// 		{
// 			save = fct->grille[i];
// 			fct->grille[i] = fct->grille[(y + i) / 2];
// 			fct->grille[y / 2 + (i / 2)] = save;
// 			j = 0;
// 			while (j < fct->h_size)
// 			{
// 				if (j % 2 == 1)
// 					fct->grille[i][j].it = -1;
// 				else
// 					fct->grille[i][j] = fct->grille[i][(x + j) / 2];
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	fct->v_s -= fct->pat * (y / 2);
// 	fct->h_s += fct->pat * (x / 2);
// 	fct->pat /= 2;
// 	fct->rw = 1;
// }