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

// static void	draw_pixels(t_vars *data, t_vector *v, unsigned int color)
// {
// 	char		*dst;
// 	t_imgarg	img;

// 	img = *data->iarg;
// 	if (v->x < WINDOW_WIDTH && v->x >= 0 && v->y < WINDOW_HEIGHT && v->y >= 0)
// 	{
// 		dst = img.addr + ((int) v->y * img.line_len
// 				+ (int)v->x * (img.bpp / 8));
// 		*(unsigned int *) dst = color;
// 	}	
// }

// static void xpm_image(char *xpm, t_vars *vars)
// {
//     vars->txtre.ig = malloc(sizeof(t_imgarg));
//     vars->txtre.ig->img = mlx_xpm_file_to_image(vars->mlx, xpm, &vars->txtre.width,
//             &vars->txtre.height);
//     vars->txtre.ig->addr = mlx_get_data_addr(vars->txtre.ig->img, &vars->txtre.ig->bpp,
//          &vars->txtre.ig->line_len, &vars->txtre.ig->endian);
//     vars->txtre.ig->bpp /= 8;
//     vars->txtre.width = vars->txtre.ig->line_len / vars->txtre.ig->bpp;
//     vars->txtre.height = vars->txtre.ig->line_len / vars->txtre.ig->bpp;
// }

// static  unsigned int generate_color(char * path, int* y, t_vars *vars)
// {
//     // int             offset_x;
//     (void)y;
//     xpm_image(path, vars);
//     if (vars->ray.is_vertical == 1)
//     {
//         // offset_x = (int) vars->ray.inters.current_pos.y % 60;
//         return (*(int *)(unsigned char [4]){199, 209, 209, 0});
//     }
//     else
//     {
//         // offset_x = (int) vars->ray.inters.current_pos.x % (int)RECT_SIZE;
//         return (*(int *)(unsigned char [4]){183, 231, 255, 0}); 
//     }
//     // dst = vars->txtre.ig->addr + ((int) (*y) * vars->txtre.width) 
//             // + ((int) offset_x * vars->txtre.ig->bpp);
// }

void    draw_wall(double dis_ray, t_vars *vars, int x)
{
    t_vector        v;
    int             top_y;
    int             bottom_y;
    double          distance;
    int             wall_height;

    top_y = 0;
    distance = (WINDOW_WIDTH / 2) / tan(M_PI / 6);
    wall_height = (int)((RECT_SIZE / dis_ray) * distance);
    top_y = (int)WINDOW_HEIGHT / 2 - wall_height / 2;
    bottom_y = top_y + wall_height;
    if (top_y < 0)
        top_y = 0;
    if (bottom_y > WINDOW_HEIGHT)
        bottom_y = WINDOW_HEIGHT;
    v.x = x;
    while (top_y <= bottom_y)
    {
        v.y = top_y;
        if (vars->ray.is_vertical == 1)
            v.color = add_color(209, 209, 199, 0);
        else
            v.color = add_color(255,231,183,0);         
        draw_pixel(vars, &v);
        top_y++;
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
        draw_wall(pdis, vars, x);
        vars->ray.dir.angle= (1.0 / (WINDOW_WIDTH)) * (M_PI / 6.0);
        rotation(&vars->ray.dir, vars->ray.dir.angle); 
        x++;
    }
}
