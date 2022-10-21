
#include "fract_ol.h"
#include <math.h>
#include <stdio.h>

int mandelbrot (double a, double b, t_vars *mlx)
{
	printf("Mandelbrot: a:\t%f, b:\t%f, mlx\n", a, b);

	int iteration = 0;
	double ca = a;
	double cb = b;
	double  aa;
	double	bb;
	double	twoab;

	while (iteration < ITERATION_MAX) //should this move to save computing resources
	{
		printf("\niteration:\t%i\n", iteration);
		aa = a * a;
		bb = b * b;
		twoab = 2 * a * b;
		a = aa - bb + ca;
		b = twoab + cb;
		printf("|aa + bb|:\t%f\n", fabs(a*a + b*b));
		if (fabs(a*a + b*b) > 16)
		{
			printf("Make colour: current_x:\t%f, current_y:\t%f\n", mlx->current_x, mlx->current_y);
			
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->current_x, mlx->current_y, 0x00E8000F * iteration / ITERATION_MAX);
			return (0);
		}
		iteration++;
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

