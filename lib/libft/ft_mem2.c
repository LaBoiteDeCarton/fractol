/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:55:33 by dmercadi          #+#    #+#             */
/*   Updated: 2021/03/24 11:15:30 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <errno.h>

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		((unsigned char *)s)[n] = 0;
}

void	*ft_memset(void	*b, int c, size_t len)
{
	while (len-- > 0)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*buff;

	buff = malloc(count * size);
	if (!buff)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(buff, count * size);
	return (buff);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s_cpy;

	len = ft_strlen(s1);
	s_cpy = malloc(sizeof(char) * (len + 1));
	if (!s_cpy)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strlcpy(s_cpy, s1, len + 1);
	return (s_cpy);
}
