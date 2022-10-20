/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:47:26 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/19 23:50:20 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DRAW_H
# define DRAW_H

#include "data.h"

void	generate_image(t_vars *vars, char *path, t_nswe ns);
void	draw_pixel(t_imgarg *data, t_vector *v);
int		create_trgb(t_color *color);
void	draw_line(t_vector *v1, t_vector *v2, t_vars *data);
void	draw_circle(t_vars *data, t_vector *v, double rad);
void	draw_rect(t_vars *data, double rect, t_vector v);
void	draw_map(t_vars *vars);
void	draw_ceil_floor(t_vars *vars);
void    draw_minimap(t_vars *vars);

#endif