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

void    draw_wall(double dis_ray, t_vars *vars, int x)
{
    t_vector        v; 
    int             top_y;
    int             bottom_y;
    double          distance;
    int             wall_height;
    
    distance = (WINDOW_WIDTH / 2) / tan(M_PI / 6);
    wall_height = (RECT_SIZE / dis_ray) * distance;
    top_y = WINDOW_HEIGHT / 2 - wall_height / 2;
    bottom_y = top_y + wall_height;
    if (top_y < 0)
        top_y = 0;
    if (bottom_y > WINDOW_HEIGHT)
        bottom_y = WINDOW_HEIGHT;
    v.x = x; 
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
        dis = cast_ray(vars);
        draw_wall(dis, vars, x);
        vars->ray.dir.angle= (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
    }
} 

