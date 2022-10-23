/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:30:05 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/23 04:56:12 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "draw.h"

void	camera(t_vars *vars);
double	cast_ray(t_vars *vars, double rect_size);
void	draw_wall(double dis_ray, t_vars *vars, int *x, double angle);

#endif