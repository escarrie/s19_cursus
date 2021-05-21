/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:58:47 by escarrie          #+#    #+#             */
/*   Updated: 2021/03/19 13:47:29 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	fatal(char *message)
{
	char	error_message[100];

	ft_strlcpy(error_message, "[!!] Fatal error ", 17);
	ft_strlcat(error_message, message, 83);
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	scene_error(char *message)
{
	char	error_message[100];

	ft_strlcpy(error_message, "Scene Error: ", 13);
	ft_strlcat(error_message, message, 87);
	ft_putstr_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void	usage(char *program_name)
{
	ft_printf("Usage: %s <scene.rt>\n", program_name);
	exit(EXIT_FAILURE);
}

void	*ec_malloc(unsigned int size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		fatal("in malloc() on memory allocation");
	return (ptr);
}
