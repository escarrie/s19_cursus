/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:29:46 by escarrie          #+#    #+#             */
/*   Updated: 2021/03/19 14:38:48 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "ggl_mlx_define.h"
# include "libft.h"
# include "libvct.h"
# include "figures.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>

# ifdef MACOS
#  define OS_NAME 1
# endif

# ifdef LINUX
#  define OS_NAME 2
# endif

# ifndef OS_NAME
#  define OS_NAME 3
# endif

# define BUFSIZE 32

# ifndef NUM_THREADS
#  define NUM_THREADS 4
# endif

# define REFLECTION_LIMIT 3

# define SP 0
# define PL 1
# define SQ 2
# define TR 3
# define CY 4
# define CU 5
# define PY 6

# define EPSILON 0.00001

/*
**	MES STRUCTURES
*/

typedef struct	s_v3
{
	t_p3 o;
	t_p3 d;
}				t_v3;

typedef struct	s_camera
{
	int				init;
	int				idx;
	t_p3			o;
	t_p3			nv;
	int				fov;
	void			*img_ptr;
	int				*px_img;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	struct s_camera	*next;
}				t_camera;

typedef struct	s_light
{
	t_p3			o;
	double			br;
	int				color;
	struct s_light	*next;
}				t_light;

typedef struct	s_scene
{
	int		res_init;
	int		xres;
	int		yres;
	int		cam_nb;
	t_light	*l;
	int		al_init;
	double	ambient_light;
	int		al_color;
	int		bgr;
}				t_scene;

typedef struct	s_figures
{
	int					flag;
	union u_figures		fig;
	int					color;
	int					specular;
	double				refl_idx;
	double				refr_idx;
	int					texture;
	t_p3				normal;
	double				wavelength;
	struct s_figures	*next;
}				t_figures;

typedef struct	s_minilibx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_camera	*cam;
	t_camera	*begin;
}				t_minilibx;

typedef struct	s_wrapper
{
	t_minilibx	mlx;
	t_scene		data;
	t_figures	*lst;
	int			tid;
	int			i;
	int			j;
}				t_wrapper;

typedef struct	s_rss
{
	int limit;
	int xres;
	int yres;
	int i;
	int j;
}				t_rss;

typedef struct	s_inter
{
	int		color;
	int		ref_color;
	t_p3	normal;
	t_p3	p;
	t_p3	ref_vec;
}				t_inter;

typedef struct	s_bmp_header
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}				t_bmphead;

typedef struct	s_dib_header
{
	unsigned int	size;
	int				width;
	int				height;
	unsigned short	colplanes;
	unsigned short	bpp;
	unsigned int	compression;
	unsigned int	img_size;
	int				x_ppm;
	int				y_ppm;
	unsigned int	color_number;
	unsigned int	important_color;
}				t_dibhead;

typedef struct	s_thread
{
	pthread_t	threads[NUM_THREADS];
	t_wrapper	wrapper[NUM_THREADS];
	int			i;
}				t_thread;

typedef struct	s_sq
{
	t_p3 half_size;
	t_p3 floor;
	t_p3 center_to_ip;
}				t_sq;

typedef struct	s_cube
{
	t_figures	sq;
	t_p3		center;
	t_p3		normal[6];
}				t_cube;

typedef struct	s_pyramid
{
	t_figures	sq;
	t_figures	tr;
	t_p3		tr_center;
	t_p3		normal[5];
	t_p3		corner[4];
}				t_pyr;

/*
**	FUNCTION PARSING
*/

void			parse_scene(t_minilibx *mlx, t_scene *data,
					t_figures **lst, char **av);
void			parse_res(t_scene *data, char **str);
void			parse_ambient_light(t_scene *data, char **str);
void			parse_camera(t_minilibx *mlx, t_scene *data, char **str);
void			parse_light(t_scene **data, char **str);

