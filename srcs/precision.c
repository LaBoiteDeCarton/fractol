/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:17:51 by dmercadi          #+#    #+#             */
/*   Updated: 2022/01/23 16:17:52 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

void	sub_precision(t_fct *fct)
{
	if (fct->precision)
		fct->precision -= 1;
	fct->rw = 1;
}

void	add_precision(t_fct *fct)
{
	if (fct->precision < INT32_MAX)
		fct->precision += 1;
	fct->rw = 1;
}
