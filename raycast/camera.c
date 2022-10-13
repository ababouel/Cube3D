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

void    draw_pixels(t_vars *data, t_vector *v, unsigned int color)
{
    t_imgarg        *img;
    unsigned int    *dst;

<<<<<<< HEAD
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
    pixels = *(unsigned int *)(text.txt_img.addr + (text.width * pt.py) + pt.px);
    return (pixels);
=======
    img = data->iarg;
    dst = (unsigned int *) data->iarg->addr;
    dst[((int)WINDOW_WIDTH * (int)v->y) + (int)v->x] = color;
>>>>>>> 16b83a706dfcbff36fafb51a063bcc123e7f9e58
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
    unsigned int    *color;

    top_y = 0;
    y = 0;
    offset.px = 0;
    offset.py = 0;
    correct_dis = dis_ray * cos(M_PI/6 - angle);
    distance = (WINDOW_WIDTH / 2) / tan(M_PI / 6);
<<<<<<< HEAD
    wall_height = (60 / correct_dis) * distance;
=======
    wall_height = (60 / correct_dis) * distance; 
>>>>>>> 16b83a706dfcbff36fafb51a063bcc123e7f9e58
    top_y = (int)WINDOW_HEIGHT / 2 - (int)wall_height / 2;
    if (top_y < 0)
        top_y = 0;
    bottom_y = top_y + (int)wall_height;
    if (bottom_y > WINDOW_HEIGHT)
        bottom_y = WINDOW_HEIGHT;
    if (vars->ray.is_vertical)
<<<<<<< HEAD
        offset.px = (int)vars->ray.dir.y % 60;
    else
        offset.px = (int)vars->ray.dir.x % 60;
=======
    {
        offset.px = *x % vars->wall_txt.w_txt.width;
        color = (unsigned int *) vars->wall_txt.w_txt.txt_img.addr;
    }
    else
    {
        offset.px = *x % vars->wall_txt.n_txt.width;
        color = (unsigned int *) vars->wall_txt.n_txt.txt_img.addr;
    }
>>>>>>> 16b83a706dfcbff36fafb51a063bcc123e7f9e58
    v.x = *x;
    y = top_y; 
    while (y <= bottom_y)
    {
        // printf("offset =>\nx->%d\ny->%d\n", offset.px, offset.py);
        v.y = y;
        // if (vars->ray.is_vertical)
        // {
            offset.py = (double)(((y - top_y) / wall_height) * 60);
            draw_pixels(vars, &v, color[(int)(60 * offset.py) + offset.px]);
        // }
        // else
        // {
        //     offset.py = (double)(((y - top_y) / wall_height) * 60);
        //     draw_pixels(vars, &v, color[(int)(128 * offset.py) + offset.px]);
        // }
        y++;
    }
}

void    map(t_vars *vars)
{   
    t_point v;

    v.py = 0;	
	// while (v.py < vars->data->hgt)
	// {
	// 	v.px = 0;
	// 	while (v.px < vars->data->wth[v.py])
    //     {
    //         if (vars->data->map[v.py][v.px] == '1')
    //             draw_rect(vars, v.px, v.py);
    //         v.px++;
    //     }
    //     v.py++;
    // }
    int x = 0;
    draw_line(vars->ordr.origin,vars->ordr.dir1, vars);
    draw_line(vars->ordr.origin,vars->ordr.minplane, vars);
    draw_line(vars->ordr.origin,vars->ordr.maxplane, vars);
    vars->ray.origin = *vars->ordr.origin;
    vars->ray.dir = *vars->ordr.minplane;
    vars->ray.dir.angle = M_PI / 6.0;
    while (x < WINDOW_WIDTH)
    {
        cast_ray(vars, RECT_SIZE); 
        draw_line(&vars->ray.origin, &vars->ray.dir, vars);
        vars->ray.dir.angle= (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
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
<<<<<<< HEAD
        dis = cast_ray(vars); 
=======
        dis = cast_ray(vars, RECT_SIZE); 
>>>>>>> 16b83a706dfcbff36fafb51a063bcc123e7f9e58
        draw_wall(dis, vars, &x, angle);
        vars->ray.dir.angle= (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
        angle += vars->ray.dir.angle;
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
    }
<<<<<<< HEAD
   map(vars);
=======
    // map(vars);
>>>>>>> 16b83a706dfcbff36fafb51a063bcc123e7f9e58
}
