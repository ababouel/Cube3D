/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:39:13 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/17 06:08:05 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "tools.h"

void    draw_minimap(t_vars *vars)
{
    t_imgarg    *ig;
    t_vector    v;
    
    v.y = 0;
    ig = &vars->minimap.iarg;
	while (v.y < vars->data->hgt)
	{
        v.x = 0;	
		while (v.x < vars->data->wth[0])
		{

            if (vars->data->map[(int)v.y][(int) v.x] == '1')
            {
                v.color = add_color(0, 0, 255);
                draw_rect(vars, 10, v);
            }
            else if (vars->data->map[(int)v.y][(int) v.x] == '0')
            {
                v.color = add_color(255, 255, 255);
                draw_rect(vars, 10, v);
            }
            else if (vars->data->map[(int)v.y][(int) v.x] == 'N')
            {
                v.color = add_color(0,255,0);
                draw_rect(vars, 10, v);
            }
			v.x++;
		}
		v.y++;
	}
}