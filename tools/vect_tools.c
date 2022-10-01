/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:44:01 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/01 11:02:09 by ababouel         ###   ########.fr       */
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