/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:42:32 by escarrie          #+#    #+#             */
/*   Updated: 2021/01/25 13:42:41 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

# include "minirt.h"

typedef struct	s_sphere
{
	t_p3	c;
	double	r;
	int		inside;
}				t_sphere;

typedef struct	s_plane
{
	t_p3	p;
}				t_plane;

typedef struct	s_square
{
	t_p3	c;
	double	side;

}				t_square;

typedef struct	s_cylinder
{
	t_p3	c;
	t_p3	nv;
	double	r;
	double	h;
	double	dist1;
	double	dist2;
}				t_cylinder;

typedef struct	s_triangle
{
	t_p3	p1;
	t_p3	p2;
	t_p3	p3;
}				t_triangle;

union			u_figures
{
	t_sphere	sp;
	t_plane		pl;
	t_square	sq;
	t_cylinder	cy;
	t_triangle	tr;
};

#endif
