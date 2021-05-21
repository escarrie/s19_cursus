/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:44:29 by escarrie          #+#    #+#             */
/*   Updated: 2021/03/19 14:07:27 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		parse_res(t_scene *data, char **str)
{
	if (data->res_init > 0)
		scene_error("Resolution (R) can only be declared once in the scene\n");
	else
		data->res_init = 1;
	next(str);
	data->xres = stoi(str);
	in_range(data->xres, 1, INFINITY, "resolution");
	data->yres = stoi(str);
	in_range(data->yres, 1, INFINITY, "resolution");
}

void		parse_ambient_light(t_scene *data, char **str)
{
	if (data->al_init > 1)
		scene_error(
			"Ambient lightning (A) can only be declared once in the scene\n");
	else
		data->al_init = 1;
	next(str);
	data->ambient_light = stof(str);
	in_range(data->ambient_light, 0, 1, "ambient lightning");
	data->al_color = parse_color(str);
}

void		parse_camera(t_minilibx *mlx, t_scene *data, char **str)
{
	t_camera	*elem;
	t_camera	*begin;
	int			prev_idx;

	prev_idx = 0;
	begin = mlx->cam;
	elem = ec_malloc(sizeof(t_camera));
	elem->next = NULL;
	if (mlx->cam)
	{
		while (mlx->cam->next)
			mlx->cam = mlx->cam->next;
		prev_idx = mlx->cam->idx;
		mlx->cam->next = elem;
	}
	else
		mlx->cam = elem;
	next(str);
	elem->idx = prev_idx + 1;
	data->cam_nb = elem->idx;
	elem->o = parse_p3(str);
	elem->nv = normalize(parse_p3(str));
	elem->fov = stoi(str);
	in_range(elem->fov, 0, 180, "camera");
	mlx->cam = begin ? begin : elem;
}

void		parse_light(t_scene **data, char **str)
{
	t_light	*elem;
	t_light	*list;
	t_light *begin;

	begin = (*data)->l;
	list = (*data)->l;
	elem = ec_malloc(sizeof(t_light));
	elem->next = NULL;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elem;
		list = list->next;
	}
	else
		list = elem;
	next(str);
	list->o = parse_p3(str);
	list->br = stof(str);
	in_range(list->br, 0, 1, "light");
	list->color = parse_color(str);
	(*data)->l = begin ? begin : list;
}

void		parse_cylinder(t_figures **elem, char **str)
{
	t_figures	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = CY;
	next(str);
	lst->fig.cy.c = parse_p3(str);
	lst->fig.cy.nv = normalize(parse_p3(str));
	lst->fig.cy.r = stof(str) / 2;
	in_range(lst->fig.cy.r, 0, INFINITY, "cylinder");
	lst->fig.cy.h = stof(str);
	in_range(lst->fig.cy.h, 0, INFINITY, "cylinder");
	lst->specular = stoi(str);
	in_range(lst->specular, 0, INFINITY, "cylinder");
	lst->refl_idx = stof(str);
	in_range(lst->refl_idx, 0, 1, "cylinder");
	lst->refr_idx = stof(str);
	in_range(lst->refr_idx, 0, INFINITY, "cylinder");
	lst->texture = stoi(str);
	in_range(lst->texture, 0, 5, "cylinder");
	if (lst->texture == 2)
		lst->wavelength = stof(str);
	lst->color = parse_color(str);
}
