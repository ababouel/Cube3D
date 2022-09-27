/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:55:30 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/27 04:23:25 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "tools.h"

void    norm_vect(t_vector *vect)
{
    double mag;
    
    mag = sqrt(vect->x * vect->x + vect->y * vect->y);
    if (mag != 0)
    {
        vect->x /= mag;
        vect->y /= mag;
    }
}

void    debug_draw_vect(double scale, t_vars *vars)
{
    rotation(vars->ordr.dir, vars->ordr.angle); 
    norm_vect(vars->ordr.dir);
    vect_multi(vars->ordr.dir, scale);
    vect_add(vars->ordr.dir, vars->ordr.origin);
    draw_line(vars->ordr.origin, vars->ordr.dir, vars);
}
void    vect_multi(t_vector *dir,double scale)
{
    dir->x *= scale;
    dir->y *= scale;
}
void    vect_add(t_vector *dir,t_vector *origin)
{
    dir->x += origin->x;
    dir->y += origin->y; 
}
