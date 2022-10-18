
#include "fract_ol.h"

int mandelbrot (double x, double y, t_data *mlx)
{
	int maxitteration = 18;

		//foreach -2 to 2 point on the line of the grid
			//perform f(c) = c^2 - c
			//for number of itterations
			int iteration = 0;
			while (iteration < maxitteration)
			{
				int ca = a
				int cb = b
				int aabb = a*a - b*b real number
				int two_ab = 2*a*b imaginary number 
				a = aabb + ca
				b = two_ab + bc
				if (|a| + |b| > 16) //absolute numbers
				{
					//colour "artistic" colour
				}
				iteration++;
			}

			//map iteration as 0 to maxitteration into 0 to 255 to set color 

			if (iteration == maxitteration)
				//pixel color to b lack as it is inthe mandelbrot set

	return (0);
}

int mandelbrot_grid(t_data *mlx) 
{
	double	x;
	double	y;

	//get window width and height
	//divide windows into -2 to 2 grid each axis
	//foreach line - move to own function with the next line
