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

void    camera(t_vars *vars)
{
    t_vector    v;
    int         x;

    x = 0;
    v = *vars->ordr.minplane;
    v.mag = WINDOW_WIDTH;
    draw_line(vars->ordr.origin, vars->ordr.dir1, vars);
    draw_line(vars->ordr.origin, vars->ordr.maxplane, vars);
    draw_line(vars->ordr.origin, vars->ordr.minplane, vars);
    while (x < WINDOW_WIDTH)
    {
        draw_line(vars->ordr.origin, &v, vars);
        v.angle = (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
        rotation(&v, v.angle); 
        x++;
    }
}