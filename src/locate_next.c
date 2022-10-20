
#include "fract_ol.h"

//if zooming don't remake the grid, seperate grid setup. 
void	locate_next(t_vars *mlx) 
{
	double x;
	double y;

	mlx->current_x = 0;
	mlx->current_y = 0;

	while (mlx->current_y < WINDOWS_SIZE_Y)
	{
		while (mlx->current_x < WINDOWS_SIZE_X)
		{
			x = mlx->grid_x_min + mlx->current_x * (mlx->grid_y_max - mlx->grid_x_min) / WINDOWS_SIZE_X;
			y = mlx->grid_y_max - (mlx->grid_y_max - mlx->grid_y_min) * mlx->current_y / WINDOWS_SIZE_Y;
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




