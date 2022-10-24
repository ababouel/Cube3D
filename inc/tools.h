/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 02:43:41 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/24 19:36:39 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "draw.h"
# include "events.h"

void		ft_putstr_fd(char *s, int fd);
t_vector	*addvect(double x, double y, t_color color, double mag);
t_color		add_color(int rd, int gr, int bl);
t_vars		*allocate(void);
void		rotation(t_vector *v, double angle);
void		debug(t_vector *v, int x, double angle);
void		norm_vect(t_vector *vect);
void		vect_multi(t_vector *dir, double scale);
void		vect_add(t_vars *vars, double angle);
void		move_dir(t_vars *vars, double travel);
int			ft_cord_in_wall(t_vars *vars, double x, double y);

#endif
