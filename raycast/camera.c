/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:55:30 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/23 04:57:32 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "tools.h"

void	camera(t_vars *vars)
{
	int		x;
	double	dis;
	double	angle;

	x = 0;
	dis = 0.0;
	angle = 0;
	vars->ray.origin = *vars->ordr.origin;
	vars->ray.dir = *vars->ordr.minplane;
	while (x < WINDOW_WIDTH)
	{
		dis = cast_ray(vars, RECT_SIZE);
		draw_wall(dis, vars, &x, angle);
		vars->ray.dir.angle = (1.0 / (WINDOW_WIDTH / 2)) * (M_PI / 6.0);
		angle += vars->ray.dir.angle;
		rotation(&vars->ray.dir, vars->ray.dir.angle);
		x++;
	}
}
