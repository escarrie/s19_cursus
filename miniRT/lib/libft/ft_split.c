/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:03:48 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/21 14:18:44 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static char		*malloc_word(const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char		**ft_free(char **res, int i)
{
	while (i)
	{
		free(res[i - 1]);
		i--;
	}
	free(res);
	return (NULL);
}

char			**ft_split(const char *str, char c)
{
	char	**res;
	int		i;

	if (!str)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			if (!(res[i] = malloc_word(str, c)))
				return (ft_free(res, i));
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	res[i] = NULL;
	return (res);
}
