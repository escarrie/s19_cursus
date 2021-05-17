/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:40:21 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/21 12:57:35 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	i = n;
	if (!src && !dst)
		return (0);
	if (tmp_src == tmp_dst)
		return (dst);
	if (tmp_dst > tmp_src && tmp_dst < (tmp_src + n))
		while (n > 0)
		{
			tmp_dst[n - 1] = tmp_src[n - 1];
			n--;
		}
	else
	{
		i = -1;
		while (++i < n)
			tmp_dst[i] = tmp_src[i];
	}
	return (dst);
}
