/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:43:27 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/28 10:46:55 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flag(char **str, t_tag *tag)
{
	while (is_set(**str, FLAG))
	{
		**str == '-' ? tag->left_align = ENABLED : SKIP;
		**str == '0' ? tag->zero_fill = ENABLED : SKIP;
		**str == '+' ? tag->plus = ENABLED : SKIP;
		**str == ' ' ? tag->space = ENABLED : SKIP;
		**str == '#' ? tag->hexa = H_ENABLED : SKIP;
		(*str)++;
	}
}

static void	parse_width(char **str, va_list ap, t_tag *tag)
{
	if (!(**str == '*' || is_set(**str, DIGIT)))
		return ;
	if (**str == '*')
	{
		tag->width = va_arg(ap, int);
		(*str)++;
	}
	else
	{
		tag->width = ft_atoi(&(**str));
		while (is_set(**str, DIGIT))
			(*str)++;
	}
	if (tag->width < 0 && tag->left_align == DISABLED)
	{
		tag->left_align = ENABLED;
		tag->width = -(tag->width);
	}
}

static void	parse_prcs(char **str, va_list ap, t_tag *tag)
{
	if (**str != '.')
		return ;
	(*str)++;
	if (**str == '*')
	{
		tag->prcs = va_arg(ap, int);
		(*str)++;
	}
	else if (is_set(**str, DIGIT))
	{
		tag->prcs = ft_atoi(&(**str));
		while (is_set(**str, DIGIT))
			(*str)++;
	}
	else
	{
		tag->prcs = 0;
		tag->only_p = ENABLED;
	}
	if (tag->prcs < 0)
		tag->prcs = DISABLED;
}

static void	parse_len_modifer(char **str, t_tag *tag)
{
	if (!is_set(**str, LEN_MODIFER))
		return ;
	tag->len_mod += ENABLED;
	while (is_set(**str, LEN_MODIFER))
	{
		tag->len_mod += **str;
		(*str)++;
	}
}

int			parse(char **str, va_list ap, t_tag *tag)
{
	if (**str == '\0')
		return (ERROR);
	parse_flag(str, tag);
	parse_width(str, ap, tag);
	parse_prcs(str, ap, tag);
	parse_len_modifer(str, tag);
	if (is_set(**str, CONVERSION) == FALSE)
		return (ERROR);
	return (0);
}
