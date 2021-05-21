/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:49:45 by escarrie          #+#    #+#             */
/*   Updated: 2021/03/19 14:17:27 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int		*simple_first_column(int *edge_color, int last[2],
												t_rss rss, t_wrapper *w)
{
	int		*color;

	color = (int *)ec_malloc(sizeof(int) * 4);
	if (rss.j == w->data.yres / NUM_THREADS * w->tid)
	{
		color[0] = calc_ray(0, rss, w);
		color[1] = calc_ray(2, rss, w);
		color[2] = calc_ray(6, rss, w);
		color[3] = calc_ray(8, rss, w);
		last[0] = color[3];
		last[1] = color[1];
		edge_color[0] = color[2];
	}
	else
	{
		color[0] = edge_color[0];
		color[1] = edge_color[1];
		color[2] = calc_ray(6, rss, w);
		color[3] = calc_ray(8, rss, w);
		last[0] = color[3];
		edge_color[0] = color[2];
	}
	return (color);
}

static int		*simple_last_column(int *edge_color, int last[2],
												t_rss rss, t_wrapper *w)
{
	int		*color;

	color = (int *)ec_malloc(sizeof(int) * 4);
	if (rss.j == w->data.yres / NUM_THREADS * w->tid)
	{
		color[0] = last[1];
		color[1] = calc_ray(2, rss, w);
		color[2] = last[0];
		color[3] = calc_ray(8, rss, w);
		edge_color[rss.i] = color[2];
		edge_color[rss.i + 1] = color[3];
	}
	else
	{
		color[0] = edge_color[rss.i];
		color[1] = edge_color[rss.i + 1];
		color[2] = last[0];
		color[3] = calc_ray(3, rss, w);
		edge_color[rss.i] = color[2];
		edge_color[rss.i + 1] = color[3];
	}
	return (color);
}

static int		*simple_center_pixel(int *edge_color, int last[2],
												t_rss rss, t_wrapper *w)
{
	int *color;

	color = (int *)ec_malloc(sizeof(int) * 4);
	if (rss.j == w->data.yres / NUM_THREADS * w->tid)
	{
		color[0] = last[1];
		color[1] = calc_ray(2, rss, w);
		color[2] = last[0];
		color[3] = calc_ray(8, rss, w);
		last[0] = color[3];
		last[1] = color[1];
		edge_color[rss.i] = color[2];
	}
	else
	{
		color[0] = edge_color[rss.i];
		color[1] = edge_color[rss.i + 1];
		color[2] = last[0];
		color[3] = calc_ray(4, rss, w);
		last[0] = color[3];
		edge_color[rss.i] = color[2];
	}
	return (color);
}

int				*simple_pixel(int *edge_color, int last[2],
											t_rss rss, t_wrapper *w)
{
	int	*color;

	if (rss.i == 0)
		color = simple_first_column(edge_color, last, rss, w);
	else if (rss.i == w->data.xres - 1)
		color = simple_last_column(edge_color, last, rss, w);
	else
		color = simple_center_pixel(edge_color, last, rss, w);
	return (color);
}
