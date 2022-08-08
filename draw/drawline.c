/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/08/08 00:39:58 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_pixel(t_imgarg *data, int x, int y, int color)
{
	char	*dst;
	int		pos;

	if (x < 500 && x > 0 && y < 500 && y > 0)
	{
		pos = (y * data->line_length + x * (data->bits_per_pixel / 8));
		dst = data->addr + pos;
		*(unsigned int*)dst = color;
	}
}

void draw_line(t_vector *v1, t_vector *v2, t_imgarg *data)
{
	float	dx;
	float	dy;
	float	xf;
	float	yf;
	int		step;
	
	dx = v2->x - v1->x;
	dy = v2->y - v1->y;
	step = sqrt((dx * dx) + (dy * dy));
	dy /= step;
	dx /= step;
	xf = v1->x;
	yf = v1->y;
	while (step)
	{
		draw_pixel(data, xf, yf, create_trgb(0,255,255,255));
		xf += dx;
		yf += dy; 
		step--;
	}
}

void	draw_map()
{

}