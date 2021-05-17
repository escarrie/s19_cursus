/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:02:49 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/27 16:03:43 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_putnbr_base(int nb, char *base)
{
	long long	nbr;
	int			i;

	nbr = nb;
	i = 0;
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr >= (long long)ft_strlen(base))
		i += ft_putnbr_base((nbr / (long long)ft_strlen(base)), base);
	i += ft_putchar(base[nbr % (long long)ft_strlen(base)]);
	return (i);
}

int			ft_putnbr_u_base(unsigned int nb, char *base)
{
	long unsigned	nbr;
	int				i;

	nbr = nb;
	i = 0;
	if (nbr >= (long unsigned)ft_strlen(base))
		i += ft_putnbr_base((nbr / (long unsigned)ft_strlen(base)), base);
	i += ft_putchar(base[nbr % (long unsigned)ft_strlen(base)]);
	return (i);
}
