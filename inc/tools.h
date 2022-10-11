/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 02:43:41 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/10 21:13:53 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include "draw.h"
#include "events.h"

t_vector    *addvect(double x, double y, t_color color, double mag);
t_color     add_color(int rd, int gr, int bl);
t_vars      *allocate(void);
void        rotation(t_vector *v, double angle);
void        debug(t_vector *v, int x, double angle);
void        norm_vect(t_vector *vect);
void        vect_multi(t_vector *dir,double scale);
void        vect_add(t_vector *origin, t_vector *dir, double angle);

#endif