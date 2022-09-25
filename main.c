/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/25 02:19:47 by ababouel         ###   ########.fr       */
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
	t_vars		*vars;
	t_vector	v1;
	t_vector	v;

	vars = malloc(sizeof(t_vars));
	vars->iarg = malloc(sizeof(t_imgarg));
	v.color = malloc(sizeof(t_color));
	v.x = 300;
	v.y = 10;
	v1.x = 300;
	v1.y = 300;
	v.color->bl = 0;
	v.color->rd = 255;
	v.color->gr = 0;
	v.color->al= 0;
	v1.color->bl = 0;
	v1.color->rd = 255;
	v1.color->gr = 0;
	v1.color->al= 0;
	vars->mlx = mlx_init();
	vars->mlx = mlx_init();
   	vars->win = mlx_new_window(vars->mlx, 600, 600, "cub3d");	
	vars->iarg->img = mlx_new_image(vars->mlx, 600, 600);
	vars->iarg->addr = mlx_get_data_addr(vars->iarg->img, &vars->iarg->bpp, &vars->iarg->line_len, &vars->iarg->endian);
	// draw_line(&v2,&v1,vars);
	draw_circle(vars, &v1, &v, 0.1);
	mlx_put_image_to_window( vars->mlx, vars->win, vars->iarg->img, 0,0);
	mlx_key_hook(vars->win, ft_close, &vars);	
	mlx_loop(vars->mlx);
}	