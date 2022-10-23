/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:39:13 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/23 00:03:44 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "tools.h"

static int	check_map(t_vars *vars, t_vector *vmin)
{
	t_data	*data;

	data = vars->data;
	if (vmin->y / 30 >= 0 && vmin->y / 30 < data->hgt
		&& vmin->x / 30 >= 0 && vmin->x / 30 < data->wth[(int)vmin->y / 30])
	{
		if (vars->data->map[(int)vmin->y / 30][(int) vmin->x / 30] == '1')
			return (1);
		else if (vars->data->map[(int)vmin->y / 30][(int) vmin->x / 30] == '0'
			|| vars->data->map[(int)vmin->y / 30][(int) vmin->x / 30] == 'N')
			return (2);
	}
	return (0);
}

static void	draw_pixel_map(t_vars *vars, t_vector *vmin, t_vector *vd)
{
	if (check_map(vars, vmin) == 1)
	{
		vd->color = add_color(255, 0, 0);
		draw_pixel(vars->iarg, vd);
	}
	else if (check_map(vars, vmin) == 2)
	{
		vd->color = add_color(255, 255, 255);
		draw_pixel(vars->iarg, vd);
	}
}

static void	draw_playerpos(t_vars *vars)
{
	t_vector	vd;

	vd.color = add_color(0, 255, 0);
	vd.x = 100;
	vd.y = 100;
	draw_circle(vars, &vd, 10);
}

void	draw_minimap(t_vars *vars)
{
	t_vector	vmin;
	t_vector	vmax;
	t_vector	vd;

	vd.y = 0;
	vmax.x = ((vars->ordr.origin->x / 256) * 30) + 100;
	vmax.y = ((vars->ordr.origin->y / 256) * 30) + 100;
	vmin.y = ((vars->ordr.origin->y / 256) * 30) - 100;
	while (vmin.y < vmax.y)
	{
		vd.x = 0;
		vmin.x = ((vars->ordr.origin->x / 256) * 30) - 100;
		while (vmin.x < vmax.x)
		{
			draw_pixel_map(vars, &vmin, &vd);
			vmin.x++;
			vd.x++;
		}
		vmin.y++;
		vd.y++;
	}
	draw_playerpos(vars);
}
