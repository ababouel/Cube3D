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

void    draw_ray(t_vars *vars)
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
    printf("mag=> %f\n",dis);
    draw_line(&vars->ray.origin, &vars->ray.dir, vars);
}

void    camera(t_vars *vars)
{
    vars->ray.origin = *vars->ordr.origin;
    vars->ray.dir = *vars->ordr.dir1;
    draw_line(vars->ordr.origin, vars->ordr.dir1, vars);
    draw_line(vars->ordr.origin, vars->ordr.maxplane, vars);
    draw_line(vars->ordr.origin, vars->ordr.minplane, vars);
    draw_ray(vars);
}

    // while (x < WINDOW_WIDTH)
    // {
    //     draw_line(vars->ordr.origin, &v, vars);
    //     v.angle = (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
    //     rotation(&v, v.angle); 
    //     x++;
    // }