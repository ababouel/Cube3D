/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/26 05:29:15 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "draw.h" 
#include <assert.h>
#include "events.h"
#include "tools.h"

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
	t_vector	*v1,*v2;

	vars = allocate();
	vars->rect = addvect(500,500,add_color(255,0,0,0));
	v1 = addvect(516,516,add_color(0,0,255,0));
	v2 = addvect(189.264295,210.188074,add_color(0,0,255,0));
	ft_init(vars);
	draw_rect(vars);
	draw_line(v1,v2,vars);
	rotation(v2, 90);	
	draw_line(v1,v2,vars);
	mlx_put_image_to_window( vars->mlx, vars->win, vars->iarg->img, 0,0);
	mlx_key_hook(vars->win, esc_key, vars);
	mlx_hook(vars->win, 17, 0, close_game, vars);
	mlx_loop(vars->mlx);
}	