/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/09 20:36:47 by ababouel         ###   ########.fr       */
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

void	draw_pixel(t_imgarg *data, t_vector *v, int color)
{
	char	*dst;
	int		pos;

	if (v->x < 500 && v->x > 0 && v->y < 500 && v->y > 0)
	{
		pos = (v->y * data->line_length + v->x * (data->bits_per_pixel / 8));
		dst = data->addr + pos;
		*(unsigned int*)dst = color;
	}
}

void draw_line(t_vector *v1, t_vector *v2, t_imgarg *data, t_color *color)
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
		draw_pixel(data, &vf, create_trgb(color));
		vf.x += vd.x;
		vf.y += vd.y; 
		step--;
	}
}

void	draw_circle(t_imgarg *data ,t_vector *v, int r, int color)
{
	double PI = 3.1415926535;
	double i;
	double angle;
	t_vector v1;
	
	i = 0;
	while(i < 360)
	{
		angle = i;
		v1.x = r * cos(angle * PI / 180);
		v1.y = r * sin(angle * PI / 180);
		v->x += v1.x;
		v->y += v1.y; 
		draw_pixel(data, v, color);
		i += 0.1;
	}	
}