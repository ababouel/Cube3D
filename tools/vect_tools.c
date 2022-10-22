/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:44:01 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/22 02:07:25 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "tools.h"

int	ft_cord_in_wall(t_vars *vars, double x, double y)
{
    int mapGridX;
    int mapGridY;

    mapGridX = (int)(x / RECT_SIZE);
    mapGridY = (int)(y / RECT_SIZE);
    if (vars->data->map[mapGridY][mapGridX] == '1')
        return (-1);
    return (1);
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

void    vect_multi(t_vector *dir,double scale)
{
    dir->x *= scale;
    dir->y *= scale;
}

void    vect_add(t_vars *vars, double travel)
{
    t_vector    new_origin;

    new_origin.x = vars->ordr.origin->x + travel * vars->ordr.dir1->x;
    new_origin.y = vars->ordr.origin->y + travel * vars->ordr.dir1->y;
    if (ft_cord_in_wall(vars, new_origin.x, new_origin.y) == 1)
    {
        vars->ordr.origin->x = new_origin.x;
        vars->ordr.origin->y = new_origin.y;
    }
}

void    move_dir(t_vars *vars, double travel)
{
    t_vector    new_origin;
  
    new_origin.x = vars->ordr.origin->x + travel *  cos(vars->ordr.origin->angle);
    new_origin.y = vars->ordr.origin->y + travel * sin(vars->ordr.origin->angle);
    if (ft_cord_in_wall(vars, new_origin.x, new_origin.y) == 1)
    {
        vars->ordr.origin->x = new_origin.x;
        vars->ordr.origin->y = new_origin.y;
    }
}