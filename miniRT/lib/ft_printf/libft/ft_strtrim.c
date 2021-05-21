/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:36:31 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/15 14:21:34 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_is_in_set(char c, char *set)
{
	size_t i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_check_is_in_set(s1[start], (char *)set))
		start++;
	end = ft_strlen(s1);
	while (s1[end - 1] && ft_check_is_in_set(s1[end - 1], (char *)set))
		end--;
	if (end <= start)
		end = start;
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	str = ft_substr(s1, start, end - start);
	return (str);
}
