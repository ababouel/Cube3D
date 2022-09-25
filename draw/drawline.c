/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/25 01:02:02 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int	create_trgb(t_color *color)
{
	return (color->t << 24 | color->r << 16 | color->g << 8 | color->b);
}

void	draw_pixel(t_vars *data, t_vector *v)
{
	char		*dst;

	if (v->x < 600 && v->x > 0 && v->y < 600 && v->y > 0)
	{
		dst = data->img->addr + ((int)v->y * data->img->line_len + (int)v->x * (data->img->bpp / 8));
		*(unsigned int *)dst = create_trgb(data->img->color);
	}	
}

void draw_line(t_vector *v1, t_vector *v2, t_vars *data)
{
	int			step;
	t_vector	vd;
	t_vector	vf;

	vd.x = v2->x - v1->x;
	vd.y = v2->y - v1->y;
	step = sqrt((vd.x * vd.x) + (vd.y * vd.y));
	vd.y /= step;
	vd.x /= step;
	vf.x = v1->x;
	vf.y = v1->y;	
	while (step)
	{
		draw_pixel(data, &vf);
		vf.x += vd.x;
		vf.y += vd.y; 
		step--;
	}
}

void	draw_circle(t_vars *data ,t_vector *v, int rad)
{
	float PI = 3.1416;
	float i;
	float angle;
	t_vector v1;
	
	i = 0;
	while(i < 360)
	{
		angle = i;
		v1.x = rad * cos(angle * PI / 180);
		v1.y = rad * sin(angle * PI / 180);
		v->x += v1.x;
		v->y += v1.y; 
		draw_pixel(data, v);
		i += 0.1;
	}	
}