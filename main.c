/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/08/06 18:54:33 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "draw.h" 

char **map = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
}

int	rans(int max_number, int minimum_number)
{
	int number;

	number = rand() % (max_number + 1 - minimum_number) + minimum_number;
	return (number);
}

int	close(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
}

int	main(void)
{
	t_vars		vars;
	t_imgarg	img;

	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1280, 720, "cub3d");
	vars.img = mlx_new_image(vars.mlx, 1280, 720);
	img.addr = mlx_get_data_addr(vars.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int x = 1;
	while (x < 720)
	{
		int y = 1;
		while (y < 1280)
		{
			draw_pixel(&img, y, x, create_trgb(128, rans(255, 0), rans(255, 0), rans(255, 0)));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win, 17, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
