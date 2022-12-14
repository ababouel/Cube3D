/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/22 23:34:17 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "events.h"
#include "tools.h"
#include "raycast.h"

static unsigned int	create_trgb(t_color *color)
{
	return (color->rd << 16 | color->gr << 8 | color->bl);
}

static void	add_camera_data(t_vars *vars, t_vector *v, double angle)
{
	v->angle = angle;
	vars->ordr.origin = addvect((v->x * RECT_SIZE) + RECT_SIZE / 2,
			(v->y * RECT_SIZE) + RECT_SIZE / 2, v->color, 0);
	rotation(vars->ordr.dir1, v->angle);
	rotation(vars->ordr.minplane, v->angle);
	rotation(vars->ordr.maxplane, v->angle);
}

static	void	add_pos_player(t_vars *vars, t_vector v)
{
	if (vars->ordr.origin == NULL
		&& vars->data->map[(int)v.y][(int)v.x] == 'S')
		add_camera_data(vars, &v, -3 * M_PI / 2);
	else if (vars->ordr.origin == NULL
		&& vars->data->map[(int)v.y][(int)v.x] == 'N')
		add_camera_data(vars, &v, -M_PI / 2);
	else if (vars->ordr.origin == NULL
		&& vars->data->map[(int)v.y][(int)v.x] == 'E')
		add_camera_data(vars, &v, 0);
	else if (vars->ordr.origin == NULL
		&& vars->data->map[(int)v.y][(int)v.x] == 'W')
		add_camera_data(vars, &v, -M_PI);
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

void	init_pos_player(t_vars *vars)
{
	t_vector	v;

	v.y = 0;
	while (v.y < vars->data->hgt)
	{
		v.x = 0;
		while (v.x < vars->data->wth[(int)v.y])
		{
			add_pos_player(vars, v);
			v.x++;
		}
		v.y++;
	}
}
