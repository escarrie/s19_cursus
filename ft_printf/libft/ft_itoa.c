/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:26:15 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/26 18:20:27 by escarrie         ###   ########.fr       */
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

char				*ft_itoa_base(unsigned int n, const char *base)
{
	unsigned int	div;
	unsigned int	len;
	unsigned int	base_len;
	char			*res;

	div = n;
	len = (n == 0) ? 1 : 0;
	base_len = (unsigned int)ft_strlen((char *)base);
	while (div != 0)
	{
		div = div / base_len;
		len++;
	}
	if (!(res = ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	res[0] = '0';
	while (n != 0)
	{
		len--;
		res[len] = base[(n % base_len)];
		n /= base_len;
	}
	return (res);
}
