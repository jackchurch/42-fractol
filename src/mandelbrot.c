
#include "fract_ol.h"
#include <math.h>>

int mandelbrot (double x, double y, t_vars *mlx)
{
	int max_iteration = ITERATION_MAX; //use directly to save line space


			int iteration = 0;
			while (iteration < max_iteration) //should this move to save computing resources
			{
				int ca = x;
				int cb = y;
				int a = x;
				int b = y;
				int aabb = a * a - b * b; //real number
				int two_ab = 2*a*b; //imaginary number
				a = aabb + ca;
				b = two_ab + cb;
				if (fabs((double)a + (double)b) > 16) //absolute numbers
				{
					break ;					//colour "artistic" colour
				}
				iteration++;
			}

			//map iteration as 0 to maxitteration into 0 to 255 to set color 

			if (iteration == max_iteration)
				mlx_pixel_put(mlx->mlx, mlx->win, mlx->current_x, mlx->current_y, 0x000000 * iteration / ITERATION_MAX);
			else
				mlx_pixel_put(mlx->mlx, mlx->win, mlx->current_x, mlx->current_y, 0x00008B);
				//pixel color to b lack as it is inthe mandelbrot set

	return (0);
}
