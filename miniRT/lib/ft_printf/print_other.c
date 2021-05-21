/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:26:01 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/28 10:53:29 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_padding(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
		i += ft_putchar(c);
	return (i);
}
