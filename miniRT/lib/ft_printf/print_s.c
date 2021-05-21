/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:31:39 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/28 10:56:58 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	s_addon(t_tag *tag, int l_s, char *s)
{
	if (tag->width > l_s && tag->prcs == DISABLED)
	{
		if (tag->left_align == DISABLED)
			tag->nbyte += print_padding(tag->padding, tag->width - l_s);
		tag->nbyte += ft_putstr(s);
		if (tag->left_align == ENABLED)
			tag->nbyte += print_padding(tag->padding, tag->width - l_s);
	}
	else if (tag->width > l_s && tag->prcs > l_s)
	{
		if (tag->left_align == DISABLED)
			tag->nbyte += print_padding(tag->padding, tag->width - l_s);
		tag->nbyte += ft_putstr(s);
		if (tag->left_align == ENABLED)
			tag->nbyte += print_padding(tag->padding, tag->width - l_s);
	}
	else if (tag->prcs <= l_s && tag->prcs > DISABLED)
	{
		if (tag->width > tag->prcs && tag->left_align == DISABLED)
			tag->nbyte += print_padding(tag->padding, tag->width - tag->prcs);
		tag->nbyte += ft_putstr_n(s, tag->prcs);
		if (tag->width > tag->prcs && tag->left_align == ENABLED)
			tag->nbyte += print_padding(tag->padding, tag->width - tag->prcs);
	}
}

int			my_print_s(t_tag *tag, va_list ap)
{
	char	*s;
	int		l_s;

	s = va_arg(ap, char *);
	if (tag->zero_fill == ENABLED && tag->left_align == DISABLED)
		tag->padding = '0';
	if (s == NULL)
		s = "(null)";
	l_s = (int)ft_strlen(s);
	if ((tag->width == DISABLED || tag->width <= l_s) &&
		(tag->prcs == DISABLED || tag->prcs >= l_s))
	{
		tag->nbyte += ft_putstr(s);
		if (tag->width < DISABLED && tag->left_align == ENABLED)
			tag->nbyte += print_padding(tag->padding, -(tag->width) - l_s);
	}
	else
		s_addon(tag, l_s, s);
	return (0);
}
