/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:28:06 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/18 11:40:27 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list *new_struct;

	if (!(new_struct = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_struct->content = content;
	new_struct->next = NULL;
	return (new_struct);
}
