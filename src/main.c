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
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_vars	mlx;

	if (argc != 2)
	{
		printf("argc not 2");
		return (1);
	}
	if (argv[1][0] == 'm')
	{
		mlx.type = 1;
		printf("mlx.type is %i", mlx.type);
	}
	else if (argv[1][0] == 'j')
	{
		mlx.constant_x = 0;
		mlx.constant_y = 0;
		mlx.mouse_x = 0;
		mlx.mouse_y = 0;
		printf("mlx.type is %i", mlx.type);
		mlx.type = 2;
	}
	else
	{
		printf("\"./fractol m\" or \"./fractol j\"");
		return (1);
	}
	
	window_setup(&mlx);

	return (0);
}

//struct . will modify data
//sturct -> will dereference

void	window_setup(t_vars *mlx)
{	
		printf("running window_setup\n");

	mlx->mlx = mlx_init();

	if (mlx->type == 1)
		mlx->win = mlx_new_window(mlx->mlx, WINDOWS_SIZE_X, WINDOWS_SIZE_Y, "Mandelbrot");
	if (mlx->type == 2)
		mlx->win = mlx_new_window(mlx->mlx, WINDOWS_SIZE_X, WINDOWS_SIZE_Y, "Julia");

	mlx->color = 0;

	mlx->grid_x_min = GRID_X_MIN;
	mlx->grid_x_max = GRID_X_MAX;
	mlx->grid_y_min = GRID_Y_MIN;
	mlx->grid_y_max = GRID_Y_MAX;

	locate_next((void *)mlx);

	mlx_key_hook(mlx->win, keys, (void *)mlx);
	mlx_mouse_hook(mlx->win, zoom, (void *)mlx);
	mlx_loop(mlx->mlx);
}


//if zooming don't remake the grid

//if zooming don't remake the grid, seperate grid setup. 
void	locate_next(t_vars *mlx) 
{
	double x;
	double y;

	mlx->current_x = 0;
	mlx->current_y = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->current_y < WINDOWS_SIZE_Y)
	{
		while (mlx->current_x < WINDOWS_SIZE_X)
		{
			x = mlx->grid_x_min + mlx->current_x * (mlx->grid_x_max - mlx->grid_x_min) / WINDOWS_SIZE_X;
			y = mlx->grid_y_max - mlx->current_y * (mlx->grid_y_max - mlx->grid_y_min) / WINDOWS_SIZE_Y;
			if (mlx->type == 1)
				mandelbrot(x, y, mlx);
			else
				julia(x, y, mlx);
			mlx->current_x++;
		}
		mlx->current_y++;
		mlx->current_x = 0;
	}

	//divide windows into -2 to 2 grid each axis
	//foreach line - move to own function with the next line


			//foreach -2 to 2 point on the line of the grid
			//perform f(c) = c^2 - c
			//for number of itterations

}
