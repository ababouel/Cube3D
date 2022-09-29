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

void debug(t_vector *v, int x, double angle)
{
    if (x)
        printf("origin =>\n");
    else
        printf("dir =>\n");
	printf("vector x => %f\n", v->x);
	printf("vector y => %f\n", v->y);	
	printf("vector angle => %f\n", angle);	
}

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
    (void)scale; 
    draw_line(vars->ordr.origin, vars->ordr.dir1, vars);
    draw_line(vars->ordr.origin, vars->ordr.maxplane, vars);
    draw_line(vars->ordr.origin, vars->ordr.minplane, vars); 
}
void    vect_multi(t_vector *dir,double scale)
{
    dir->x *= scale;
    dir->y *= scale;
}
void    vect_add(t_vector *origin,t_vector *dir, double travel)
{
    t_vector    new_origin;

    new_origin.x = origin->x + travel * dir->x;
    new_origin.y = origin->y + travel * dir->y;
    origin->x = new_origin.x;
    origin->y = new_origin.y;
}