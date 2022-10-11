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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

// main.c
int		main(void);

//hooks.c
int	sl_close(int keycode, t_vars *vars);
int	key_hook(int keycode, t_vars *vars);
int	mouse_hook(int mousecode, int x, int y, t_vars *vars);

#endif