/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:48:44 by dmercadi          #+#    #+#             */
/*   Updated: 2022/01/23 15:48:49 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lastocc;

	lastocc = 0;
	while (*s)
	{
		if (*s == (char)c)
			lastocc = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (lastocc);
}
