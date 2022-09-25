/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:37:52 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/25 03:12:03 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define ON_DESTROY 17
# define ESC_KEY 53
# define ARROWLEFT 123
# define ARROWRIGHT 124
# define ARROWDOWN 125
# define ARROWUP 126


#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "draw.h" 
#include <assert.h>

int	close_game(t_vars *vars);
int	esc_key(int keynum, t_vars *vars);
void	clear_data(t_vars *vars);

#endif