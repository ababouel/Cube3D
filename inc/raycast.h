/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:30:05 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/28 20:05:50 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# define PI 3.14
# include "draw.h"

void    norm_vect(t_vector *vect);
void    debug_draw_vect(double scale, t_vars *vars);
void    vect_multi(t_vector *dir,double scale);
void    vect_add(t_vector *origin, t_vector *dir, double angle);

#endif