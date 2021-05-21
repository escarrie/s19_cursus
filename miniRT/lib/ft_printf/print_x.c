/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:23:08 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/28 00:11:18 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_before(t_tag *tag, int l_nbr, char *nbr)
{
	if (tag->width > l_nbr && tag->left_align == DISABLED)
	{
		if ((tag->prcs == DISABLED || tag->prcs < l_nbr) && tag->prcs != 0)
			tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
		else if (tag->prcs != DISABLED && tag->prcs > l_nbr)
		{
			tag->nbyte += print_padding(tag->padding, tag->width - tag->prcs);
			tag->nbyte += print_padding('0', tag->prcs - l_nbr);
		}
		else if (tag->prcs == 0 && *nbr != '0')
			tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
		else if (tag->prcs == 0 && *nbr == '0')
			tag->nbyte += print_padding(tag->padding, tag->width);
	}
	else if ((tag->left_align == ENABLED || tag->width == DISABLED) &&
			tag->prcs > l_nbr)
		tag->nbyte += print_padding('0', tag->prcs - l_nbr);
	else if (tag->prcs > l_nbr && tag->left_align == DISABLED)
		tag->nbyte += print_padding('0', tag->prcs - l_nbr);
}

static void	process_after(t_tag *tag, int l_nbr, char *nbr)
{
	if (tag->left_align == ENABLED && tag->width > l_nbr)
	{
		if (tag->prcs > l_nbr && tag->width > tag->prcs)
			tag->nbyte += print_padding(tag->padding, tag->width - tag->prcs);
		else if (tag->prcs == DISABLED)
			tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
		else if (tag->width > l_nbr && tag->prcs != 0 && tag->prcs < tag->width)
			tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
		else if (tag->prcs == 0 && *nbr != '0')
			tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
		else if (tag->prcs == 0 && *nbr == '0')
			tag->nbyte += print_padding(tag->padding, tag->width);
	}
}

int			my_print_hex(t_tag *tag, va_list ap, char conv)
{
	char	*nbr;
	int		l_nbr;

	nbr = NULL;
	if (conv == 'x')
		nbr = ft_itoa_base((int)va_arg(ap, int), HEX_LOW);
	else if (conv == 'X')
		nbr = ft_itoa_base((int)va_arg(ap, int), HEX_UP);
	if (nbr == NULL)
		return (ERROR);
	l_nbr = ft_strlen(nbr);
	if (tag->zero_fill == ENABLED && tag->left_align == DISABLED &&
		tag->prcs == DISABLED)
		tag->padding = '0';
	process_before(tag, l_nbr, nbr);
	if (tag->prcs != 0 || (tag->prcs == 0 && *nbr != '0'))
		tag->nbyte += ft_putstr(nbr);
	process_after(tag, l_nbr, nbr);
	free(nbr);
	return (0);
}
