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

uint32_t	*generate_pixels(t_vars *vars, char *path)
{
	t_point		t;
	t_imgarg	ig;
	char		*ttc;
	uint32_t	*txtcolor;

	t.py = 0;
	ig = vars->txtre.ig;
	ig.img = mlx_xpm_file_to_image(vars->mlx, path, &vars->txtre.width, &vars->txtre.height);
	ig.addr = mlx_get_data_addr(ig.img, &ig.bpp, &ig.line_len, &ig.endian);
	txtcolor = malloc(sizeof(uint32_t) * (uint32_t)vars->txtre.width * (uint32_t) vars->txtre.height);
	while (t.py <= vars->txtre.height)
	{
		t.px = 0;
		while (t.px <= vars->txtre.width)
		{
			ttc = ig.addr + ((int) t.py * ig.line_len + (int) t.px * (ig.bpp / 8));
			txtcolor[(vars->txtre.width * t.py) + t.px] = *(uint32_t *)ttc;
			t.px++;	
		}
		t.py++;
	}
	return (txtcolor);
}

void    draw_wall(double dis_ray, t_vars *vars, int *x)
{
    t_point         offset;
    t_vector        v;
    int             top_y;
    int             bottom_y;
    double          distance;
    int             wall_height;
    t_imgarg        ig;
    int             y;
    int             distance_from_top;

    top_y = 0;
    ig = vars->txtre.ig;
    distance = (WINDOW_WIDTH / 2) / tan(M_PI / 6);
    wall_height = (int)((RECT_SIZE / dis_ray) * distance);
    top_y = (int)WINDOW_HEIGHT / 2 - wall_height / 2;
    bottom_y = top_y + wall_height;
    if (top_y < 0)
        top_y = 0;
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
        distance_from_top = y + (wall_height/2)-(WINDOW_HEIGHT/2);
        offset.py = distance_from_top * (RECT_SIZE / wall_height);
        draw_pixels(vars, &v, (unsigned int) vars->wall_text[((int)RECT_SIZE * offset.py) + offset.px]);
        y++;
    }
}
void    camera(t_vars *vars)
{
    int x;
    double dis;
    double pdis;

    x = 0;
    dis = 0.0;
    vars->ray.origin = *vars->ordr.origin;
    vars->ray.dir = *vars->ordr.minplane;
    vars->ray.dir.angle = M_PI / 6.0;
    while (x < WINDOW_WIDTH)
    {
        dis = cast_ray(vars);
        pdis = dis * cos(vars->ray.dir.angle - vars->ordr.dir1->angle);
        draw_wall(pdis, vars, &x);
        vars->ray.dir.angle= (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
    }
}
