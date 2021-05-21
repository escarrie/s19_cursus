/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:22:49 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/28 00:09:30 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_before(t_tag *tag, int l_nbr, unsigned int nbr)
{
	if (tag->zero_fill == ENABLED && tag->prcs == DISABLED &&
		tag->left_align == DISABLED)
		tag->padding = '0';
	if (tag->width > l_nbr && tag->left_align == DISABLED &&
		tag->width > tag->prcs && tag->prcs != 0)
	{
		if (tag->width > tag->prcs && tag->prcs != DISABLED &&
			tag->prcs > l_nbr)
			tag->nbyte += print_padding(tag->padding, tag->width - tag->prcs);
		else
			tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
	}
	if (tag->prcs > l_nbr)
		tag->nbyte += print_padding('0', tag->prcs - l_nbr);
	if (tag->prcs == 0 && tag->left_align == DISABLED &&
		tag->width > l_nbr && nbr != 0)
		tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
	if (tag->width != DISABLED && tag->prcs == 0 && nbr == 0 &&
		tag->zero_fill == DISABLED && tag->left_align == DISABLED)
		tag->nbyte += print_padding(tag->padding, tag->width);
}

static void	process_after(t_tag *tag, int l_nbr, unsigned int nbr)
{
	if (tag->width > l_nbr && tag->left_align == ENABLED && tag->prcs != 0)
	{
		if (tag->width > tag->prcs && tag->prcs != DISABLED &&
			tag->prcs > l_nbr)
			tag->nbyte += print_padding(tag->padding, tag->width - tag->prcs);
		else if (!(tag->width > l_nbr && tag->prcs > tag->width &&
				tag->left_align == ENABLED))
			tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
	}
	if (tag->width > l_nbr && tag->left_align == ENABLED && tag->prcs == 0 &&
		nbr != 0)
		tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
	if (tag->width > l_nbr && tag->left_align == ENABLED && tag->prcs == 0 &&
		nbr == 0)
		tag->nbyte += print_padding(tag->padding, tag->width);
	if (tag->width < DISABLED && tag->left_align == ENABLED &&
		-(tag->width) > tag->prcs && tag->prcs > l_nbr)
		tag->nbyte += print_padding(tag->padding, -(tag->width) - tag->prcs);
}

int			my_print_u(t_tag *tag, va_list ap)
{
	unsigned int	nbr;
	int				l_nbr;

	nbr = va_arg(ap, unsigned int);
	l_nbr = get_nu_size(nbr, DIGIT);
	process_before(tag, l_nbr, nbr);
	if (tag->prcs != 0 || (tag->prcs == 0 && nbr != 0))
		tag->nbyte += ft_putnbr_u_base(nbr, DIGIT);
	process_after(tag, l_nbr, nbr);
	return (0);
}
