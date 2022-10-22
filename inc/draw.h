/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:47:26 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/23 00:10:04 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DRAW_H
# define DRAW_H

#include "data.h"

void	generate_image(t_vars *vars, char *path, t_nswe ns);
void	draw_pixel(t_imgarg *data, t_vector *v);
void	draw_line(t_vector *v1, t_vector *v2, t_vars *data);
void	draw_circle(t_vars *data, t_vector *v, double rad);
void	draw_rect(t_vars *data, double rect, t_vector v);
void	init_pos_player(t_vars *vars);
void	draw_ceil_floor(t_vars *vars);
void	draw_minimap(t_vars *vars);

#endif