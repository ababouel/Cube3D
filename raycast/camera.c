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

void    draw_pixels(t_vars *data, t_vector *v, unsigned int color)
{
    t_imgarg        *img;
    unsigned int    *dst;

    img = data->iarg;
    dst = (unsigned int *) img->addr;
    dst[((int)WINDOW_WIDTH * (int)v->y) + (int)v->x] = color;
}

void    draw_wall(double dis_ray, t_vars *vars, int *x, double angle)
{
    t_point         offset;
    t_vector        v;
    double          correct_dis;
    int             top_y;
    int             bottom_y;
    double          scale;
    double          wall_height; 
    int             y;
    unsigned int    *color;

    y = 0;
    top_y = 0;
    v.x= *x;
    offset.px = 0;
    offset.py = 0;
    correct_dis = dis_ray * cos(M_PI / 6 - angle);
    scale = (RECT_SIZE / 2) / tan(M_PI / 6);
    wall_height = (WINDOW_HEIGHT / correct_dis) * scale; 
    top_y = (int)WINDOW_HEIGHT / 2 - (int)wall_height / 2; 
    bottom_y = top_y + (int)wall_height;

    if (vars->ray.is_vertical)
        color = (unsigned int *) vars->wall_txt.w_txt.txt_img.addr;
    else
        color = (unsigned int *) vars->wall_txt.s_txt.txt_img.addr;

    y = top_y;
    if (top_y < 0)
        y = 0;
    while ( y >= 0 && y <= bottom_y && y <= WINDOW_HEIGHT)
    {
        v.y = y;
        if (vars->ray.is_vertical)
        {
            offset.px = (int) vars->ray.inters.current_pos.y % vars->wall_txt.w_txt.width;
            offset.py = (double)(((y - top_y) / wall_height) * vars->wall_txt.w_txt.height); 
            draw_pixels(vars, &v, color[(int)(vars->wall_txt.w_txt.width * offset.py) + offset.px]); 
        }
        else
        {
            offset.px = (int) vars->ray.inters.current_pos.x % vars->wall_txt.s_txt.width;
            offset.py = (double)(((y - top_y) / wall_height) * vars->wall_txt.s_txt.height);
            draw_pixels(vars, &v, color[(int)(vars->wall_txt.s_txt.width * offset.py) + offset.px]); 
        }
        y++;
    } 
}
void    map(t_vars *vars)
{   
    t_point v;

    v.py = 0;	
    int x = 0;
    draw_circle(vars, vars->ordr.origin, 10);
    vars->ray.origin = *vars->ordr.origin;
    vars->ray.dir = *vars->ordr.minplane;
    vars->ray.dir.angle = M_PI / 6.0;
    while (x < WINDOW_WIDTH)
    {
        cast_ray(vars, RECT_SIZE);
        printf("dis => %f\n",vars->ray.dir.mag); 
        draw_line(&vars->ray.origin, &vars->ray.dir, vars);
        vars->ray.dir.angle = M_PI / (3.0 * WINDOW_WIDTH);
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
    } 
}

void    camera(t_vars *vars)
{
    int x;
    double dis;
    double  angle;

    x = 0;
    dis = 0.0;
    angle = 0;
    vars->ray.origin = *vars->ordr.origin;
    vars->ray.dir = *vars->ordr.minplane;
    vars->ray.dir.angle = M_PI / 6.0;
    while (x < WINDOW_WIDTH)
    {
        dis = cast_ray(vars, RECT_SIZE); 
        draw_wall(dis, vars, &x, angle);
        vars->ray.dir.angle = (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
        angle += vars->ray.dir.angle;
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
    }  
    // map(vars);
}
