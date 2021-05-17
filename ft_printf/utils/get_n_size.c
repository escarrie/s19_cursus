/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:00:38 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/26 11:22:13 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		get_n_size(long long n, char *base)
{
	int	l_base;
	int	l_nbr;

	l_nbr = 0;
	l_base = ft_strlen(base);
	if (n < 0)
	{
		n = n * -1;
		l_nbr = 1;
	}
	while (n >= l_base)
	{
		n = n / l_base;
		l_nbr++;
	}
	return (l_nbr + 1);
}

int		get_nu_size(unsigned int n, char *base)
{
	int	l_base;
	int	l_nbr;

	l_nbr = 0;
	l_base = ft_strlen(base);
	while (n >= (unsigned int)l_base)
	{
		n = n / l_base;
		l_nbr++;
	}
	return (l_nbr + 1);
}
