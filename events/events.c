/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:35:59 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/27 20:31:57 by fech-cha         ###   ########.fr       */
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
	if (keynum == ESC_KEY)
		clear_data(vars);
	if (keynum == ARROWRIGHT)
		vars->keys.arr_right = 1;
	if (keynum == ARROWLEFT)
		vars->keys.arr_left = 1;
	if (keynum == UP_W)
		vars->keys.arr_up = 1;
	if (keynum == DOWN_S)
		vars->keys.arr_down = 1;
	if (keynum == LEFT_A)
		vars->keys.rot_left = 1;
	if (keynum == RIGHT_D)
		vars->keys.rot_right = 1;
	return (0);
}

int	move_keys_release(int keynum, t_vars *vars)
{
	if (keynum == ARROWRIGHT)
		vars->keys.arr_right = 0;
	if (keynum == ARROWLEFT)
		vars->keys.arr_left = 0;
	if (keynum == UP_W)
		vars->keys.arr_up = 0;
	if (keynum == DOWN_S)
		vars->keys.arr_down = 0;
	if (keynum == LEFT_A)
		vars->keys.rot_left = 0;
	if (keynum == RIGHT_D)
		vars->keys.rot_right = 0;
	return (0);
}
