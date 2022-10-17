/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:39:13 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/17 03:14:37 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void    draw_minimap(t_vars *vars)
{
    t_imgarg    *ig;
    t_vector    v;
    
    v.y = 0;	
    ig = &vars->minimap.iarg;
	while (v.y < vars->data->hgt)
	{
		v.x = 0;
		while (v.x < vars->data->wth[(int)v.y])
		{	
            if (vars->data->map[(int)v.y][(int) v.x] == 1)
                draw_rect(vars, 10, v.x, v.y);
            if (vars->data->map[(int)v.y][(int) v.x] == 0)
                draw_rect(vars, 10, v.x, v.y);
			v.x++;
		}
		v.y++;
	}
}