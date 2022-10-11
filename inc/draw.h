/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:47:26 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/10 05:50:24 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DRAW_H
# define DRAW_H

# define WINDOW_WIDTH	1280.0
# define WINDOW_HEIGHT	800.0
# define MLX_ERROR	1
# define RECT_SIZE	60.0

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <assert.h>
# include "parsing.h"

#include "data.h"

uint32_t	*generate_pixels(t_vars *vars, char *path);
void	draw_pixel(t_vars *data, t_vector *v);
int		create_trgb(t_color *color);
void	draw_line(t_vector *v1, t_vector *v2, t_vars *data);
void	draw_circle(t_vars *data, t_vector *v, double rad);
void	draw_rect(t_vars *data, double x, double y);
void	draw_map(t_vars *vars);
void	draw_ceil_floor(t_vars *vars);

#endif