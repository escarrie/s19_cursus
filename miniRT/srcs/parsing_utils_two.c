/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:10:02 by escarrie          #+#    #+#             */
/*   Updated: 2021/03/19 14:10:56 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		comma(char **str)
{
	if (**str != ',')
		scene_error("parameters bad formatted\n");
	(*str)++;
}

t_p3		parse_p3(char **str)
{
	t_p3	p;

	p.x = stof(str);
	comma(str);
	p.y = stof(str);
	comma(str);
	p.z = stof(str);
	next(str);
	return (p);
}

int			parse_color(char **str)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	r |= stoi(str);
	in_range(r, 0, 255, "colors must be in range [0, 255],");
	r <<= 16;
	comma(str);
	g |= stoi(str);
	in_range(g, 0, 255, "colors must be in range [0, 255],");
	g <<= 8;
	comma(str);
	b |= stoi(str);
	in_range(b, 0, 255, "colors must be in range [0, 255],");
	return (r | g | b);
}

void		ft_addnewlst_back(t_figures **alst)
{
	t_figures	*begin;
	t_figures	*elem;
	t_figures	*list;

	begin = *alst;
	list = *alst;
	elem = ec_malloc(sizeof(t_figures));
	elem->next = NULL;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elem;
	}
	else
		begin = elem;
	*alst = begin;
}
