/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:16:58 by dmercadi          #+#    #+#             */
/*   Updated: 2022/01/23 16:16:59 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

void	set_complexe(t_complexe *z, long double r, long double i)
{
	z->r = r;
	z->i = i;
}

void	add_complexe(t_complexe *z, t_complexe z1, t_complexe z2)
{
	set_complexe(z, z1.r + z2.r, z1.i + z2.i);
}

void	sub_complexe(t_complexe *z, t_complexe z1, t_complexe z2)
{
	set_complexe(z, z1.r - z2.r, z1.i - z2.i);
}

void	sq_complexe(t_complexe *z)
{
	set_complexe(z, (z->r * z->r) - (z->i * z->i), z->i * z->r * 2);
}

void	mult_complexe(t_complexe *z, t_complexe z1, t_complexe z2)
{
	set_complexe(z, z1.r * z2.r - z1.i * z2.i, z1.r * z2.i + z1.i * z2.r);
}

long double	mod_sq_complexe(t_complexe z)
{
	return (z.r * z.r + z.i * z.i);
}

long double	mod_complexe(t_complexe z)
{
	return (sqrtl(mod_sq_complexe(z)));
}