void			parse_plane(t_figures **elem, char **str);
void			parse_sphere(t_figures **elem, char **str);
void			parse_cylinder(t_figures **elem, char **str);
void			parse_square(t_figures **elem, char **str);
void			parse_triangle(t_figures **elem, char **str);
void			parse_cube(t_figures **elem, char **str);
void			parse_pyramid(t_figures **elem, char **str);
char			*readfile(char *str, int fd);
void			next(char **str);
int				stoi(char **str);
double			stof(char **str);
t_p3			parse_p3(char **str);
void			comma(char **str);
int				parse_color(char **str);
void			ft_addnewlst_back(t_figures **alst);
void			in_range(double nb, double min, double max, char *function);

/*
**	FUNCTION RAY TRACING
*/

void			render_scene(t_wrapper *w);
int				calc_ray(int n, t_rss rss, t_wrapper *w);
int				trace_ray(t_p3 o, t_p3 d, t_wrapper *w, int depth);
void			calc_normal(t_p3 p, t_p3 d, t_p3 *normal, t_figures *l);
void			try_all_intersections(t_v3 ray, t_figures *lst,
					t_figures *closest_figure, double *closest_intersection);
void			compute_light(t_v3 ray, t_inter *inter, t_scene data,
					t_figures *lst);
t_p3			refract_ray(t_p3 d, t_p3 normal, t_figures *lst);
double			calc_specular(t_v3 ray, t_inter *inter, t_scene data,
					t_figures *lst);
void			add_coeficient(double (*rgb)[3], double coef, int color);
int				is_lit(t_p3 o, t_p3 d, t_figures *lst);

/*
**	FUNCTION INTERSECTION SOLVER
*/

double			cylinder_intersection(t_p3 o, t_p3 d, t_figures *lst);
double			sphere_intersection(t_p3 o, t_p3 d, t_figures *lst);
double			square_intersection(t_p3 o, t_p3 d, t_figures *lst);
double			plane_intersection(t_p3 o, t_p3 d, t_figures *lst);
double			solve_plane(t_p3 o, t_p3 d, t_p3 plane_p, t_p3 plane_nv);
double			pyramid_intersection(t_p3 o, t_p3 d, t_figures *lst);
double			cube_intersection(t_p3 o, t_p3 d, t_figures *lst);
double			triangle_intersection(t_p3 o, t_p3 d, t_figures *lst);

/*
**	FUNCTION SIMPELING
*/

int				*simple_pixel(int *edge_color, int last[2],
					t_rss rss, t_wrapper *w);
int				supersimple(int *color, t_rss rss, t_wrapper *w);

/*
**	FUNCTION ERROR
*/

void			*ec_malloc(unsigned int size);
void			fatal(char *message);
void			scene_error(char *message);
void			usage(char *program_name);

/*
**	FUNCTION MULTI RENDERING
*/

void			wrapp_data(t_minilibx mlx, t_scene data, t_figures *lst,
				t_wrapper *wrapper);
void			multithreaded_render(t_wrapper wrapper[NUM_THREADS]);

/*
**	FUNCTION MLX
*/

void			graphic_loop(t_minilibx mlx, t_scene data, char **av);
void			init_mlx(t_minilibx *mlx, t_scene *data);
int				next_cam(int keycode, t_minilibx *mlx);
int				close_program(void *param);
void			succes_message(int ac);

/*
**	FUNCTION COLOR OPERATION
*/

int				average_supersimpled_color(int *color);
int				color_difference(int color1, int color2);
int				color_x_light(int color, double rgb[3]);
int				cadd(int color_a, int color_b);
int				cproduct(int color, double coef);
int				average(int color1, int color2);

/*
**	FUNCTION UTILS
*/

void			apply_texture(int texture, t_inter *inter, t_figures *lst);
t_p3			reflect_ray(t_p3 ray, t_p3 normal);
int				rainbow(t_inter *inter);
void			save_as_bmp(t_minilibx mlx, t_scene data, char *name);

#endif
