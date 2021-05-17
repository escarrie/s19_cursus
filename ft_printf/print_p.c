/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:36:47 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/28 10:53:48 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	process_before(t_tag *tag, int l_p)
{
	if (tag->width > l_p && tag->left_align == DISABLED &&
		tag->zero_fill == DISABLED && (tag->prcs == DISABLED ||
		tag->prcs < l_p) && tag->prcs != 0)
		tag->nbyte += print_padding(tag->padding, tag->width - l_p);
	else if (tag->width > l_p && tag->width > tag->prcs + 2 &&
		tag->left_align == DISABLED && tag->prcs > l_p)
		tag->nbyte += print_padding(tag->padding, tag->width - (tag->prcs + 2));
	else if (tag->width > l_p && tag->prcs == 0 && tag->left_align == DISABLED)
		tag->nbyte += print_padding(tag->padding, tag->width - 2);
}

static void	process_middle(t_tag *tag, int l_p)
{
	if (tag->zero_fill == ENABLED && tag->left_align == DISABLED &&
		tag->width > l_p && tag->prcs == DISABLED)
		tag->nbyte += print_padding(tag->padding, tag->width - l_p);
	else if (tag->zero_fill == DISABLED && (tag->width == DISABLED ||
		tag->width <= tag->prcs) && tag->prcs > l_p)
		tag->nbyte += print_padding('0', tag->prcs - (l_p - 2));
	else if (tag->width > l_p && tag->width > tag->prcs + 2 &&
		tag->left_align == DISABLED)
		tag->nbyte += print_padding('0', tag->prcs - (l_p - 2));
	else if (tag->prcs > l_p && tag->width > l_p &&
			tag->prcs + 2 >= tag->width && tag->left_align == DISABLED)
		tag->nbyte += print_padding('0', tag->prcs - (l_p - 2));
}

static void	process_after(t_tag *tag, int l_p)
{
	if (tag->left_align == ENABLED && tag->width > l_p &&
		tag->zero_fill == DISABLED && tag->prcs == DISABLED)
		tag->nbyte += print_padding(tag->padding, tag->width - l_p);
	else if (tag->left_align == ENABLED && tag->width < DISABLED)
	{
		if (-(tag->width) > l_p && tag->prcs == DISABLED)
			tag->nbyte += print_padding(tag->padding, -(tag->width) - l_p);
	}
}

int			my_print_p(t_tag *tag, va_list ap)
{
	char	*p;
	char	*b_p;
	int		l_p;

	b_p = "0x";
	p = ft_lltoa_base_x(va_arg(ap, long unsigned int), HEX_LOW);
	if (p == NULL)
		p = "0";
	l_p = ft_strlen(p) + ft_strlen(b_p);
	if (tag->zero_fill == ENABLED && tag->left_align == DISABLED)
		tag->padding = '0';
	process_before(tag, l_p);
	tag->nbyte += ft_putstr(b_p);
	process_middle(tag, l_p);
	if (tag->prcs != 0)
		tag->nbyte += ft_putstr(p);
	else if (tag->prcs == 0 && tag->only_p == ENABLED && *p != '0')
		tag->nbyte += ft_putstr(p);
	process_after(tag, l_p);
	if (*p != '0')
		free(p);
	return (0);
}
