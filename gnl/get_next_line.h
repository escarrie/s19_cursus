/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:07:56 by escarrie          #+#    #+#             */
/*   Updated: 2020/09/20 00:29:37 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

int		get_next_line(int fd, char **line);
size_t	gnl_check_line(char *str);
int		gnl_manager_cpy(char *line_tmp, char **line, char *rest, size_t pos_n);
int		gnl_read(int fd, char **line, char *buf, char *rest);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_join(char *s1, char *s2, int flag_free);
size_t	ft_strlen(char *str);
void	*ft_memcpy(void *dst, void *src, size_t n);
int		gnl_last_rest_containt_n(char *line_tmp, char **line,
									char *rest, size_t pos_n);

#endif
