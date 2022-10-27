/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:37:52 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/28 00:24:45 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "draw.h" 

# define ON_DESTROY 17
# define ESC_KEY 53
# define ARROWLEFT 123
# define ARROWRIGHT 124
# define DOWN_S 1
# define UP_W 13
# define LEFT_A 0
# define RIGHT_D 2

int		close_game(t_vars *vars);
int		esc_key(int keynum, t_vars *vars);
void	clear_data(t_vars *vars);
void	climg(t_imgarg *img);
void	ft_check_keys(t_vars *vars);
void	ft_rotate(t_vars *vars, int choice);
int		move_keys(int keynum, t_vars *vars);
int		move_mouse(int x, int y, t_vars *data);
int		move_keys_release(int keynum, t_vars *vars);

#endif
