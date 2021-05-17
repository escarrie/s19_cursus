/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:26:45 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/28 10:45:12 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	my_store_n(t_tag *tag, va_list ap)
{
	int	*ptr;

	if (tag->len_mod == DISABLED)
	{
		ptr = (int *)va_arg(ap, int *);
		*ptr = tag->nbyte;
	}
	return (0);
}

static int	write_on_condition(char **str, va_list ap, t_tag *tag)
{
	if (**str == 'c')
		return (my_print_c(tag, ap));
	else if (**str == 's')
		return (my_print_s(tag, ap));
	else if (**str == 'd' || **str == 'i')
		return (my_print_di(tag, ap));
	else if (**str == 'u')
		return (my_print_u(tag, ap));
	else if (**str == 'x')
		return (my_print_hex(tag, ap, 'x'));
	else if (**str == 'X')
		return (my_print_hex(tag, ap, 'X'));
	else if (**str == 'p')
		return (my_print_p(tag, ap));
	else if (**str == '%')
		return (my_print_prc(tag));
	else if (**str == 'n')
		return (my_store_n(tag, ap));
	else
		return (ERROR);
}

static void	prepare_new_tag(t_tag *tag)
{
	tag->plus = DISABLED;
	tag->left_align = DISABLED;
	tag->width = DISABLED;
	tag->prcs = DISABLED;
	tag->hexa = H_DISABLED;
	tag->zero_fill = DISABLED;
	tag->space = DISABLED;
	tag->only_p = DISABLED;
	tag->padding = ' ';
	tag->sign = '\0';
}

static int	process_format(char *str, va_list ap)
{
	t_tag tag;

	tag.nbyte = 0;
	while (str && *str)
	{
		while (*str && *str != '%')
		{
			tag.nbyte += ft_putchar(*str);
			str++;
		}
		if (*str == '%')
		{
			str++;
			prepare_new_tag(&tag);
			if (parse(&str, ap, &tag) == ERROR)
				return (ERROR);
			if (write_on_condition(&str, ap, &tag) == ERROR)
				return (ERROR);
			str++;
		}
	}
	return (tag.nbyte);
}

int			ft_printf(const char *src, ...)
{
	va_list ap;
	int		nbyte;

	nbyte = 0;
	va_start(ap, src);
	if ((nbyte = process_format((char *)src, ap)) == ERROR)
		return (ERROR);
	va_end(ap);
	return (nbyte);
}
