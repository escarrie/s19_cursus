/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:08:00 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/19 15:23:08 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t			len_two_string;
	char			*s_cat;

	if (!s1 || !s2)
		return (NULL);
	len_two_string = ft_strlen(s1);
	len_two_string += ft_strlen(s2);
	if (!(s_cat = (char *)malloc(sizeof(char) * len_two_string + 1)))
		return (NULL);
	s_cat[0] = '\0';
	ft_strlcat(s_cat, s1, len_two_string + 1);
	ft_strlcat(s_cat, s2, len_two_string + 1);
	return (s_cat);
}
