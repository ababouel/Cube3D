/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:47:26 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/12 05:02:21 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DRAW_H
# define DRAW_H

# define WINDOW_WIDTH	1920.0
# define WINDOW_HEIGHT	1080.0
# define MLX_ERROR	1
# define RECT_SIZE	64.0

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <assert.h>
# include "parsing.h"

#include "data.h"

void	generate_image(t_vars *vars, char *path, t_nswe ns);
void	draw_pixel(t_vars *data, t_vector *v);
int		create_trgb(t_color *color);
void	draw_line(t_vector *v1, t_vector *v2, t_vars *data);
void	draw_circle(t_vars *data, t_vector *v, double rad);
void	draw_rect(t_vars *data, double x, double y);
void	draw_map(t_vars *vars);
void	draw_ceil_floor(t_vars *vars);

#endif