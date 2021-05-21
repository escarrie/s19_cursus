/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:08:26 by escarrie          #+#    #+#             */
/*   Updated: 2021/03/19 13:38:23 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static t_p3	set_camera(int n, t_rss rss, t_minilibx mlx)
{
	double	img_asp_ratio;
	double	correct_fov;
	double	x_offset;
	double	y_offset;
	t_p3	p;

	x_offset = ((n % 3) * 0.5);
	y_offset = ((n / 3) * 0.5);
	img_asp_ratio = (double)(rss.xres) / (double)(rss.yres);
	correct_fov = tan(mlx.cam->fov * M_PI / 180 / 2);
	p.x =
	((2 * ((rss.i + x_offset) / rss.xres)) - 1) * img_asp_ratio * correct_fov;
	p.y = (1 - (2 * ((rss.j + y_offset) / rss.yres))) * correct_fov;
	p.x *= -1;
	p.z = 1;
	normalize(p);
	return (p);
}

static t_p3	where_look(t_p3 d, t_p3 cam_nv)
{
	t_p3	x_axis;
	t_p3	y_axis;
	t_p3	z_axis;
	t_p3	tmp;
	t_p3	rotated;

	tmp = vdefine(0, 1, 0);
	z_axis = cam_nv;
	if (cam_nv.y == 1 || cam_nv.y == -1)
		x_axis = (cam_nv.y == 1) ? (t_p3) {1, 0, 0} : (t_p3) {0, 0, 1};
	else
		x_axis = cross(tmp, z_axis);
	y_axis = cross(z_axis, x_axis);
	rotated.x = d.x * x_axis.x + d.y * x_axis.y + d.z * x_axis.z;
	rotated.y = d.x * y_axis.x + d.y * y_axis.y + d.z * y_axis.z;
	rotated.z = d.x * z_axis.x + d.y * z_axis.y + d.z * z_axis.z;
	return (rotated);
}

int			calc_ray(int n, t_rss rss, t_wrapper *w)
{
	t_p3	d;
	int		color;

	d = set_camera(n, rss, w->mlx);
	d = where_look(d, w->mlx.cam->nv);
	color = trace_ray(w->mlx.cam->o, d, w, REFLECTION_LIMIT);
	return (color);
}
