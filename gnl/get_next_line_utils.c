/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:47:10 by escarrie          #+#    #+#             */
/*   Updated: 2020/02/18 15:06:33 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*gnl_join(char *s1, char *s2, int flag_free)
{
	char			*s_cat;
	size_t			len_two_string;
	size_t			i;
	size_t			j;

	if (!s1 || !s2)
		return (NULL);
	len_two_string = ft_strlen(s1);
	len_two_string += ft_strlen(s2);
	if (!(s_cat = (char *)malloc(sizeof(char) * len_two_string + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		s_cat[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		s_cat[i++] = s2[j++];
	s_cat[i] = '\0';
	if (flag_free)
		free(s1);
	return (s_cat);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	if (len + start > ft_strlen(s) && start < ft_strlen(s))
		len = (ft_strlen(s) - start);
	if (!(tmp = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	i = -1;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (!dst || !src)
		return (NULL);
	if (tmp_dst == NULL && tmp_src == NULL)
		return (NULL);
	while (++i < n)
		tmp_dst[i] = tmp_src[i];
	tmp_dst[i] = '\0';
	return (&dst[0]);
}

int		gnl_last_rest_containt_n(char *line_tmp, char **line,
									char *rest, size_t pos_n)
{
	gnl_manager_cpy(line_tmp, line, rest, pos_n);
	free(line_tmp);
	return (1);
}
