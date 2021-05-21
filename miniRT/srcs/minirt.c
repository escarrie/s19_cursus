/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:34:25 by escarrie          #+#    #+#             */
/*   Updated: 2021/03/19 13:56:25 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		calc_pixel_color(int *edge_color, int last[2], t_wrapper *w)
{
	t_rss	rss;
	int		*color;

	rss.limit = 3;
	rss.xres = w->data.xres;
	rss.yres = w->data.yres;
	rss.i = w->i;
	rss.j = w->j;
	w->data.bgr = 0x202020;
	color = simple_pixel(edge_color, last, rss, w);
	if (color_difference(color[0], color[3]) ||
		color_difference(color[1], color[2]))
		return (supersimple(color, rss, w));
	return (average_supersimpled_color(color));
}

t_p3	refract_ray(t_p3 d, t_p3 normal, t_figures *lst)
{
	double cosi;
	double etai;
	double etat;
	double eta;
	double k;

	cosi = dot(d, normal);
	etai = 1;
	etat = lst->refr_idx;
	if (lst->fig.sp.inside == 1)
	{
		k = etai;
		etai = etat;
		etat = k;
	}
	eta = etai / etat;
	k = 1 - eta * eta * (1 - cosi * cosi);
	return (k < 0 ? reflect_ray(scal_x_vec(-1, d), normal)
					: vadd(scal_x_vec(eta, d),
						scal_x_vec(eta * cosi - sqrt(k), normal)));
}

void	render_scene(t_wrapper *w)
{
	int edge_color[w->data.xres + 2];
	int last[3];
	int color;
	int n;

	n = w->data.yres / NUM_THREADS;
	w->j = n * w->tid;
	while (w->j < (n * (w->tid + 1)))
	{
		w->i = 0;
		while (w->i < w->data.xres)
		{
			color = calc_pixel_color(edge_color, last, w);
			w->mlx.cam->px_img[w->j * w->data.xres + w->i] = color;
			w->i++;
		}
		if (w->tid == NUM_THREADS - 1)
			ft_printf("\rRendering scene... (cam %d/%d) [%d%%]",
						w->mlx.cam->idx, w->data.cam_nb, 100 * (w->j % n) / n);
		w->j++;
	}
	if (w->tid == NUM_THREADS - 1)
		ft_printf("\rRendering scene... (cam %d/%d) [100%%]\n",
					w->mlx.cam->idx, w->data.cam_nb);
}

int		trace_ray(t_p3 o, t_p3 d, t_wrapper *w, int depth)
{
	t_v3		ray;
	t_figures	cl_fig;
	t_inter		inter;
	double		closest_intersection;
	double		r;

	ray.o = o;
	ray.d = d;
	closest_intersection = INFINITY;
	cl_fig.flag = -1;
	try_all_intersections(ray, w->lst, &cl_fig, &closest_intersection);
	inter.p = vadd(o, scal_x_vec(closest_intersection, d));
	calc_normal(inter.p, d, &(inter.normal), &cl_fig);
	inter.color = (cl_fig.flag != -1) ? cl_fig.color : w->data.bgr;
	apply_texture(cl_fig.texture, &inter, w->lst);
	compute_light(ray, &inter, w->data, w->lst);
	r = cl_fig.flag != -1 ? cl_fig.refl_idx : 0;
	cl_fig.refr_idx = cl_fig.flag != -1 ? cl_fig.refr_idx : 0;
	if (cl_fig.refr_idx > 0)
		inter.color = trace_ray(inter.p,
							refract_ray(d, inter.normal, &cl_fig), w, depth);
	if (r > 0 && depth > 0)
		inter.ref_color = trace_ray(inter.p,
				reflect_ray(scal_x_vec(-1, d), inter.normal), w, depth - 1);
	return (cadd(cproduct(inter.color, 1 - r), cproduct(inter.ref_color, r)));
}

int		main(int ac, char **av)
{
	t_wrapper	wrapper[NUM_THREADS];
	t_minilibx	mlx;
	t_scene		data;
	t_figures	*lst;

	if (OS_NAME == 3)
		fatal("Something not work");
	if (ac < 2 || ac > 3)
		usage(av[0]);
	if (ac == 3 && ft_strncmp(av[2], "--save", ft_strlen(av[2])))
		scene_error("Invalid argument");
	parse_scene(&mlx, &data, &lst, av);
	init_mlx(&mlx, &data);
	wrapp_data(mlx, data, lst, wrapper);
	multithreaded_render(wrapper);
	if (ac == 3)
		save_as_bmp(mlx, data, av[1]);
	succes_message(ac);
	graphic_loop(mlx, data, av);
	return (0);
}
