/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:46:44 by dmercadi          #+#    #+#             */
/*   Updated: 2021/03/24 17:40:51 by dmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sepcount(char const *s, char c)
{
	int	count;
	int	isword;

	count = 0;
	isword = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && !isword)
		{
			count++;
			isword = 1;
		}
		else if (*s == c)
			isword = 0;
		s++;
	}
	return (count);
}

static int	next_word_len(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s == c)
		s++;
	while (*s != c)
	{
		count++;
		s++;
	}
	return (count);
}

static char	*ft_next_str(char const **s, char c)
{
	char	*next_str;
	int		next_str_len;
	int		i;

	next_str_len = next_word_len(*s, c);
	next_str = malloc(sizeof(char) * (next_str_len + 1));
	if (!next_str)
		return (NULL);
	else
	{
		i = 0;
		while (**s == c)
			(*s)++;
		while (i < next_str_len)
		{
			next_str[i] = **s;
			(*s)++;
			i++;
		}
		next_str[i] = 0;
	}
	return (next_str);
}

static char	**free_split(char **splited, int i)
{
	while (i-- > 0)
		free(splited[i]);
	free(splited);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split_tab;
	char	*next_str;
	int		i;
	int		size;

	size = sepcount(s, c);
	split_tab = malloc(sizeof(char *) * (size + 1));
	if (!split_tab || !s)
		return (NULL);
	else
	{
		i = 0;
		while (i < size)
		{
			next_str = ft_next_str(&s, c);
			if (next_str == NULL)
				break ;
			split_tab[i] = next_str;
			i++;
		}
		if (i < size)
			return (free_split(split_tab, i));
		split_tab[size] = NULL;
	}
	return (split_tab);
}
