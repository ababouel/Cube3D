/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/09 19:51:17 by ababouel         ###   ########.fr       */
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
	"10000N0001",
	"1000000001",
	"1000100001",
	"1000100001",
	"1111111111"
};

int	ft_close(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 49)
		exit(0);
	printf("%d\n", keycode);
	return (0);
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
	void	*p;
	t_vars	vars;
	int		xfloor;
	int		yfloor;
	int		xp;
	int		yp;
	int 	x;
	int		y;
	int		xb;
	int		yb;
	int		xd = 0;
	int		yd = 0;
	
	vars.mlx = mlx_init();
   	vars.win = mlx_new_window(vars.mlx, 600, 600, "cub3d");	
	wall = mlx_xpm_file_to_image(vars.mlx, "./texture/wall.xpm", &x, &y);
	floor = mlx_xpm_file_to_image(vars.mlx, "./texture/floor.xpm", &xfloor, &yfloor);
	p = mlx_xpm_file_to_image(vars.mlx, "./texture/test.xpm", &xp, &yp);	
	yb = 0;
	while (yb < 10 )
	{	
		xb = 0;
		while( xb < 10 )
		{
			if (xb == 0)
				xd = 0;
			if (map[yb][xb] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, wall, xd, yd);
			if (map[yb][xb] == 'N' || map[yb][xb] == '0')
				mlx_put_image_to_window(vars.mlx, vars.win, floor, xd, yd);
			if (map[yb][xb] == 'N')
				mlx_put_image_to_window(vars.mlx, vars.win, p, xd, yd);
			xb++;
			xd += x;
		}
		yb++;
		yd += y;
	}
	mlx_key_hook(vars.win, ft_close, &vars);	
	mlx_loop(vars.mlx);
}
