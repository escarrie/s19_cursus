/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:40:21 by escarrie          #+#    #+#             */
/*   Updated: 2021/04/12 20:23:20 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvct.h"

double		mod(t_p3 v)
{
	return (sqrt(dot(v, v)));
}

t_p3		normalize(t_p3 p)
{
	t_p3	nv;
	double	mod;

	mod = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	nv.x = p.x / mod;
	nv.y = p.y / mod;
	nv.z = p.z / mod;
	return (nv);
}

double		vsin(t_p3 a, t_p3 b)
{
	return (sqrt(1 - pow(vcos(a, b), 2)));
}

double		vcos(t_p3 a, t_p3 b)
{
	return (dot(a, b) / (mod(a) * mod(b)));
}

t_p3		scal_x_vec(double n, t_p3 p)
{
	t_p3	v;

	v.x = n * p.x;
	v.y = n * p.y;
	v.z = n * p.z;
	return (v);
}
