/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:14:05 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/19 15:46:38 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next;
	t_list *current;

	current = *lst;
	if (del)
		while (current)
		{
			next = current->next;
			(*del)(current->content);
			free(current);
			current = next;
		}
	*lst = 0;
}
