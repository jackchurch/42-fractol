
#include "fract_ol.h"
#include <math.h>
#include <stdio.h>

int mandelbrot(double x, double y, t_vars *mlx)
{
	// printf("Mandelbrot: a:\t%f, b:\t%f, mlx\n", a, b);
	int		i;
	double	xx;
	double	yy;
	double	temp;

	xx = 0;
	yy = 0;
	i = 1;
	while (i < ITERATION_MAX)
	{
		temp = xx;
		xx = (pow(xx, 2) - pow(yy, 2)) + x;
		yy = (2 * temp * yy) + y;
		if (pow(xx, 2) + pow(yy, 2) > 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->current_x, mlx->current_y, 0x00E8000F * i / ITERATION_MAX);
			return (0);
		}
		i++;
	}
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->current_x, mlx->current_y, 0x000000);
	return (0);
}
	
	/*
	
	for each pixel (Px, Py) on the screen do
    x0 := scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.00, 0.47))
    y0 := scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1.12, 1.12))
    x := 0.0
    y := 0.0
    iteration := 0
    max_iteration := 1000
    while (x*x + y*y ≤ 2*2 AND iteration < max_iteration) do
        xtemp := x*x - y*y + x0
        y := 2*x*y + y0
        x := xtemp
        iteration := iteration + 1
    
    color := palette[iteration]
    plot(Px, Py, color)*/

