/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di_addons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 10:39:30 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/28 10:51:55 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_next(t_tag *tag, int l_nbr, int nbr)
{
	if (tag->width == DISABLED &&
		tag->left_align == DISABLED && tag->prcs > (l_nbr - 1))
	{
		tag->nbyte += ft_putchar('-');
		tag->nbyte += print_padding('0', tag->prcs - (l_nbr - 1));
		nbr *= -1;
	}
	else if (tag->width > l_nbr && tag->prcs < l_nbr &&
		tag->left_align == DISABLED && tag->prcs != DISABLED)
		tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
	else if (tag->width > l_nbr && tag->width > tag->prcs &&
		tag->left_align == DISABLED && tag->prcs > (l_nbr - 1))
	{
		tag->nbyte += print_padding(tag->padding, tag->width - tag->prcs - 1);
		tag->nbyte += ft_putchar('-');
		tag->nbyte += print_padding('0', tag->prcs - (l_nbr - 1));
		nbr *= -1;
	}
	return (nbr);
}

int			process_before_n_addon(t_tag *tag, int l_nbr, int nbr)
{
	if (tag->width > l_nbr && tag->prcs > l_nbr &&
		tag->width > tag->prcs && tag->left_align == DISABLED)
	{
		tag->nbyte += print_padding(tag->padding, tag->width - tag->prcs - 1);
		tag->nbyte += ft_putchar('-');
		tag->nbyte += print_padding('0', tag->prcs - l_nbr + 1);
		nbr *= -1;
	}
	else if (tag->left_align == ENABLED && tag->prcs > l_nbr)
	{
		tag->nbyte += ft_putchar('-');
		tag->nbyte += print_padding('0', tag->prcs - l_nbr + 1);
		nbr *= -1;
	}
	else
		nbr = process_next(tag, l_nbr, nbr);
	return (nbr);
}
