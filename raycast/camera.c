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

static t_texture  get_texture(t_vars *vars, t_nswe ns)
{
    t_texture text;

    if ( ns == NO)
	    text = vars->wall_txt.n_txt;
    else if (ns == SO)
	    text = vars->wall_txt.s_txt;
    else if (ns == EA)
	    text = vars->wall_txt.e_txt;
    else
	    text = vars->wall_txt.w_txt;
    return (text);
}

static void set_texture(t_vars *vars,t_texture *text, t_nswe ns)
{
    if ( ns == NO)
	    vars->wall_txt.n_txt = *text;
    else if (ns == SO)
	    vars->wall_txt.s_txt = *text;
    else if (ns == EA)
	    vars->wall_txt.e_txt = *text;
    else
	    vars->wall_txt.w_txt = *text;
}

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

void   generate_image(t_vars *vars, char *path, t_nswe ns)
{
	t_texture    text;
    t_imgarg     ig;

    text = get_texture(vars, ns); 
    ig = text.txt_img;
	ig.img = mlx_xpm_file_to_image(vars->mlx, path, &text.width, &text.height);
	ig.addr = mlx_get_data_addr(ig.img, &ig.bpp, &ig.line_len, &ig.endian);
    text.txt_img = ig;
    set_texture(vars, &text, ns);
}

static unsigned int generate_pixels(t_vars *vars, t_nswe ns, t_point pt)
{
    unsigned int pixels;
    t_texture   text;
    
    text = get_texture(vars, ns);
    pixels = *(unsigned int *)text.txt_img.addr + (text.width * pt.py) + pt.px;
    return (pixels);
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
    int             y;

    top_y = 0;
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
        offset.py = (y - top_y) * (RECT_SIZE / wall_height);
        draw_pixels(vars, &v, generate_pixels(vars, WE, offset));
        y++;
    }
}

void    map(t_vars *vars)
{   
    int     x;
    double  dis;

    x = 0;
    draw_line(vars->ordr.origin,vars->ordr.dir1, vars);
    draw_line(vars->ordr.origin,vars->ordr.minplane, vars);
    draw_line(vars->ordr.origin,vars->ordr.maxplane, vars);
    vars->ray.origin = *vars->ordr.origin;
    vars->ray.dir = *vars->ordr.minplane;
    vars->ray.dir.angle = M_PI / 6.0;
    while (x < WINDOW_WIDTH)
    {
        dis = cast_ray(vars);
        draw_line(&vars->ray.origin, &vars->ray.dir, vars);
        vars->ray.dir.angle= (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0); 
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
    }
}

void    camera(t_vars *vars)
{
    // int x;
    // double dis;
    // double  angle;

    // x = 0;
    // dis = 0.0;
    // angle = 0;
    // vars->ray.origin = *vars->ordr.origin;
    // vars->ray.dir = *vars->ordr.minplane;
    // vars->ray.dir.angle = M_PI / 6.0;
    // while (x < WINDOW_WIDTH)
    // {
    //     dis = cast_ray(vars); 
    //     draw_wall(dis, vars, &x, angle);
    //     vars->ray.dir.angle= (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
    //     angle += vars->ray.dir.angle;
    //     rotation(&vars->ray.dir, vars->ray.dir.angle); 
    //     x++;
    // }
    map(vars);
}
