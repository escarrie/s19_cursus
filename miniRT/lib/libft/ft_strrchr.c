/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 10:35:00 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/19 15:50:16 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int last_find;

	i = -1;
	last_find = -1;
	while (s[++i])
		if (s[i] == c)
			last_find = i;
	if (last_find == -1 && c == '\0')
		return ((char *)&s[i]);
	else if (last_find != -1)
		return ((char *)&s[last_find]);
	return (NULL);
}
