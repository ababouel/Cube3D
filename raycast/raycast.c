/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:18:19 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/19 05:59:19 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static int intersect_with_x(t_inters   *inters, t_vars *vars)
{
    int gridX;
    int gridY;

    gridX = inters->next_pos.px - 1 + inters->sign_x;
    gridY = inters->pos_grid.py;
    if (gridY < 0 || gridY > vars->data->hgt || gridX < 0 || gridX > vars->data->wth[gridY])
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
    if (gridY < 0 || gridY > vars->data->hgt || gridX < 0 || gridX > vars->data->wth[gridY])
        return (0);
    if(vars->data->map[gridY][gridX] == '1')
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
    inters->dx = ((double)inters->next_pos_grid.px - inters->current_pos.x) / vars->ray.dir.x;
    inters->dy = ((double)inters->next_pos_grid.py - inters->current_pos.y) / vars->ray.dir.y;
}

// double  ft_min(double v1, double v2)
// {
//     if (v1 < v2)
//         return (v1);
//     return (v2);
// }

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
    inters->final_d += 0.0001;
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

// static double cal_dis(double ox, double oy, double px, double py)
// {
//      return (sqrt((ox - px) * (ox - px) + (oy - py) * (oy - py)));
// }
// static  double  intersect_vertical(t_vars *vars, double rect_size)
// {
//     t_inters    *inters;
//     t_point     grid;
//     t_vector    tmp;
//     double      xf;
//     double      yf;
//     double      dis; 
//     xf = 0;
//     yf = 0;
//     dis = 0;
//     inters = &vars->ray.inters;
//     if (vars->ray.dir.x < 0)
//     {
//         inters->current_pos.x  = round(vars->ray.origin.x / rect_size) * (rect_size) - 1;
//         xf = -rect_size;
//     }
//     else
//     {
//         inters->current_pos.x  = round(vars->ray.origin.x / rect_size) * (rect_size) + rect_size;
//         xf = rect_size;
//     }
//     inters->current_pos.y = vars->ray.origin.y +  (vars->ray.origin.x - inters->current_pos.x) * tan(vars->ray.dir.angle);
//     grid.px = inters->current_pos.x / rect_size;
//     grid.py = inters->current_pos.y / rect_size;
//     tmp = inters->current_pos;
//     while (inters->current_pos.x > 0 && inters->current_pos.x < WINDOW_WIDTH && inters->current_pos.y > 0 && inters->current_pos.y < WINDOW_HEIGHT)
//     {
//         if ((grid.py > 0 && grid.py < vars->data->hgt 
//             && grid.px > 0 && grid.px < vars->data->wth[grid.py]) 
//             && vars->data->map[grid.py][grid.px] == '1')
//             break;
//         yf = rect_size * tan(vars->ray.dir.angle);
//         inters->current_pos.x += xf;
//         inters->current_pos.y += yf;
//         grid.px = inters->current_pos.x / rect_size;
//         grid.py = inters->current_pos.y / rect_size;
//     } 
//     dis = cal_dis(vars->ray.origin.x,vars->ray.origin.y, inters->current_pos.x,inters->current_pos.y);
//     return (dis); 
// }

// static  double  intersect_horizontal(t_vars *vars, double rect_size)
// {
//     t_inters    *inters;
//     t_point     grid;
//     double      xf;
//     double      yf;
//     double      dis;
    
    
//     xf = 0;
//     yf = 0;
//     dis = 0;
//     inters = &vars->ray.inters;
//     if (vars->ray.dir.y < 0)
//     {
//         inters->current_pos.y  = floor(vars->ray.origin.y / rect_size) * (rect_size) - 1;
//         yf = -rect_size;
//     }
//     else
//     {
//         inters->current_pos.y  = floor(vars->ray.origin.y / rect_size) * (rect_size) + rect_size;
//         yf = rect_size;
//     }
//     inters->current_pos.x = vars->ray.origin.x +  (vars->ray.origin.y - inters->current_pos.y)/tan(vars->ray.dir.angle);
//     grid.px = inters->current_pos.x / rect_size;
//     grid.py = inters->current_pos.y / rect_size;
//     while (inters->current_pos.x > 0 && inters->current_pos.x < WINDOW_WIDTH && inters->current_pos.y > 0 && inters->current_pos.y < WINDOW_HEIGHT)
//     {
//         if ((grid.py > 0 && grid.py < vars->data->hgt 
//             && grid.px > 0 && grid.px < vars->data->wth[grid.py]) 
//             && vars->data->map[grid.py][grid.px] == '1')
//             break;
//         xf = rect_size / tan(vars->ray.dir.angle);
//         inters->current_pos.x += xf;
//         inters->current_pos.y += yf;
//         grid.px = inters->current_pos.x / rect_size;
//         grid.py = inters->current_pos.y / rect_size;
//     }   
//     dis = cal_dis(vars->ray.origin.x,vars->ray.origin.y, inters->current_pos.x,inters->current_pos.y);
//     return (dis);
// }

// double  cast_ray(t_vars *vars, double rect_size)
// {
//     double dis;
//     double hdis;
//     double vdis;

//     dis = 0; 
//     hdis = intersect_horizontal(vars, rect_size);
//     vdis = intersect_vertical(vars, rect_size);
//     if (hdis < vdis)
//         dis = hdis;
//     else
//         dis = vdis;
//     vars->ray.dir.mag = dis;   
//     return (dis);
// }