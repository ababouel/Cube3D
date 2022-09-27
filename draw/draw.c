/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/27 03:11:49 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "events.h"
#include "tools.h"

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
	step = sqrt((vd.x * vd.x) + (vd.y * vd.y));
	vd.y /= step;
	vd.x /= step;
	vf.x = v1->x;
	vf.y = v1->y;
	vf.color = v1->color;	
	while (step)
	{
		draw_pixel(data, &vf);
		vf.x += vd.x;
		vf.y += vd.y; 
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

// void	draw_rect(t_vars *data)
// {
// 	t_vector v;	
// 	v.y = data->rect->y;
// 	v.color = data->rect->color;
// 	while (v.y < data->rect->y + RECT_SIZE)
// 	{
// 		v.x = data->rect->x;
// 		while (v.x < data->rect->x + RECT_SIZE)
// 		{
// 			draw_pixel(data, &v);
// 			v.x++;
// 		}
// 		v.y++;
// 	}
// 	mlx_put_image_to_window( data->mlx, data->win, data->iarg->img, 0,0);
// }