/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:23:46 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/21 14:41:05 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;
	size_t j;

	i = 0;
	len = 0;
	j = 0;
	while (src[len] != '\0')
		len++;
	while (dst[i])
		i++;
	if (size <= i)
		len = len + size;
	else
		len = len + i;
	while (i + 1 < size && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len);
}
