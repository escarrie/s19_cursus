/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:27:45 by escarrie          #+#    #+#             */
/*   Updated: 2020/10/23 14:00:42 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		my_print_prc(t_tag *tag)
{
	char c;

	c = '%';
	if (tag->zero_fill == ENABLED && tag->left_align == DISABLED)
		tag->padding = '0';
	if (tag->width > 1 && tag->left_align == DISABLED)
		tag->nbyte += print_padding(tag->padding, tag->width - 1);
	tag->nbyte += ft_putchar(c);
	if (tag->width > 1 && tag->left_align == ENABLED)
		tag->nbyte += print_padding(tag->padding, tag->width - 1);
	return (0);
}
