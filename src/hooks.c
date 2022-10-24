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

// #include "fract_ol.h"
#include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>

#include "fract_ol.h"
#include <stdio.h>



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
		if (keycode == 123)
			dx *= -1;
		mlx->grid_x_min += dx / 7.5;
		mlx->grid_x_max += dx / 7.5;
	}
	if (keycode == 126 || keycode == 125)
	{
		if (keycode == 125)
			dy *= -1;
		mlx->grid_y_min += dy / 7.5;
		mlx->grid_y_max += dy / 7.5;
	}
}

int	keys(int keycode, t_vars *mlx)
{
	if (keycode == 53)
		move(keycode, mlx);
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
	locate_next(mlx);
	return (0);
}

int	zoom(int keycode, int x, int y, t_vars *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->grid_x_max - mlx->grid_x_min) / WINDOWS_SIZE_X;
	dy = (mlx->grid_y_max - mlx->grid_y_min) / WINDOWS_SIZE_Y;
	if (keycode == 5)
	{
		mlx->grid_x_min = (mlx->grid_x_min + ((dx * x) * 0.5));
		mlx->grid_x_max = (mlx->grid_x_max - ((dx *(WINDOWS_SIZE_X - x)) * 0.5));
		mlx->grid_y_max = (mlx->grid_y_max - ((dy * y) * 0.5));
		mlx->grid_y_min = (mlx->grid_y_min + ((dy * (WINDOWS_SIZE_Y - y)) * 0.5));
	}
	if (keycode == 4)
	{
		mlx->grid_x_min = (mlx->grid_x_min - ((dx * x) * 0.5));
		mlx->grid_x_max = (mlx->grid_x_max + ((dx * (WINDOWS_SIZE_X - x)) * 0.5));
		mlx->grid_y_max = (mlx->grid_y_max + ((dy * y) * 0.5));
		mlx->grid_y_min = (mlx->grid_y_min - ((dy * (WINDOWS_SIZE_Y - y)) * 0.5));
	}
	if (keycode == 1 || keycode == 2)
	{
		mlx->julia_x  = (mlx->grid_x_min + x * (mlx->grid_x_max - mlx->grid_x_min) / WINDOWS_SIZE_X);
		mlx->julia_y = (mlx->grid_y_max - y * (mlx->grid_y_max - mlx->grid_y_min) / WINDOWS_SIZE_Y);
	}
	printf("Hello from mouse_hook:\n\tmousecode is %d\n\t\tx is %f\n\t\ty is %f\n", keycode, mlx->julia_x, mlx->julia_y);

	locate_next(mlx);
	return (0);
}


// int	key_hook(int keycode, t_vars *vars)
// {
// 	if (vars->mlx){
// 		if (keycode == 53)
// 			exit(0);
// 		if (keycode == 8)
// 			vars->color += 0x00321123;
// 		if (keycode == 1)
// 			vars->julia_y += 0.2;
// 		if (keycode == 13)
// 			vars->julia_y -= 0.2;
// 		if (keycode == 0)
// 			vars->julia_x -= 0.2;
// 		if (keycode == 2)
// 			vars->julia_x += 0.2;
// 		else
// 			move(keycode, vars);
// 		printf("\nHello from key_hook, keycode is %d", keycode);
// 	}
// 	return (0);
// }

// void	move(int keycode, t_vars *vars)
// {
// 	double	x;
// 	double	y;

// 	x = vars->grid_x_max - vars->grid_x_min;
// 	y = vars->grid_y_max - vars->grid_y_min;
// 	if (keycode == 123 || keycode == 124)
// 	{
// 		if (keycode == 123)
// 			x *= -1;
// 		vars->grid_x_min += x;
// 		vars->grid_x_max += x;
// 	}
// 	if (keycode == 125 || keycode == 126)
// 	{
// 		if (keycode == 125)
// 			y *= -1;
// 		vars->grid_y_min += y;
// 		vars->grid_y_max += y;
// 	}

// }

// int	zoom(int mousecode, int x, int y, t_vars *vars)
// {
// 	if (vars->mlx)
// 	{
// 		double	dx;
// 		double	dy;

// 		dx = (vars->grid_x_max - vars->grid_x_min) / WINDOWS_SIZE_X;
// 		dy = (vars->grid_y_max - vars->grid_y_min) / WINDOWS_SIZE_Y;
// 		if (mousecode == 4)
// 		{
// 			vars->grid_x_min -=  dx * x * 0.5;
// 			vars->grid_x_max += dx * (WINDOWS_SIZE_X - x) * 0.5;
// 			vars->grid_y_max += dy * y * 0.5;
// 			vars->grid_y_min -= dy * (WINDOWS_SIZE_Y - y) * 0.5;
// 		}
// 		if (mousecode== 5)
// 		{
// 			vars->grid_x_min +=  dx * x * 0.5;
// 			vars->grid_x_max -= dx * (WINDOWS_SIZE_X - x) * 0.5;
// 			vars->grid_y_max -= dy * y * 0.5;
// 			vars->grid_y_min += dy * (WINDOWS_SIZE_Y - y) * 0.5;
// 		}
// 		printf("Hello from mouse_hook:\n\tmousecode is %d\n\t\tx is %d\n\t\ty is %d\n", mousecode, x, y);

// 		locate_next(vars);
// 	}
// 	return (0);
// }
