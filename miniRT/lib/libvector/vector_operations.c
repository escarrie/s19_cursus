/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:40:30 by escarrie          #+#    #+#             */
/*   Updated: 2021/01/25 13:40:32 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvct.h"

t_p3		vdefine(double x, double y, double z)
{
	t_p3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_p3		vadd(t_p3 a, t_p3 b)
{
	t_p3	p;

	p.x = a.x + b.x;
	p.y = a.y + b.y;
	p.z = a.z + b.z;
	return (p);
}

t_p3		vsubstract(t_p3 a, t_p3 b)
{
	t_p3	p;

	p.x = a.x - b.x;
	p.y = a.y - b.y;
	p.z = a.z - b.z;
	return (p);
}

double		dot(t_p3 a, t_p3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_p3		cross(t_p3 a, t_p3 b)
{
	t_p3	cp;

	cp.x = a.y * b.z - a.z * b.y;
	cp.y = a.z * b.x - a.x * b.z;
	cp.z = a.x * b.y - a.y * b.x;
	return (cp);
}
