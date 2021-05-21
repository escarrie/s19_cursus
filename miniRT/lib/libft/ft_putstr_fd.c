/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:39:00 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/26 12:20:51 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

int		ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	return ((int)ft_strlen(s));
}

int		ft_putstr_n(char *s, int n)
{
	if (s && n <= (int)ft_strlen(s))
		write(1, s, n);
	return (n);
}
