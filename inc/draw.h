/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:19:03 by ababouel          #+#    #+#             */
/*   Updated: 2022/08/06 15:19:08 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

#include "parsing.h"

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
}	t_vars;

typedef struct s_vector
{
	double	x;
	double	y;
	t_color	*color;
}	t_vector;

void	draw_pixel(t_vars *data, t_vector *v);
int		create_trgb(t_color *color);
void	draw_line(t_vector *v1, t_vector *v2, t_vars *data);
void	draw_circle(t_vars *data,t_vector *v, t_vector *vfix, double rad);
void	draw_rectangle(t_imgarg *data, t_vector *v, t_vector *v1);

#endif