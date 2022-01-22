#include "fct.h"

void	zoom_out(t_fct *fct, int x, int y)
{
	long double	perc;
	long double	new_pat;
	long double	largeur_extrait;

	if (fct->keys.k_shift2)
		new_pat = fct->pat * 2;
	else
		new_pat = fct->pat * 1.5;
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
		new_pat = fct->pat / 2;
	else
		new_pat = fct->pat / 1.5;
	if (fct->v_s + new_pat != fct->v_s &&
			fct->h_s + new_pat != fct->h_s)
	{
		largeur_extrait = (fct->pat - new_pat) * fct->h_size;
		perc = (long double)x / fct->h_size;
		fct->h_s += perc * largeur_extrait;
		largeur_extrait = (fct->pat - new_pat) * fct->v_size;
		perc = (long double)y / fct->v_size;
		fct->v_s -= perc * largeur_extrait;
		fct->pat = new_pat;
		fct->rwa = 1;
	}
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
// 				fct->grille[i][j].it = 0;
// 			j++;
// 		}
// 		j = fct->h_size - 1;
// 		while (j > x)
// 		{
// 			if (x % 2 == j % 2)
// 				fct->grille[i][j] = fct->grille[i][j - ((j - x) / 2)];
// 			else
// 				fct->grille[i][j].it = 0;
// 			j--;
// 		}
// 		i--;
// 	}
// 	while (j <= x)
// 		{
// 			if (x % 2 == j % 2)
// 				fct->grille[y][j] = fct->grille[y][j + ((x - j) / 2)];
// 			else
// 				fct->grille[y][j].it = 0;
// 			j++;
// 		}
// 		j = fct->h_size - 1;
// 		while (j > x)
// 		{
// 			if (x % 2 == j % 2)
// 				fct->grille[y][j] = fct->grille[y][j - ((j - x) / 2)];
// 			else
// 				fct->grille[y][j].it = 0;
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
// 				fct->grille[i][j].it = 0;
// 			j++;
// 		}
// 		j = fct->h_size - 1;
// 		while (j > x)
// 		{
// 			if (x % 2 == j % 2)
// 				fct->grille[i][j] = fct->grille[i][j - ((j - x) / 2)];
// 			else
// 				fct->grille[i][j].it = 0;
// 			j--;
// 		}
// 		i++;
// 	}
// 	fct->v_s -= fct->pat * (y / 2);
// 	fct->h_s += fct->pat * (x / 2);
// 	fct->pat /= 2;
// 	fct->rw = 1;
// }

// void	zoom_inligne(t_fct *fct, t_case *ligne, int x, int y)
// {
// 	int j;

// 	j = 0;
// 	while (j < fct->h_size)
// 	{
// 		if (j % 2 == 1)
// 			ligne[j].it = -1;
// 		else
// 			ligne[j] = ligne[(x + j) / 2];
// 		j++;
// 	}
// }

// void	zoom_in(t_fct *fct, int x, int y)
// {
// 	t_case *save;
// 	int i;
// 	int j;
// 	int ymod2;

// 	ymod2 = y % 2;
// 	i = 0;
// 	while (i < y)
// 	{
// 		if (i % 2 != ymod2)
// 			reset_ligne(fct->grille[i], fct->h_size);
// 		else
// 		{
// 			save = fct->grille[i];
// 			fct->grille[i] = fct->grille[(y + i) / 2];
// 			fct->grille[y / 2 + (i / 2)] = save;
			
// 		}
// 		i++;
// 	}
// 	fct->v_s -= fct->pat * (y / 2);
// 	fct->h_s += fct->pat * (x / 2);
// 	fct->pat /= 2;
// 	fct->rw = 1;
// }