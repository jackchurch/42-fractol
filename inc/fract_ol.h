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

#ifndef FRACT_OL_H
# include <mlx.h>
# define FRACT_OL_H
# define ITERATION_MAX	100
# define GRID_X_MIN -2
# define GRID_X_MAX 2
# define GRID_Y_MIN -2
# define GRID_Y_MAX 2
# define WINDOWS_SIZE_X 800
# define WINDOWS_SIZE_Y 800

typedef struct s_vars {
	void	*mlx;
	void	*win;
	double	grid_x_min;
	double	grid_x_max;
	double	grid_y_min;
	double	grid_y_max;
	double	current_x;
	double	current_y;
	int		type;
	int		color;
	double	julia_x;
	double	julia_y;
}	t_vars;

// main.c
int		main(int argc, char **argv);
void	locate_next(t_vars *mlx);
void	window_setup(t_vars *mlx);

//hooks.c
int		ft_exit(void);
void	move(int keycode, t_vars *mlx);
int		keys(int keycode, t_vars *mlx);
int		mouse(int keycode, int x, int y, t_vars *mlx);
void	zoom(int keycode, int x, int y, t_vars *mlx);

//mandelbrot.c
int		mandelbrot(double a, double b, t_vars *mlx);

//julica.c
int		julia(double a, double b, t_vars *mlx);

#endif
