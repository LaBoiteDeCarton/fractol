/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:57:21 by dmercadi          #+#    #+#             */
/*   Updated: 2021/03/24 16:55:57 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*s1 != *s2 || !*s1 || !*s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (dstsize > 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	if (dstsize != 0)
		dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dst[i] && dstsize > 0)
	{
		i++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		dst[i++] = *src++;
		dstsize--;
	}
	if (dstsize >= 1)
		dst[i] = '\0';
	while (*src++)
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	while (len > 0 && *haystack)
	{
		i = 0;
		while (len - i > 0 && needle[i] && haystack[i] == needle[i])
			i++;
		if (!(needle[i]))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	if (!*needle)
		return ((char *)haystack);
	return (NULL);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	signe;

	res = 0;
	signe = 1;
	while (*str == ' ' || *str == '\r' || *str == '\n'
		|| *str == '\f' || *str == '\v' || *str == '\t')
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + signe * (*str - '0');
		str++;
	}
	return (res);
}
