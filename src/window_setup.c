
#include "fract_ol.h"
#include <stdio.h>

//struct . will modify data
//sturct -> will dereference

int	window_setup(t_vars *mlx)
{	
	printf("inside windows setup");
	const double window_height = WINDOWS_SIZE_Y; //note to self, remove these and use directly to save line numbers even though it kills me
	const double window_width = WINDOWS_SIZE_X;

	mlx->mlx = mlx_init();

	if (mlx->type == 1)
		mlx->win = mlx_new_window(mlx->mlx, window_width, window_height, "Mandelbrot");
	if (mlx->type == 2)
		mlx->win = mlx_new_window(mlx->mlx, window_width, window_height, "Julia");

	mlx->color = 0;

	mlx->grid_x_min = GRID_X_MIN;
	mlx->grid_x_max = GRID_X_MAX;
	mlx->grid_y_min = GRID_Y_MIN;
	mlx->grid_y_max = GRID_Y_MAX;

	locate_next(mlx);

	mlx_key_hook(mlx->win, key_hook, &mlx);
	mlx_hook(mlx->win, 2, 1L<<0, sl_close, &mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, &mlx);
	mlx_loop(mlx->mlx);

	return (0);
}


//if zooming don't remake the grid