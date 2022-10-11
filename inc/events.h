/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:37:52 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/10 05:34:28 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

#include "data.h"

# define ON_DESTROY 17
# define ESC_KEY 53
# define ARROWLEFT 123
# define ARROWRIGHT 124
# define ARROWDOWN 125
# define ARROWUP 126

#include "draw.h" 

int     close_game(t_vars *vars);
int     esc_key(int keynum, t_vars *vars);
void    clear_data(t_vars *vars);
void	climg(t_imgarg *img);
#endif