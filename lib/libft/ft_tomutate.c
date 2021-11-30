/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tomutate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:21:47 by dmercadi          #+#    #+#             */
/*   Updated: 2021/03/24 12:22:14 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

static int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		c -= 32;
	return (c);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}
