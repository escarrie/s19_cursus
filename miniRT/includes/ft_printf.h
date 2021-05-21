/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:22:00 by escarrie          #+#    #+#             */
/*   Updated: 2021/01/31 17:38:13 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

# define DIGIT "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define CONVERSION "cspdiuxXn%"
# define FLAG "+- 0#"
# define LEN_MODIFER "lh"

# define TRUE 1
# define FALSE 0
# define ENABLED 1
# define DISABLED -1
# define H_ENABLED 2
# define H_DISABLED 0
# define ERROR -1
# define SKIP 0

typedef struct	s_tag
{
	int		nbyte;
	int		plus;
	int		left_align;
	int		width;
	int		prcs;
	int		space;
	int		zero_fill;
	int		hexa;
	int		len_mod;
	int		only_p;
	char	padding;
	char	sign;
}				t_tag;

int				ft_printf(const char *str_src, ...);
int				parse(char **str, va_list ap, t_tag *tag);
int				my_print_hex(t_tag *tag, va_list ap, char conv);
int				my_print_di(t_tag *tag, va_list ap);
int				my_print_u(t_tag *tag, va_list ap);
int				my_print_s(t_tag *tag, va_list ap);
int				my_print_c(t_tag *tag, va_list ap);
int				my_print_p(t_tag *tag, va_list ap);
int				my_print_prc(t_tag *tag);
int				print_padding(char c, int n);
int				is_set(char c, char *set);
int				get_n_size(long long n, char *base);
int				get_nu_size(unsigned int n, char *base);
int				ft_putnbr_base(int nb, char *base);
int				ft_putnbr_u_base(unsigned int nb, char *base);
char			*ft_lltoa_base_x(long unsigned int n, const char *base);
int				process_before_n_addon(t_tag *tag, int l_nbr, int nbr);

#endif
