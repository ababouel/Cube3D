/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 02:43:41 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/26 04:54:44 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include "draw.h"
#include "events.h"

t_vector    *addvect(double x, double y, t_color *color);
t_color     *add_color(int rd, int gr, int bl, int al);
t_vars      *allocate(void);
void        rotation(t_vector *v, double angle);

#endif