
#include "fract_ol.h"

int grid_setup (t_vars *mlx) 
{
	double x;
	double y;
	mlx->current_x = 0;
	mlx->current_y = 0;
	double window_height = WINDOWS_SIZE_Y; //note to self, remove these and use directly to save line numbers even though it kills me
	double window_width = WINDOWS_SIZE_X;
	mlx->grid_x_min = GRID_X_MIN;
	// mlx->grid_x_max = mlx->grid_x_min + window_width; //nope
	mlx->grid_x_max = GRID_X_MAX;
	mlx->grid_y_min = GRID_Y_MIN;
	mlx->grid_y_max = GRID_Y_MAX;

	y = 0;
	while (mlx->current_y < window_height)
	{
		x = 0; //hmmmm
		while (mlx->current_x < window_width)
		{
			x = mlx->grid_x_min + mlx->current_x * (mlx->grid_y_max - mlx->grid_x_min) / WINDOWS_SIZE_X;
			y = mlx->grid_y_max - (mlx->grid_y_max - mlx->grid_y_min) * mlx->current_y / WINDOWS_SIZE_Y;
			mandelbrot (x, y, mlx);
			mlx->current_x++;
			x++; //hmmmmmm
		}
		mlx->current_y++;
		mlx->current_x = 0;
		y++; //hmmmmmm
	}
	//divide windows into -2 to 2 grid each axis
	//foreach line - move to own function with the next line


			//foreach -2 to 2 point on the line of the grid
			//perform f(c) = c^2 - c
			//for number of itterations

}
