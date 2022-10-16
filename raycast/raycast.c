/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:18:19 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/16 05:54:18 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static int intersect_with_x(t_inters   *inters, t_vars *vars)
{
    int gridX;
    int gridY;

    gridX = inters->next_pos.px - 1 + inters->sign_x;
    gridY = inters->pos_grid.py;
    if (gridX < 0 || gridX > *vars->data->wth || gridY < 0 || gridY > vars->data->hgt)
        return (0);
    if(vars->data->map[gridY][gridX] == '1')
    {
        vars->ray.is_vertical = 1;
        return (1);
    }
    return (0);
}

static int intersect_with_y(t_inters   *inters, t_vars *vars)
{
    int gridX;
    int gridY;

    gridX = inters->pos_grid.px;
    gridY = inters->next_pos.py - 1 + inters->sign_y;
    if (gridX < 0 || gridX > *vars->data->wth || gridY < 0 || gridY > vars->data->hgt)
        return (0);
    if(vars->data->map && vars->data->map[gridY][gridX] == '1')
    {
        vars->ray.is_vertical = 0;
        return (1);
    }
    return (0);
}

static void op_params(t_inters *inters, t_vars *vars, double rect_size)
{
    inters->pos_grid.px = inters->current_pos.x / rect_size;
    inters->pos_grid.py = inters->current_pos.y / rect_size;
    inters->next_pos.px = inters->pos_grid.px + inters->sign_x;
    inters->next_pos.py = inters->pos_grid.py + inters->sign_y;
    inters->next_pos_grid.px = inters->next_pos.px * rect_size;
    inters->next_pos_grid.py = inters->next_pos.py * rect_size;
    inters->dx = (inters->next_pos_grid.px - inters->current_pos.x) / vars->ray.dir.x;
    inters->dy = (inters->next_pos_grid.py - inters->current_pos.y) / vars->ray.dir.y;
}

static double   op_distance(t_inters *inters, t_vars *vars)
{
    if (inters->dx < inters->dy)
    {
        inters->is_inters = intersect_with_x(inters,vars);
        inters->final_d = inters->dx;
    }
    else
    {
        inters->is_inters = intersect_with_y(inters,vars);
        inters->final_d = inters->dy;
    }
    inters->final_d += 0.00001;
    inters->current_pos.x += inters->final_d * vars->ray.dir.x;
    inters->current_pos.y += inters->final_d * vars->ray.dir.y;
    return (inters->final_d);
} 

double  cast_ray(t_vars *vars, double rect_size)
{
    int         x;
    double      dis;
    
    x = 0;
    dis = 0;
    vars->ray.inters.is_inters = 0;
    vars->ray.inters.current_pos = vars->ray.origin;
    vars->ray.inters.sign_x = 1;
    vars->ray.inters.sign_y = 1;
    if(vars->ray.dir.x < 0)
        vars->ray.inters.sign_x = 0;
    if(vars->ray.dir.y < 0)
        vars->ray.inters.sign_y = 0;
    while(x < 100 && !vars->ray.inters.is_inters)
    {
        op_params(&vars->ray.inters, vars, rect_size); 
        dis += op_distance(&vars->ray.inters, vars); 
        x++;
    } 
    vars->ray.dir.mag = dis;
    return (dis);
}
