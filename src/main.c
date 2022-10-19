/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchurch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:58:47 by jchurch           #+#    #+#             */
/*   Updated: 2022/10/06 11:58:51 by jchurch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>

void my_mlx_pixel_put(t_data *data, int x, int y, int color){
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	// void	*img;

	int	width = WINDOWS_SIZE_X;
	int	height = WINDOWS_SIZE_X;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 50, 50);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// int x = 0;
	// int y = 0;

	// var a = 

	// while (y < 55)
	// {
	// 	while (x < 55)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 		x++;
	// 	}
	// 	x = 5;
	// 	y++;
	// }
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<0, sl_close, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
