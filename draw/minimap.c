/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:39:13 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/22 03:15:09 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "tools.h"

void    draw_minimap(t_vars *vars)
{
    t_vector    v;
    t_vector    vp;
    
    v.y = 0;
	while (v.y < vars->data->hgt * 10)
	{
        v.x = 0;	
		while (v.x < vars->data->wth[(int)v.y / 10] * 10)
		{
            if (vars->data->map[(int)v.y/10][(int) v.x/10] == '1')
            {
                v.color = add_color(255, 0, 0);
                draw_pixel(vars->iarg, &v);
            }
            else if (vars->data->map[(int)v.y/10][(int) v.x/10] == '0' 
                || vars->data->map[(int)v.y/10][(int) v.x/10] == 'N')
            {
                v.color = add_color(255, 255, 255);
                draw_pixel(vars->iarg, &v);
            }
            v.x++;
		}
		v.y++;
	}
    vp.color = add_color(0,255,0);
    vp.x = (vars->ordr.origin->x / 256) * 10;
    vp.y = (vars->ordr.origin->y / 256) * 10;
    draw_circle(vars, &vp, 5); 
}