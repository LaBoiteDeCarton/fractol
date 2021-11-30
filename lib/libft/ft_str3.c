/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:58:45 by dmercadi          #+#    #+#             */
/*   Updated: 2021/03/24 17:39:39 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t 	ssize;

	if (!s)
		return (NULL);
	ssize = ft_strlen(s);
	if (start > ssize)
		len = 0;
	if (ssize - start < len)
		len = ssize - start;
	sub_s = malloc(sizeof(char) * (len + 1));
	if (!sub_s)
		sub_s = NULL;
	else
	{
		sub_s[len] = 0;
		while (len-- > 0)
			sub_s[len] = s[start + len];
	}
	return (sub_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	totsize;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	totsize = ft_strlen(s1) + ft_strlen(s2);
	new_s = malloc(sizeof(char) * (totsize + 1));
	if (!new_s)
		new_s = NULL;
	else
	{
		ft_strlcpy(new_s, s1, totsize + 1);
		ft_strlcat(new_s, s2, totsize + 1);
	}
	return (new_s);
}

static int	itoasize(int n)
{
	int	size;

	if (n < 0)
		size = 2;
	else
		size = 1;
	while (n / 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		nsize;
	int		signe;

	nsize = itoasize(n);
	signe = 1;
	if (n < 0)
		signe = -1;
	a = malloc(sizeof(char) * (nsize + 1));
	if (!a)
		return (NULL);
	a[nsize--] = '\0';
	if (n == 0)
		a[0] = '0';
	else
	{
		if (signe == -1)
			a[0] = '-';
		while (n)
		{
			a[nsize--] = (n % 10) * signe + '0';
			n /= 10;
		}
	}
	return (a);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	int		i;

	if (!s)
		return (NULL);
	new_s = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_s)
		return (NULL);
	else
	{
		i = 0;
		while (s[i])
		{
			new_s[i] = f(i, s[i]);
			i++;
		}
		new_s[i] = 0;
	}
	return (new_s);
}
