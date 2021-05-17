/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:40:59 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/17 11:00:22 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s || !f)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		res[i] = (*f)(i, s[i]);
	res[i] = '\0';
	return (res);
}
