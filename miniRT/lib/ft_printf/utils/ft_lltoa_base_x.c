/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:52:08 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/27 11:54:02 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_lltoa_base_x(long unsigned int n, const char *base)
{
	long unsigned int	div;
	int					len;
	long long			base_len;
	char				*ret;

	len = 0;
	base_len = (long long)ft_strlen((char *)base);
	div = n;
	if (n == 0)
		return (NULL);
	while (div != 0)
	{
		div = div / base_len;
		len++;
	}
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	while (n != 0)
	{
		len--;
		ret[len] = (n > 0) ? base[(n % base_len)] : base[-(n % base_len)];
		n = n / base_len;
	}
	return (ret);
}
