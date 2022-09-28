/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:55:30 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/28 03:38:13 by ababouel         ###   ########.fr       */
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
    norm_vect(vars->ordr.dir1);
    vect_multi(vars->ordr.dir1, scale);
    vect_add(vars->ordr.origin, vars->ordr.dir1);
    draw_line(vars->ordr.origin, vars->ordr.dir1, vars);
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