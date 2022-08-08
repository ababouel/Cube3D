/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/08/08 23:10:22 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "draw.h" 
#include <assert.h>
char map[10][10] = {
	"1111111111",
	"1000000001",
	"1000100001",
	"1000100001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000100001",
	"1000100001",
	"1111111111"
};

int	ft_close(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
}
t_vector *addvect(float x, float y)
{
	t_vector *v;
	v = malloc(sizeof(t_vector));
	v->x = x;
	v->y = y;

	return (v);
}
int	main(void)
{
	void	*wall;
	void	*floor;
	void	*mlx;
	void	*new;
	int		xfloor;
	int		yfloor;
	int 	x;
	int		y;
	int		xb;
	int		yb;
	int		xd = 0;
	int		yd = 0;
	
	mlx = mlx_init();
   	new = mlx_new_window(mlx, 1000, 1000, "cub3d");
	// image = mlx_new_image(mlx, 500, 500);
	wall = mlx_xpm_file_to_image(mlx, "./texture/wall.xpm", &x, &y);
	floor = mlx_xpm_file_to_image(mlx, "./texture/floor.xpm", &xfloor, &yfloor);	
	yb = 0;
	while (yb < 10 )
	{	
		xb = 0;
		while( xb < 10 )
		{
			if (xb == 0)
				xd = 0;
			if (map[yb][xb] == '1')
				mlx_put_image_to_window(mlx, new, wall, xd, yd);
			xb++;
			xd += x;
		}
		yb++;
		yd += y;
	}
	xd = 0;
	yd = 0;
	yb = 0;
	while (yb < 10 )
	{	
		xb = 0;
		while( xb < 10 )
		{
			if (xb == 0)
				xd = 0;
			if (map[yb][xb] == '0')
				mlx_put_image_to_window(mlx, new, floor, xd, yd);
			xb++;
			xd += xfloor;
		}
		yb++;
		yd += yfloor;
	}
	mlx_loop(mlx);
}
