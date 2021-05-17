/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 09:16:06 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/13 09:45:19 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;

	if (!(tmp = (void *)malloc(size * nmemb)))
		return (NULL);
	ft_bzero(tmp, nmemb * size);
	return (tmp);
}
