/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Esteban <Esteban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:07:57 by escarrie          #+#    #+#             */
/*   Updated: 2020/07/14 09:32:14 by Esteban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_check_line(char *str)
{
	size_t i;

	i = 0;
	while (str && str[i])
		if (str[i++] == '\n')
			return (i);
	return (0);
}

int		gnl_check_rest(char *rest, char **line)
{
	size_t	pos_n;

	pos_n = gnl_check_line(rest);
	if (pos_n)
	{
		*line = gnl_substr(rest, 0, pos_n - 1);
		ft_memcpy(rest, &rest[pos_n], ft_strlen(&rest[pos_n]));
		return (1);
	}
	return (0);
}

int		gnl_manager_cpy(char *line_tmp, char **line, char *rest, size_t pos_n)
{
	*line = gnl_substr(line_tmp, 0, pos_n - 1);
	ft_memcpy(rest, &line_tmp[pos_n], ft_strlen(&line_tmp[pos_n]));
	free(line_tmp);
	return (1);
}

int		gnl_read(int fd, char **line, char *buf, char *rest)
{
	int		res;
	size_t	pos_n;
	char	*line_tmp;

	line_tmp = gnl_join(rest, "", 0);
	*rest = '\0';
	while ((res = read(fd, buf, BUFFER_SIZE)))
	{
		buf[res] = '\0';
		line_tmp = gnl_join(line_tmp, buf, 1);
		pos_n = gnl_check_line(line_tmp);
		if (pos_n)
			return (gnl_manager_cpy(line_tmp, line, rest, pos_n));
	}
	if (res == 0)
	{
		buf[res] = '\0';
		line_tmp = gnl_join(line_tmp, buf, 1);
		pos_n = gnl_check_line(line_tmp);
		if (pos_n)
			return (gnl_last_rest_containt_n(line_tmp, line, rest, pos_n));
		*line = line_tmp;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	rest[BUFFER_SIZE + 1];
	char		*buf;
	int			ret;

	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1 || read(fd, buf, 0))
		return (-1);
	if (gnl_check_rest(rest, line) == 1)
	{
		free(buf);
		return (1);
	}
	ret = gnl_read(fd, line, buf, rest);
	free(buf);
	return (ret);
}
