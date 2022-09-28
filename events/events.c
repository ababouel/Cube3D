/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:35:59 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/27 23:53:50 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "tools.h"
#include "raycast.h"

int	close_game(t_vars *vars)
{
	clear_data(vars);
	return (0);
}

int	esc_key(int keynum, t_vars *vars)
{
	// t_vector *v;
	if (keynum == ESC_KEY)
		clear_data(vars);
	if (keynum == ARROWRIGHT)
	{ 
		climg(vars->iarg);
		vars->ordr.angle += 5;
		rotation(vars->ordr.dir1, vars->ordr.angle);
		debug_draw_vect(50,vars);
	}
	else if (keynum == ARROWLEFT)
	{
		climg(vars->iarg);
		vars->ordr.angle -= 5;
		rotation(vars->ordr.dir1, vars->ordr.angle);
		debug_draw_vect(50,vars);
	}
	else if (keynum == ARROWUP)
	{
		// climg(vars->iarg);
		// v = addvect(-1,-1,add_color(255,0,0,0));	
		// vect_add(vars->ordr.origin, v);
		// debug_draw_vect(50,vars);		
	}
	else if (keynum == ARROWDOWN)
	{
		// climg(vars->iarg);
		// v = addvect(1,1,add_color(255,0,0,0));
		// rotation(v,vars->ordr.angle);
		// vect_add(vars->ordr.origin, v);	
		// debug_draw_vect(50,vars);			
	}
	return (0);
}

void	clear_data(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_destroy_image(vars->mlx, vars->iarg->img);
	mlx_destroy_window(vars->mlx, vars->win);
	//free array of map
	// while (i < vars->line_count)
	// {
	// 	free(vars->map_colors[i]);
	// 	free(vars->map_values[i]);
	// 	i++;
	// }
	// free(vars->map_colors);
	// free(vars->map_values);
	free(vars->iarg);
	free(vars);
	exit(0);
}

void	climg(t_imgarg *img)
{
	t_vector	v;
	char		*pixel;

	v.y = 0;
	while (v.y < WINDOW_HEIGHT)
	{
		v.x = 0;
		while (v.x < WINDOW_WIDTH)
		{
			pixel = img->addr +((int)v.y * img->line_len + (int)v.x * (img->bpp / 8));
			*(unsigned int *)pixel = 0x000000;
			v.x++;
		}
		v.y++;
	}
}