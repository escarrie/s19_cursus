/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:21:13 by escarrie          #+#    #+#             */
/*   Updated: 2021/03/19 14:19:32 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int			close_program(void *param)
{
	param = (void *)param;
	exit(EXIT_SUCCESS);
	return (1);
}

int			next_cam(int keycode, t_minilibx *mlx)
{
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode != SP_KEY)
		return (0);
	if (mlx->cam->next)
	{
		mlx->cam = mlx->cam->next;
		mlx_put_image_to_window(
				mlx->mlx_ptr, mlx->win_ptr, mlx->cam->img_ptr, 0, 0);
	}
	else
	{
		mlx->cam = mlx->begin;
		mlx_put_image_to_window(
				mlx->mlx_ptr, mlx->win_ptr, mlx->cam->img_ptr, 0, 0);
	}
	return (1);
}

void		graphic_loop(t_minilibx mlx, t_scene data, char **av)
{
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, data.xres, data.yres, av[0]);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.cam->img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_program, 0);
	mlx_hook(mlx.win_ptr, KEYPRESS, KEYPRESSMASK, next_cam, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

t_p3		reflect_ray(t_p3 ray, t_p3 normal)
{
	return (vsubstract(scal_x_vec(2 * dot(normal, ray), normal), ray));
}

void		succes_message(int ac)
{
	int	t;

	t = NUM_THREADS;
	if (ac == 2)
	{
		if (NUM_THREADS == 1)
			ft_printf("\nScene successfully render with 1 thread...");
		else
			ft_printf("\nScene successfully render with %d thread...", t);
		ft_printf("\npress ESC at any moment for quit the program");
		ft_printf("\nIf the scene has many camera press SPACE for");
		ft_printf(" change camera");
	}
	else
	{
		ft_printf("\nScene successfully save as BMP\n");
		ft_printf("The file has been saved into \"images\" directory\n\n");
		exit(EXIT_SUCCESS);
	}
}
