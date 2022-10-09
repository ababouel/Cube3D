/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bin: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:55:30 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/28 19:48:46 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "tools.h"

static void	draw_pixels(t_vars *data, t_vector *v, unsigned int color)
{
	char		*dst;
	t_imgarg	img;

	img = *data->iarg;
	if (v->x < WINDOW_WIDTH && v->x >= 0 && v->y < WINDOW_HEIGHT && v->y >= 0)
	{
		dst = img.addr + ((int) v->y * img.line_len
				+ (int)v->x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}	
}

void    draw_wall(double dis_ray, t_vars *vars, int *x, int *tx)
{
    t_vector        v;
    int             top_y;
    int             txt_y;
    int             bottom_y;
    double          distance;
    int             wall_height;
    char            *ttc;
    t_imgarg        ig;

    top_y = 0;
    txt_y = 0;
    if (*tx > 60)
        *tx = 0;
    ig = vars->txtre.ig;
    distance = (WINDOW_WIDTH / 2) / tan(M_PI / 6);
    wall_height = (int)((RECT_SIZE / dis_ray) * distance);
    top_y = (int)WINDOW_HEIGHT / 2 - wall_height / 2;
    bottom_y = top_y + wall_height;
    if (top_y < 0)
        top_y = 0;
    if (bottom_y > WINDOW_HEIGHT)
        bottom_y = WINDOW_HEIGHT;
    v.x = *x;
    while (top_y <= bottom_y)
    {
        v.y = top_y;
        if (txt_y > 60)
            txt_y = 0;
        ttc = ig.addr + ((int) txt_y * ig.line_len + (int) *tx * (ig.bpp / 8));
        draw_pixels(vars, &v, *(unsigned int *) ttc);
        top_y++;
        txt_y++;
    }
}
void    camera(t_vars *vars)
{
    int x;
    int tx;
    double dis;
    double pdis;

    x = 0;
    tx = 0;
    dis = 0.0;
    vars->ray.origin = *vars->ordr.origin;
    vars->ray.dir = *vars->ordr.minplane;
    vars->ray.dir.angle = M_PI / 6.0;
    while (x < WINDOW_WIDTH)
    {
        dis = cast_ray(vars);
        pdis = dis * cos(vars->ray.dir.angle - vars->ordr.dir1->angle);
        draw_wall(pdis, vars, &x, &tx);
        vars->ray.dir.angle= (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
        tx++;
    }
}
