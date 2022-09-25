/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/25 05:32:49 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "draw.h" 
#include <assert.h>
#include "events.h"

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

t_vector *addvect(float x, float y)
{
	t_vector *v;
	v = malloc(sizeof(t_vector));
	v->x = x;
	v->y = y;

	return (v);
}


t_vars	*allocate(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		return (NULL);
	vars->iarg = (t_imgarg *)malloc(sizeof(t_imgarg));
	if (vars->iarg == NULL)
		return (NULL);
	return (vars);
}

int    ft_init(t_vars *vars)
{
    vars->mlx = mlx_init();
	if (!vars->mlx)
		return (MLX_ERROR);
	vars->win = mlx_new_window(vars->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "vars");
	if (!vars->win)
	{
		free(vars);
		return (MLX_ERROR);
	}
	vars->iarg->img= mlx_new_image(vars->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->iarg->addr = mlx_get_data_addr(vars->iarg->img,
			&vars->iarg->bpp, &vars->iarg->line_len, &vars->iarg->endian);
	return (0);
}

int	main(void)
{
	t_vars		*vars;
	t_vector	v;
	t_rect		*rect;

	vars = allocate();
	v.color = malloc(sizeof(t_color));
	rect = malloc(sizeof(t_rect));
	rect->height = 32;
	rect->width = 32;
	v.x = 250;
	v.y = 55;
	v.color->bl = 0;
	v.color->rd = 255;
	v.color->gr = 0;
	v.color->al= 0;
	rect->vrect = &v;
	ft_init(vars);
	// draw_line(&v2,&v1,vars);
	// draw_circle(vars, &v1, &v, 0.1);
	draw_rect(vars, rect);
	mlx_put_image_to_window( vars->mlx, vars->win, vars->iarg->img, 0,0);
	mlx_key_hook(vars->win, esc_key, vars);
	mlx_hook(vars->win, 17, 0, close_game, vars);
	mlx_loop(vars->mlx);
}	