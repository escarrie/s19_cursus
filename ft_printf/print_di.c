/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:42:37 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/28 10:49:16 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_before(t_tag *tag, int l_nbr, long long nbr)
{
	if (tag->zero_fill == ENABLED && tag->prcs == DISABLED &&
		tag->left_align == DISABLED)
		tag->padding = '0';
	if (tag->width > l_nbr && tag->left_align == DISABLED &&
		tag->width > tag->prcs && tag->prcs != 0)
	{
		if (tag->width > tag->prcs && tag->prcs != DISABLED &&
			tag->prcs > l_nbr && tag->prcs != 0)
			tag->nbyte += print_padding(tag->padding, tag->width - tag->prcs);
		else if (tag->prcs != 0 && nbr != 0)
			tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
	}
	if (tag->prcs > l_nbr)
		tag->nbyte += print_padding('0', tag->prcs - l_nbr);
	else if (tag->width > l_nbr && tag->prcs == 0 &&
		tag->left_align == DISABLED && nbr != 0)
		tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
	else if (nbr == 0 && tag->width > 0 && tag->prcs == DISABLED &&
			tag->left_align == DISABLED)
		tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
	else if (tag->width > l_nbr && tag->prcs == 0 &&
			nbr == 0 && tag->left_align == DISABLED)
		tag->nbyte += print_padding(tag->padding, tag->width);
}

static int	process_before_n(t_tag *tag, int l_nbr, int nbr)
{
	if (tag->width > l_nbr && tag->left_align == DISABLED &&
		tag->zero_fill == DISABLED && tag->prcs == DISABLED)
		tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
	if (tag->zero_fill == ENABLED && tag->width > l_nbr &&
		tag->left_align == DISABLED && tag->prcs == DISABLED)
	{
		tag->nbyte += ft_putchar('-');
		tag->nbyte += print_padding('0', tag->width - l_nbr);
		nbr *= -1;
	}
	else if (tag->prcs > tag->width && tag->prcs > l_nbr)
	{
		tag->nbyte += ft_putchar('-');
		tag->nbyte += print_padding('0', tag->prcs - l_nbr + 1);
		nbr *= -1;
	}
	else
		nbr = process_before_n_addon(tag, l_nbr, nbr);
	return (nbr);
}

static void	process_after(t_tag *tag, int l_nbr, long long nbr)
{
	if (tag->width > l_nbr && tag->left_align == ENABLED)
	{
		if (tag->width > tag->prcs && tag->prcs != DISABLED &&
			tag->prcs > l_nbr && tag->prcs != 0)
			tag->nbyte += print_padding(tag->padding, tag->width - tag->prcs);
		else if (tag->prcs != 0 && tag->width > tag->prcs)
			tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
		if (tag->width > l_nbr && tag->prcs == 0 &&
			tag->left_align == ENABLED && nbr != 0)
			tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
		else if (tag->width > l_nbr && tag->prcs == 0 &&
				tag->left_align == ENABLED && nbr == 0)
			tag->nbyte += print_padding(tag->padding, tag->width);
	}
	if (tag->width < 0 && tag->left_align == ENABLED)
		if (-(tag->width) > l_nbr && tag->prcs > l_nbr)
			tag->nbyte +=
			print_padding(tag->padding, -(tag->width) - tag->prcs);
}

static void	process_after_n(t_tag *tag, int l_nbr)
{
	if (tag->left_align == ENABLED && tag->prcs == DISABLED &&
		tag->width > l_nbr && tag->zero_fill == DISABLED)
		tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
	else if (tag->width > tag->prcs && tag->prcs > l_nbr &&
		tag->zero_fill == DISABLED && tag->left_align == ENABLED)
		tag->nbyte += print_padding(tag->padding, tag->width - tag->prcs - 1);
	else if (tag->width > tag->prcs && tag->prcs < l_nbr &&
		tag->prcs != DISABLED && tag->left_align == ENABLED)
		tag->nbyte += print_padding(tag->padding, tag->width - l_nbr);
	else if (tag->left_align == ENABLED && tag->width > l_nbr &&
		tag->prcs > l_nbr && tag->prcs < tag->width)
		tag->nbyte += print_padding(tag->padding, tag->width - (tag->prcs + 1));
}

int			my_print_di(t_tag *tag, va_list ap)
{
	long long	nbr;
	int			l_nbr;
	int			bool_n;

	nbr = va_arg(ap, int);
	bool_n = (nbr < 0) ? TRUE : FALSE;
	l_nbr = get_n_size((int)nbr, DIGIT);
	if (tag->zero_fill == ENABLED && tag->left_align == ENABLED)
		tag->zero_fill = DISABLED;
	if (nbr < 0)
		nbr = process_before_n(tag, l_nbr, nbr);
	else
		process_before(tag, l_nbr, nbr);
	if (tag->prcs != 0 || (tag->prcs == 0 && nbr != 0))
		tag->nbyte += ft_putnbr_base(nbr, DIGIT);
	if (bool_n)
		process_after_n(tag, l_nbr);
	else
		process_after(tag, l_nbr, nbr);
	return (0);
}
