/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:26:15 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/15 12:13:19 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_itoa_check_size(int n)
{
	size_t			size;
	unsigned int	nb;

	size = 1;
	nb = n;
	if (n < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb > 9)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	size_t			size_chain;
	size_t			i;
	char			*str;
	unsigned int	nb;

	size_chain = ft_itoa_check_size(n);
	if (!(str = (char *)malloc(sizeof(char) * size_chain + 1)))
		return (NULL);
	i = 0;
	nb = n;
	if (n < 0)
	{
		str[i] = '-';
		nb *= -1;
	}
	i = size_chain - 1;
	while (nb != 0)
	{
		str[i--] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n == 0)
		str[0] = '0';
	str[size_chain] = '\0';
	return (str);
}
