/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 06:01:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/20 05:08:06 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define WINDOW_WIDTH	1980.0
# define WINDOW_HEIGHT	1080.0
# define MLX_ERROR	1
# define RECT_SIZE	256.0
# define SCALE_HEIGHT 1

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>

typedef enum e_NSWE
{
    NO,
    SO,
    WE,
    EA
}   t_nswe;

typedef struct s_txtpath
{
    char    *path;	
    t_nswe  nswe; 
}   t_txtpath;

typedef  struct	s_color
{
	unsigned int    rd;
    unsigned int    gr;
    unsigned int    bl;
}	t_color;

typedef struct s_data
{
    int         *wth;
    int         hgt;
    t_txtpath   *txtpath; 
    char        **map;
}   t_data;

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
	t_color cwall;
	t_color cfloo;
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
	t_vector	dir;
	t_vector	origin;
	t_inters	inters;
	double		top_x;
	int			is_vertical;
}	t_ray;

typedef struct	s_texture
{
	int 		width;
	int 		height;
	t_imgarg	txt_img;
}	t_texture;

typedef struct s_wall_txt
{
	t_texture	n_txt;	
	t_texture	s_txt;	
	t_texture	w_txt;	
	t_texture	e_txt;	
}	t_wall_txt;

typedef	struct s_minimap
{	
	double		width;
	double		height;
	double		rect;
	t_vector	player;	
}	t_minimap;

typedef struct	s_vars 
{
	int			old_x;
	void		*mlx;
	void		*win;
	t_imgarg	*iarg;
	t_minimap	minimap;
	t_data		*data;
	t_org_dir	ordr;
	t_rect		rect;
	t_ray		ray;
	t_color		ceil;
	t_color		floor;
	t_wall_txt	wall_txt;
}	t_vars;

typedef struct s_wall
{
	t_point         offset;
    t_vector        v;
    double          correct_dis;
    int             top_y;
    int             bottom_y;
    double          scale;
    double          wall_height; 
    int             y;
    unsigned int    *color;
}	t_wall;
typedef struct s_pars 
{
    int     i;
    int     j;
    int     fd;
    int     col;
	int		flag;
    int     count;
    char    *line;
    char    **tmp;
}   t_pars;

#endif