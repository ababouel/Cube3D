/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/17 02:58:01 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "events.h"
#include "tools.h"
#include "raycast.h"

int	create_trgb(t_color *color)
{
	return (color->rd << 16 | color->gr << 8 | color->bl);
}

void	draw_pixel(t_imgarg *data, t_vector *v)
{
	char		*dst;
	t_imgarg	*img;

	img = data;
	if (v->x < WINDOW_WIDTH && v->x >= 0 && v->y < WINDOW_HEIGHT && v->y >= 0)
	{
		dst = img->addr + ((int) v->y * img->line_len
				+ (int)v->x * (img->bpp / 8));
		*(unsigned int *) dst = create_trgb(&v->color);
	}	
}

void	add_camera_data(t_vars *vars, t_vector *v, double angle)
{
	v->angle = angle;
	vars->ordr.origin = addvect(v->x * RECT_SIZE,
			v->y * RECT_SIZE, v->color, 0);
	rotation(vars->ordr.dir1, v->angle);
	rotation(vars->ordr.minplane, v->angle);
	rotation(vars->ordr.maxplane, v->angle);
}

void	draw_map(t_vars *vars)
{
	t_vector	v;

	v.y = 0;	
	while (v.y < vars->data->hgt)
	{
		v.x = 0;
		while (v.x < vars->data->wth[(int)v.y])
		{	
			if (vars->ordr.origin == NULL
				&& vars->data->map[(int)v.y][(int)v.x] == 'S')
				add_camera_data(vars, &v, 3 * M_PI / 4 );
			else if (vars->ordr.origin == NULL
				&& vars->data->map[(int)v.y][(int)v.x] == 'N')
				add_camera_data(vars, &v, -3 * M_PI/4);
			else if (vars->ordr.origin == NULL
				&& vars->data->map[(int)v.y][(int)v.x] == 'E')
				add_camera_data(vars, &v, -M_PI / 4);
			else if (vars->ordr.origin == NULL
				&& vars->data->map[(int)v.y][(int)v.x] == 'W')
				add_camera_data(vars, &v, M_PI/4);
			v.x++;
		}
		v.y++;
	}
}
