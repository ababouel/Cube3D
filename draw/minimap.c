/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:39:13 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/22 06:29:12 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "tools.h"

int     check_map(t_vars *vars,t_vector *vmin)
{
    t_data  *data;

    data = vars->data;
    if ( vmin->y/30 >= 0 && vmin->y/30 < data->hgt 
        && vmin->x/30 >= 0 && vmin->x/30 < data->wth[(int)vmin->y/30])
    {
        if (vars->data->map[(int)vmin->y/30][(int) vmin->x/30] == '1')
            return (1);
        else if (vars->data->map[(int)vmin->y/30][(int) vmin->x/30] == '0' 
                || vars->data->map[(int)vmin->y/30][(int) vmin->x/30] == 'N')
            return (2);
    }
    return (0);
}

void    draw_rect_minimap(t_vars *data ,t_vector *v, double rad)
{
	t_vector    v1;
	double      angle;
    
    angle = 0;
    while(angle < 360)
	{
		v1.x = cos(angle * M_PI / 180);
		v1.y = sin(angle * M_PI / 180);
        v1.mag = rad;
        draw_line(v, &v1, data);
		angle += 0.1;
	}	
}


void    draw_minimap(t_vars *vars)
{
    t_vector    vmin;
    t_vector    vmax;
    t_vector    vp;
    t_vector    vd;
    
    vd.y = 0;
    vmax.x = ((vars->ordr.origin->x / 256) * 30) + 100;
    vmax.y = ((vars->ordr.origin->y / 256) * 30) + 100;
    vmin.y = ((vars->ordr.origin->y / 256) * 30) - 100;
	while (vmin.y < vmax.y)
	{
        vd.x = 0;
        vmin.x = ((vars->ordr.origin->x / 256) * 30) - 100;	
		while (vmin.x < vmax.x)
		{
            if (check_map(vars, &vmin) == 1)
            {
                vd.color = add_color(255, 0, 0);
                draw_pixel(vars->iarg, &vd);
            }
            else if (check_map(vars, &vmin) == 2)
            {
                vd.color = add_color(255, 255, 255);
                draw_pixel(vars->iarg, &vd);
            }
            vmin.x++;
            if ((vd.y == 0 || vd.y == 200) && (vd.x < 200))
            {
                vd.color = add_color(0,255,0);
                draw_pixel(vars->iarg, &vd);
                
            }
            else if ((vd.y > 0 && vd.y < 200) && (vd.x == 0 || vd.x == 200))
            {
                vd.color = add_color(0,255,0);
                draw_pixel(vars->iarg, &vd);
                
            }
            vd.x++;
		}
		vmin.y++;
        vd.y++;
	}
    vp.color = add_color(0,255,0);
    vp.x = 100;
    vp.y = 100;
    draw_circle(vars, &vp, 10);
     
}