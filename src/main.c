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

int	main(int argc, char **argv)
{
	t_vars	mlx;

	if (argc != 2)
	{
		printf("argc not 2");
		return (1);
	}
	if (argv[1][0] == 'm')
	{
		mlx.type = 1;
		printf("mlx.type is %i", mlx.type);
	}
	else if (argv[1][0] == 'j')
	{
		printf("mlx.type is %i", mlx.type);
		mlx.type = 2;
	}
	else
	{
		printf("exiting");
		return (1);
	}
	
	printf("running window_setup");
	window_setup(&mlx);

	return (0);
}
