/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:17:16 by dmercadi          #+#    #+#             */
/*   Updated: 2022/01/23 16:17:17 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

int	ft_strisld(char *str)
{
	while (*str == ' ' || *str == '\r' || *str == '\n'
		|| *str == '\f' || *str == '\v' || *str == '\t')
		str++;
	if (*str == '-')
		str++;;
	while (*str && *str != '.')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	if (*str != '.')
		return (0);
	if (*str)
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

long double partiedecimale(char *str)
{
	long double res;

	res = 0.;
	if (!*str)
		return (res);
	res = partiedecimale(str + 1);
	res = res / 10. + (*str - '0') / 10.;
	return (res);
}

long double	ft_strtold(char *str)
{
	long double res;

	res = 0.;
	res = ft_atoi(str);
	res += partiedecimale(ft_strrchr(str, '.') + 1);
	return (res);
}
