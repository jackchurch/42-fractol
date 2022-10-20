/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchurch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:59:44 by jchurch           #+#    #+#             */
/*   Updated: 2022/10/06 11:59:46 by jchurch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define ITERATION_MAX	50
// GRID	{-2, 2, -2, 2} //future self, don't do this
# define GRID_X_MIN -2
# define GRID_X_MAX 2
# define GRID_Y_MIN -2
# define GRID_Y_MAX 2
# define WINDOWS_SIZE_X 600
# define WINDOWS_SIZE_Y 600



typedef struct	s_vars {
	void	*mlx;
	void	*win;
	double	grid_x_min;
	double	grid_x_max;
	double	grid_y_min;
	double	grid_y_max;
	double	current_x;
	double	current_y;
	void	*img; //things from here
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;	// to here may not be needed. From old struct
	int		type;
	int		color;
}				t_vars;

// main.c
int	main(int argc, char **argv);

//hooks.c
int	sl_close(int keycode, t_vars *vars);
int	key_hook(int keycode, t_vars *vars);
int	mouse_hook(int mousecode, int x, int y, t_vars *vars);

//locate_next.c
void	locate_next(t_vars *mlx);

//window_setup.c
int	window_setup(t_vars *mlx);

//mandelbrot.c
int mandelbrot (double x, double y, t_vars *mlx);

//julica.c
int julia (double x, double y, t_vars *mlx);

#endif