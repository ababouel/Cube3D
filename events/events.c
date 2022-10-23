/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:35:59 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/23 03:44:42 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "tools.h"
#include "raycast.h"
#include "parsing.h"

int	close_game(t_vars *vars)
{
	clear_data(vars);
	return (0);
}

int	esc_key(int keynum, t_vars *vars)
{	
	if (keynum == ESC_KEY)
		clear_data(vars);
	return (0);
}

void	ft_rotate(t_vars *vars, int choice)
{
	if (choice == 1)
	{
		vars->ordr.origin->angle += vars->ordr.dir1->angle;
		rotation(vars->ordr.dir1, vars->ordr.dir1->angle);
		rotation(vars->ordr.minplane, vars->ordr.minplane->angle);
		rotation(vars->ordr.maxplane, vars->ordr.maxplane->angle);
	}
	else if (choice == -1)
	{
		vars->ordr.origin->angle -= vars->ordr.dir1->angle;
		rotation(vars->ordr.dir1, -vars->ordr.dir1->angle);
		rotation(vars->ordr.maxplane, -vars->ordr.maxplane->angle);
		rotation(vars->ordr.minplane, -vars->ordr.minplane->angle);
	}
}

int	move_mouse(int x, int y, t_vars *vars)
{	
	(void)y;
	if (x > WINDOW_WIDTH / 2)
		ft_rotate(vars, 1);
	if (x < WINDOW_WIDTH / 2)
		ft_rotate(vars, -1);
	mlx_mouse_move(vars->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	return (0);
}

int	move_keys(int keynum, t_vars *vars)
{
	if (keynum == ARROWRIGHT)
		ft_rotate(vars, 1);
	else if (keynum == ARROWLEFT)
		ft_rotate(vars, -1);
	else if (keynum == UP_W)
		vect_add(vars, 15);
	else if (keynum == DOWN_S)
		vect_add(vars, -15);
	else if (keynum == LEFT_A)
		move_dir(vars, -15);
	else if (keynum == RIGHT_D)
		move_dir(vars, 15);
	return (0);
}
