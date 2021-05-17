/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:04:04 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/19 14:54:40 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
{
	int					i;
	unsigned long long	nbr;
	int					sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr *= 10;
		nbr += (int)nptr[i++] - 48;
		if (nbr > LONG_MAX)
			return ((sign == 0) ? -1 : 0);
	}
	return ((sign == 1) ? -nbr : nbr);
}
