/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchurch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:18:52 by jchurch           #+#    #+#             */
/*   Updated: 2022/10/11 15:18:54 by jchurch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdlib.h>

void	move(int keycode, t_vars *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->grid_x_max - mlx->grid_x_min);
	dy = (mlx->grid_y_max - mlx->grid_y_min);
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 124)
	{
		if (keycode == 124)
			dx *= -1;
		mlx->grid_x_min += dx / 7.5;
		mlx->grid_x_max += dx / 7.5;
	}
	if (keycode == 126 || keycode == 125)
	{
		if (keycode == 126)
			dy *= -1;
		mlx->grid_y_min += dy / 7.5;
		mlx->grid_y_max += dy / 7.5;
	}
}

int	keys(int keycode, t_vars *mlx)
{
	if (keycode == 8)
		mlx->color += 0x00321123;
	if (keycode == 1)
		mlx->julia_y += 0.2;
	if (keycode == 13)
		mlx->julia_y -= 0.2;
	if (keycode == 0)
		mlx->julia_x -= 0.2;
	if (keycode == 2)
		mlx->julia_x += 0.2;
	move(keycode, mlx);
	locate_next(mlx);
	return (0);
}

int	mouse(int keycode, int x, int y, t_vars *mlx)
{
	if (keycode == 4 || keycode == 5)
		zoom(keycode, x, y, mlx);
	if (keycode == 1 || keycode == 2)
	{
		mlx->julia_x = (mlx->grid_x_min + x * (
					mlx->grid_x_max - mlx->grid_x_min) / WINDOWS_SIZE_X);
		mlx->julia_y = (mlx->grid_y_max - y * (
					mlx->grid_y_max - mlx->grid_y_min) / WINDOWS_SIZE_Y);
	}
	locate_next(mlx);
	return (0);
}

void	zoom(int keycode, int x, int y, t_vars *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->grid_x_max - mlx->grid_x_min) / WINDOWS_SIZE_X;
	dy = (mlx->grid_y_max - mlx->grid_y_min) / WINDOWS_SIZE_Y;
	if (keycode == 5)
	{
		mlx->grid_x_min = mlx->grid_x_min + dx * x * 0.5;
		mlx->grid_x_max = mlx->grid_x_max - dx * (WINDOWS_SIZE_X - x) * 0.5;
		mlx->grid_y_max = mlx->grid_y_max - dy * y * 0.5;
		mlx->grid_y_min = mlx->grid_y_min + dy * (WINDOWS_SIZE_Y - y) * 0.5;
	}
	if (keycode == 4)
	{
		mlx->grid_x_min = mlx->grid_x_min - dx * x * 0.5;
		mlx->grid_x_max = mlx->grid_x_max + dx * (WINDOWS_SIZE_X - x) * 0.5;
		mlx->grid_y_max = mlx->grid_y_max + dy * y * 0.5;
		mlx->grid_y_min = mlx->grid_y_min - dy * (WINDOWS_SIZE_Y - y) * 0.5;
	}
}
