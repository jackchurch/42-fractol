/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchurch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:58:47 by jchurch           #+#    #+#             */
/*   Updated: 2022/10/06 11:58:51 by jchurch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <math.h>

int	main(int argc, char **argv)
{
	t_vars	mlx;

	if (argc != 2)
		return (1);
	if (argv[1][0] == 'm')
		mlx.type = 1;
	else if (argv[1][0] == 'j')
		mlx.type = 2;
	else
		return (1);
	window_setup(&mlx);
	return (0);
}

void	window_setup(t_vars *mlx)
{	
	mlx->mlx = mlx_init();
	if (mlx->type == 1)
		mlx->win = mlx_new_window(mlx->mlx,
				WINDOWS_SIZE_X, WINDOWS_SIZE_Y, "Mandelbrot");
	if (mlx->type == 2)
		mlx->win = mlx_new_window(mlx->mlx,
				WINDOWS_SIZE_X, WINDOWS_SIZE_Y, "Julia");
	mlx->color = 0x0000FFAB;
	mlx->grid_x_min = GRID_X_MIN;
	mlx->grid_x_max = GRID_X_MAX;
	mlx->grid_y_min = GRID_Y_MIN;
	mlx->grid_y_max = GRID_Y_MAX;
	if (mlx->type == 1)
		move(124, mlx);
	locate_next(mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_mouse_hook(mlx->win, mouse, mlx);
	mlx_loop(mlx->mlx);
}

void	locate_next(t_vars *mlx)
{
	double	x;
	double	y;

	mlx->current_x = 0;
	mlx->current_y = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->current_y < WINDOWS_SIZE_Y)
	{
		while (mlx->current_x < WINDOWS_SIZE_X)
		{
			x = mlx->grid_x_min + mlx->current_x * (
					mlx->grid_x_max - mlx->grid_x_min) / WINDOWS_SIZE_X;
			y = mlx->grid_y_max - mlx->current_y * (
					mlx->grid_y_max - mlx->grid_y_min) / WINDOWS_SIZE_Y;
			if (mlx->type == 1)
				mandelbrot(x, y, mlx);
			else
				julia(x, y, mlx);
			mlx->current_x++;
		}
		mlx->current_y++;
		mlx->current_x = 0;
	}
}

int	mandelbrot(double a, double b, t_vars *mlx)
{
	int		i;
	double	ca;
	double	cb;
	double	twoab;

	ca = a;
	cb = b;
	i = 1;
	while (i < ITERATION_MAX)
	{
		twoab = 2 * a * b;
		a = a * a - b * b + ca;
		b = twoab + cb;
		if (fabs(a * a + b * b) > 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->current_x,
				mlx->current_y, mlx->color * i / ITERATION_MAX);
			return (0);
		}
		i++;
	}
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->current_x, mlx->current_y, 0x000000);
	return (0);
}

int	julia(double a, double b, t_vars *mlx)
{
	int		iteration;
	double	ca;
	double	cb;
	double	twoab;

	iteration = 0;
	ca = mlx->julia_x;
	cb = mlx->julia_y;
	while (iteration < ITERATION_MAX)
	{
		twoab = 2 * a * b;
		a = a * a - b * b + 0 + ca;
		b = twoab + 0 + cb;
		if (fabs(a * a + b * b) > 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->current_x,
				mlx->current_y, mlx->color * iteration / ITERATION_MAX);
			return (0);
		}
		iteration++;
	}
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->current_x, mlx->current_y, 0x000000);
	return (0);
}
