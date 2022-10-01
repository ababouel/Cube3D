/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:47:26 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/01 13:55:36 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DRAW_H
# define DRAW_H

# define WINDOW_WIDTH	600
# define WINDOW_HEIGHT	600
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
	t_color	*color;
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
	t_color *color;
}	t_rect;


typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_imgarg	*iarg;
	t_data		*data;
	t_org_dir	ordr;
	t_rect		rect;
}	t_vars;

void	draw_pixel(t_vars *data, t_vector *v);
int		create_trgb(t_color *color);
void	draw_line(t_vector *v1, t_vector *v2, t_vars *data);
void	draw_circle(t_vars *data,t_vector *v, t_vector *vfix, double rad);
void	draw_rect(t_vars *data, double x, double y);
void	draw_map(t_vars *vars);
#endif