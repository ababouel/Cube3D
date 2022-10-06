/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:47:26 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/06 20:51:09 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DRAW_H
# define DRAW_H

# define WINDOW_WIDTH	1280.0
# define WINDOW_HEIGHT	720.0
# define MLX_ERROR	1
# define RECT_SIZE	32.0

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <assert.h>
# include "parsing.h"

typedef struct s_imgarg
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_imgarg;


typedef struct s_vector
{
	double	x;
	double	y;
	double	angle;
	double	mag;
	t_color	color;
}	t_vector;

typedef struct s_org_dir
{
	t_vector	*origin;
	t_vector	*dir1;
	t_vector	*minplane;
	t_vector	*maxplane;	
}	t_org_dir;

typedef struct  s_rect
{
	double	x;
	double	y;
	t_color color;
}	t_rect;

typedef	struct s_point
{
	int	px;
	int	py;
}	t_point;

typedef struct s_inter
{
	t_vector	current_pos;
	t_point		pos_grid;
	t_point		next_pos;
	t_point		next_pos_grid;
	double		dx;
	double		dy;
	double		final_d;
	int			sign_x;	
	int			sign_y;
	int			is_inters;	
}	t_inters;

typedef struct s_ray
{
	t_vector origin;
	t_vector dir;
}	t_ray;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_imgarg	*iarg;
	t_data		*data;
	t_org_dir	ordr;
	t_rect		rect;
	t_ray		ray;
	t_color		ceil;
	t_color		floor;
}	t_vars;

void	draw_pixel(t_vars *data, t_vector *v);
int		create_trgb(t_color *color);
void	draw_line(t_vector *v1, t_vector *v2, t_vars *data);
void	draw_circle(t_vars *data, t_vector *v, double rad);
void	draw_rect(t_vars *data, double x, double y);
void	draw_map(t_vars *vars);
void	draw_ceil_floor(t_vars *vars);

#endif