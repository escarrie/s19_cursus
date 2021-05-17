/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:16:41 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/13 11:53:03 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	i = -1;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (tmp_dst == NULL && tmp_src == NULL)
		return (NULL);
	while (++i < n)
		tmp_dst[i] = tmp_src[i];
	return (&dst[0]);
}
