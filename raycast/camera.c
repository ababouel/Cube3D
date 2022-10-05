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
#include <math.h>
#include <strings.h>

int intersect_with_x(t_inters   *inters, t_vars *vars)
{
    int gridX;
    int gridY;

    gridX = inters->next_pos_x - 1 + inters->sign_x;
    gridY = inters->pos_grid_y;
    if (gridX < 0 || gridX >= 10 || gridY < 0 || gridY >= 10)
        return (0);
    if(vars->data->map[gridY][gridX] == '1')
        return (1);
    return (0);
}

int intersect_with_y(t_inters   *inters, t_vars *vars)
{
    int gridX;
    int gridY;

    gridX = inters->pos_grid_x;
    gridY = inters->next_pos_y - 1 + inters->sign_y;
    if (gridX < 0 || gridX >= 10 || gridY < 0 || gridY >= 10)
        return (0);
    if(vars->data->map[gridY][gridX] == '1')
        return (1);
    return (0);
}

double  draw_ray(t_vars *vars)
{
    int         x;
    int         is_inters;
    t_inters    inters;
    double      dis;
    

    x = 0;
    dis = 0;
    is_inters = 0;
    bzero(&inters,sizeof(t_inters));
    inters.current_pos = vars->ray.origin;
    inters.sign_x = 1;
    inters.sign_y = 1;
    if(vars->ray.dir.x < 0)
        inters.sign_x = 0;
    if(vars->ray.dir.y < 0)
        inters.sign_y = 0;
    while(x < 200 && !is_inters)
    {
        inters.pos_grid_x = inters.current_pos.x / RECT_SIZE; 
        inters.pos_grid_y = inters.current_pos.y / RECT_SIZE;
        inters.next_pos_x = inters.pos_grid_x + inters.sign_x; 
        inters.next_pos_y = inters.pos_grid_y + inters.sign_y;
        inters.next_pos_grid_x = inters.next_pos_x * RECT_SIZE;
        inters.next_pos_grid_y = inters.next_pos_y * RECT_SIZE;
        inters.dx = (inters.next_pos_grid_x - inters.current_pos.x) / vars->ray.dir.x;
        inters.dy = (inters.next_pos_grid_y - inters.current_pos.y) / vars->ray.dir.y;
        if (inters.dx < inters.dy)
        {
            is_inters = intersect_with_x(&inters,vars);
            inters.final_d = inters.dx;
        }
        else
        {
            is_inters = intersect_with_y(&inters,vars);
            inters.final_d = inters.dy;

        }
        inters.final_d += 0.00001; 
        inters.current_pos.x += inters.final_d * vars->ray.dir.x;
        inters.current_pos.y += inters.final_d * vars->ray.dir.y;
        dis += inters.final_d; 
        x++;
    } 
    vars->ray.dir.mag = dis;
    return (dis);
}

void    draw_wall(double dis_ray, t_vars *vars, int x)
{
    double          distance;
    int             top_y;
    int             bottom_y;
    int             wall_height;
    t_vector        v; 

    distance = (WINDOW_WIDTH / 2) / tan(M_PI / 6);
    wall_height = (RECT_SIZE / dis_ray) * distance;
    top_y = WINDOW_HEIGHT / 2 - wall_height / 2;
    bottom_y = top_y + wall_height;
    if (top_y < 0)
        top_y = 0;
    if (bottom_y > WINDOW_HEIGHT)
        bottom_y = WINDOW_HEIGHT;
    v.x = x;
    if (dis_ray < 1)
        dis_ray = 0;
    if (dis_ray > 255)
        dis_ray = 255;
    while (top_y <= bottom_y)
    {
        v.y = top_y;
        v.color = add_color(0, 255, 255, 0);
        draw_pixel(vars, &v);
        top_y++;
    }
}
void    camera(t_vars *vars)
{
    int x;
    double dis;

    x = 0;
    dis = 0.0;
    vars->ray.origin = *vars->ordr.origin;
    vars->ray.dir = *vars->ordr.minplane;
    while (x < WINDOW_WIDTH)
    {
        dis = draw_ray(vars);
        draw_wall(dis, vars, x);
        vars->ray.dir.angle= (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
    }
} 

