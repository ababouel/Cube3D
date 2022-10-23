/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 03:41:17 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/23 21:11:41 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "raycast.h"
#include "parsing.h"

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
			pixel = img->addr +((int)v.y * img->line_len
					+ (int)v.x * (img->bpp / 8));
			*(unsigned int *)pixel = 0x000000;
			v.x++;
		}
		v.y++;
	}
}

void	clear_data(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_destroy_image(vars->mlx, vars->iarg->img);
	mlx_destroy_window(vars->mlx, vars->win);
	while (i < vars->data->hgt)
	{
		vars->data->map[i] = my_free(vars->data->map[i]);
		i++;
	}
	vars->data->map = my_free(vars->data->map);
	vars->data->wth = my_free(vars->data->wth);
	vars->data->txtpath = my_free(vars->data->txtpath);
	vars->iarg = my_free(vars->iarg);
	vars = my_free(vars);
	exit(0);
}
