/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:43:21 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/19 15:49:22 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	size_t	len;
	char	*s_cpy;

	len = ft_strlen(s) + 1;
	if (!(s_cpy = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_memcpy(s_cpy, s, len);
	return (s_cpy);
}
