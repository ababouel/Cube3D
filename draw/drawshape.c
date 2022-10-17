/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawshape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:37:08 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/17 03:03:31 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

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
		draw_pixel(data->iarg, &vf);
		vf.x += v2->x;
		vf.y += v2->y; 
		step--;
	}
}

void    draw_circle(t_vars *data ,t_vector *v, double rad)
{
	t_vector v1;
	double angle;
    
	angle = 0;
	while(angle < 360)
	{
		v1.x = rad * cos(angle * M_PI / 180);
		v1.y = rad * sin(angle * M_PI / 180);
		v->x += v1.x;
		v->y += v1.y; 
		draw_pixel(data->iarg, v);
		angle += 0.1;
	}	
}

void	draw_rect(t_vars *data, double rect,double x, double y)
{
	t_vector v;
		
	y *= rect;
	x *= rect;
	v.y = y; 
	v.color = data->rect.color;
	while (v.y < y + rect - 1)
	{
		v.x = x;
		while (v.x < x + rect - 1)
		{
			draw_pixel(&data->minimap.iarg, &v);
			v.x++;
		}
		v.y++;
	}
}

static void    draw_loop(int y, t_color *color, t_vars *vars)
{
    t_vector    v;
    int         x;

    x = 0;
    v.y = y;
    while (x < WINDOW_WIDTH)
    {
        v.x = x;
        v.color = *color;
        draw_pixel(vars->iarg,&v);
        x++;
	}
}

void	draw_ceil_floor(t_vars *vars)
{
	int y;

	y = 0;
	while (y < WINDOW_HEIGHT/2)
	{
        draw_loop(y, &vars->ceil, vars);	
		y++;
	}
	while (y < WINDOW_HEIGHT)
	{
        draw_loop(y, &vars->floor, vars);
		y++;
	}		
}