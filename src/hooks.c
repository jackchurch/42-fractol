/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchurch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:18:52 by jchurch           #+#    #+#             */
/*   Updated: 2022/10/11 15:18:54 by jchurch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	sl_close(int keycode, t_vars *vars)
{
	if (keycode == 53) 
	{
	printf("\nkeycode %d", keycode);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (vars->mlx)
		printf("\nHello from key_hook, keycode is %d", keycode);
	if (keycode == 13)
		while (keycode == 13)
			printf("\nkeycode %d", keycode);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	if (vars->mlx)
		printf("Hello from mouse_hook:\n\tmousecode is %d\n\t\tx is %d\n\t\ty is %d\n", mousecode, x, y);
	return (0);
}
