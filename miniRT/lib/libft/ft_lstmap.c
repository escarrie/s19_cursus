/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:05:19 by escarrie          #+#    #+#             */
/*   Updated: 2020/01/19 15:52:37 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mynewlist;
	t_list	*first;

	if (!lst)
		return (NULL);
	if (!(mynewlist = ft_lstnew(f(lst->content))))
		return (NULL);
	first = mynewlist;
	while (lst)
	{
		if (lst->next)
		{
			if (!(mynewlist->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&first, del);
				return (NULL);
			}
			mynewlist = mynewlist->next;
		}
		lst = lst->next;
	}
	mynewlist->next = NULL;
	return (first);
}
