/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 06:01:46 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/27 20:11:45 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

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
    char    **path;
    t_nswe  nswe; 
}   t_txtpath;

typedef struct s_color
{
    int     rd;
    int     gr;
    int     bl;
    int     al;
    char    type;
}   t_color;

typedef struct s_data
{
    int         wth;
    int         hgt;
    t_color     *color;
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

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_imgarg	*iarg;
	t_data		*data;
}	t_vars;



#endif