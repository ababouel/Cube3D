/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:55:30 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/21 05:55:26 by fech-cha         ###   ########.fr       */
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
    t_wall  wall;

    wall.y = 0;
    wall.top_y = 0;
    wall.v.x= *x;
    wall.offset.px = 0;
    wall.offset.py = 0;
    wall.correct_dis = dis_ray * cos(M_PI / 6 - angle);
    wall.scale = (RECT_SIZE / 2) / tan(M_PI / 6);
    wall.wall_height = (WINDOW_HEIGHT / wall.correct_dis) * wall.scale; 
    wall.top_y = (int)WINDOW_HEIGHT / 2 - (int)wall.wall_height / 2; 
    wall.bottom_y = wall.top_y + (int)wall.wall_height;
    if (!vars->ray.is_vertical)
    {
        if ( vars->ray.dir.y < 0)
            wall.color = (unsigned int *) vars->wall_txt.n_txt.txt_img.addr;
        else if ( vars->ray.dir.y > 0)
            wall.color = (unsigned int *) vars->wall_txt.s_txt.txt_img.addr;
    }
    else
    {
        if (vars->ray.dir.x  > 0)   
            wall.color = (unsigned int *) vars->wall_txt.e_txt.txt_img.addr;
        else if (vars->ray.dir.x < 0)
            wall.color = (unsigned int *) vars->wall_txt.w_txt.txt_img.addr;
    }
    wall.y = wall.top_y;
    if (wall.top_y < 0)
        wall.y = 0;
    while ( wall.y >= 0 && wall.y <= wall.bottom_y && wall.y <= WINDOW_HEIGHT)
    {
        wall.v.y = wall.y;
        if (!vars->ray.is_vertical)
        {
            if (vars->ray.dir.y < 0)
            {
                wall.offset.px = (int) vars->ray.inters.current_pos.x % vars->wall_txt.n_txt.width;
                wall.offset.py = (double)(((wall.y - wall.top_y) / wall.wall_height) * vars->wall_txt.n_txt.height);
                draw_pixels(vars, &wall.v, wall.color[(int)(vars->wall_txt.n_txt.width * wall.offset.py) + wall.offset.px]);
            } 
            else if (vars->ray.dir.y > 0)
            {
                wall.offset.px = (int) vars->ray.inters.current_pos.x % vars->wall_txt.s_txt.width;
                wall.offset.py = (double)(((wall.y - wall.top_y) / wall.wall_height) * vars->wall_txt.s_txt.height);
                draw_pixels(vars, &wall.v, wall.color[(int)(vars->wall_txt.s_txt.width * wall.offset.py) + wall.offset.px]);
            }
        }
        else
        {
            if (vars->ray.dir.x > 0)
            {
                wall.offset.px = (int) vars->ray.inters.current_pos.y % vars->wall_txt.e_txt.width;
                wall.offset.py = (double)(((wall.y - wall.top_y) / wall.wall_height) * vars->wall_txt.e_txt.height);
                draw_pixels(vars, &wall.v, wall.color[(int)(vars->wall_txt.e_txt.width * wall.offset.py) + wall.offset.px]);
            }
            else if(vars->ray.dir.x < 0)
            {
                wall.offset.px = (int) vars->ray.inters.current_pos.y % vars->wall_txt.w_txt.width;
                wall.offset.py = (double)(((wall.y - wall.top_y) / wall.wall_height) * vars->wall_txt.w_txt.height);
                draw_pixels(vars, &wall.v, wall.color[(int)(vars->wall_txt.w_txt.width * wall.offset.py) + wall.offset.px]);
            }   
        }
        wall.y++;
    } 
}

void    map(t_vars *vars)
{   
    t_point v;

    v.py = 0;	
    int x = 0;
    draw_circle(vars, vars->ordr.origin, 2);
    vars->ray.origin = *vars->ordr.origin;
    vars->ray.dir = *vars->ordr.minplane;
    vars->ray.dir.angle = M_PI / 6.0;
    while (x < WINDOW_WIDTH)
    {
        cast_ray(vars, RECT_SIZE);
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
    while (x < WINDOW_WIDTH)
    {
        dis = cast_ray(vars, RECT_SIZE); 
        draw_wall(dis, vars, &x, angle);
        vars->ray.dir.angle = (1.0 / (WINDOW_WIDTH/2)) * (M_PI / 6.0);
        angle += vars->ray.dir.angle;
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
    }  
    // map(vars);
}
