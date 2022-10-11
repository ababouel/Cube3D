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

static void	draw_pixels(t_vars *data, t_vector *v, unsigned int color)
{
	char		*dst;
	t_imgarg	img;

	img = *data->iarg;
	if (v->x < WINDOW_WIDTH && v->x >= 0 && v->y < WINDOW_HEIGHT && v->y >= 0)
	{
		dst = img.addr + ((int) v->y * img.line_len
				+ (int)v->x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}	
}

void   generate_image(t_vars *vars, char *path, char dir)
{
	t_imgarg    ig;

    if (dir == 'N')
	    ig = vars->wall_txt.n_txt;
    else if (dir == 'S')
	    ig = vars->wall_txt.s_txt;
    else if (dir == 'E')
	    ig = vars->wall_txt.e_txt;
    else
	    ig = vars->wall_txt.w_txt; 
	ig.img = mlx_xpm_file_to_image(vars->mlx, path, &vars->txtre.width, &vars->txtre.height);
	ig.addr = mlx_get_data_addr(ig.img, &ig.bpp, &ig.line_len, &ig.endian);
}

double  get_angle(t_vector *vo, t_vector *vd)
{
    double input;
    double angle;

    input = (vo->x * vd->x + vo->y * vd->y)
            / ((sqrt(vo->x * vo->x + vo->y * vo->y)
            * sqrt(vd->x * vd->x + vd->y * vd->y)));
    angle = acos(input);
    return (angle);
}

void    draw_wall(double dis_ray, t_vars *vars, int *x, double angle)
{
    t_point         offset;
    t_vector        v;
    double          correct_dis;
    int             top_y;
    int             bottom_y;
    double          distance;
    double             wall_height;
    t_imgarg        ig;
    int             y;

    top_y = 0;
    ig = vars->txtre.ig;
    correct_dis = dis_ray * cos(M_PI/6 - angle);
    distance = (WINDOW_WIDTH / 2) / tan(M_PI / 6);
    wall_height = (RECT_SIZE / correct_dis) * distance;
    top_y = (int)WINDOW_HEIGHT / 2 - (int)wall_height / 2;
    if (top_y < 0)
        top_y = 0;
    bottom_y = top_y + (int)wall_height;
    if (bottom_y > WINDOW_HEIGHT)
        bottom_y = WINDOW_HEIGHT;
    if (vars->ray.is_vertical)
        offset.px = (int)vars->ray.dir.y % (int)RECT_SIZE;
    else
        offset.px = (int)vars->ray.dir.x % (int)RECT_SIZE;
    v.x = *x;
    y = top_y; 
    while (y <= bottom_y)
    {
        v.y = y;
        offset.py = top_y - y;
        draw_pixels(vars, &v, (unsigned int) vars->wall_text[((int)RECT_SIZE * offset.py) + offset.px]);
        y++;
    }
}
void    camera(t_vars *vars)
{
    int x;
    double dis;
    double  angle;

    x = 0;
    dis = 0.0;
    angle = 0;
    vars->ray.origin = *vars->ordr.origin;
    vars->ray.dir = *vars->ordr.minplane;
    vars->ray.dir.angle = M_PI / 6.0;
    while (x < WINDOW_WIDTH)
    {
        dis = cast_ray(vars); 
        draw_wall(dis, vars, &x, angle);
        vars->ray.dir.angle= (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
        angle += vars->ray.dir.angle;
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
    }
}
