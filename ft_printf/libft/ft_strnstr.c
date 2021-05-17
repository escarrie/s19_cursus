/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:29:30 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/19 15:50:11 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t slen)
{
	size_t l;
	size_t b;

	if (!ft_strlen(src))
		return ((char *)dst);
	b = 0;
	while (dst[b] && b < slen)
	{
		l = 0;
		while (src[l] && dst[b + l] && src[l] == dst[b + l]
			&& (b + l) < slen)
			l++;
		if (!src[l])
			return ((char*)&dst[b]);
		b++;
	}
	return (0);
}
