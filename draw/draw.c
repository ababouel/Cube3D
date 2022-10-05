/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/05 16:51:09 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "events.h"
#include "tools.h"
#include "raycast.h"

int	create_trgb(t_color *color)
{
	return (color->al << 24 | color->rd << 16 | color->gr << 8 | color->bl);
}

void	draw_pixel(t_vars *data, t_vector *v)
{
	char		*dst;
	t_imgarg	img;

	img = *data->iarg;
	if (v->x < WINDOW_WIDTH && v->x >= 0 && v->y < WINDOW_HEIGHT && v->y >= 0)
	{
		dst = img.addr + ((int)v->y * img.line_len + 
			(int)v->x * (img.bpp / 8));
		*(unsigned int *)dst = create_trgb(v->color);
	}	
}

void draw_line(t_vector *v1, t_vector *v2, t_vars *data)
{
	int			step;
	t_vector	vd;
	t_vector	vf;

	vd.x = v2->x - v1->x;
	vd.y = v2->y - v1->y;
	step = v2->mag;
	vd.y /= step;
	vd.x /= step;
	vf = *v1;	
	while (step)
	{
		draw_pixel(data, &vf);
		vf.x += v2->x;
		vf.y += v2->y; 
		step--;
	}
	mlx_put_image_to_window( data->mlx, data->win, data->iarg->img, 0,0);
}

void	draw_circle(t_vars *data ,t_vector *v, t_vector *vfix, double rad)
{
	t_vector v1;
	double PI = 3.1416;
	double angle;
	
	(void) vfix;
	angle = 0;
	while(angle < 360)
	{
		v1.x = rad * cos(angle * PI / 180);
		v1.y = rad * sin(angle * PI / 180);
		v->x += v1.x;
		v->y += v1.y; 
		draw_pixel(data, v);
		angle += 0.1;
	}	
}

void	draw_rect(t_vars *data, double x, double y)
{
	t_vector v;
		
	y *= RECT_SIZE;
	x *= RECT_SIZE;
	v.y = y; 
	v.color = data->rect.color;
	while (v.y < y + RECT_SIZE - 1)
	{
		v.x = x;
		while (v.x < x + RECT_SIZE - 1)
		{
			draw_pixel(data, &v);
			v.x++;
		}
		v.y++;
	}
	mlx_put_image_to_window( data->mlx, data->win, data->iarg->img, 0,0);
}

void	add_camera_data(t_vars *vars, t_vector *v)
{
	vars->ordr.origin = addvect(v->x * RECT_SIZE, v->y * RECT_SIZE, v->color, 0);
	rotation(vars->ordr.dir1, v->angle);
	rotation(vars->ordr.minplane, v->angle);
	rotation(vars->ordr.maxplane, v->angle);
}

void	draw_map(t_vars *vars)
{
	t_vector v;

	v.y = 0;
	v.color = add_color(255,0,0,0);
	while (v.y < vars->data->hgt)
	{
		v.x = 0;
		while (v.x < vars->data->wth)
		{
			if (vars->data->map[(int)v.y][(int)v.x] == '1')
			{
				draw_rect(vars, v.x, v.y);
			}
			if (vars->ordr.origin == NULL && vars->data->map[(int)v.y][(int)v.x] == 'N')
			{
				v.angle = -3*M_PI/4;
				add_camera_data(vars,&v);	
			}
			else if (vars->ordr.origin == NULL && vars->data->map[(int)v.y][(int)v.x] == 'S')
			{
				v.angle = M_PI/4;
				add_camera_data(vars,&v);	
			}
			else if (vars->ordr.origin == NULL && vars->data->map[(int)v.y][(int)v.x] == 'E')
			{
				v.angle = -M_PI/4;
				add_camera_data(vars,&v);	
			}
			else if (vars->ordr.origin == NULL && vars->data->map[(int)v.y][(int)v.x] == 'W')
			{
				v.angle = 3*M_PI/4;
				add_camera_data(vars,&v);
			}	
			v.x++;
		}
		v.y++;
	}
}