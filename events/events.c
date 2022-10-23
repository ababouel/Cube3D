/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:35:59 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/23 02:32:43 by fech-cha         ###   ########.fr       */
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


void	climg(t_imgarg *img)
{
	t_vector	v;
	char		*pixel;

	v.y = 0;
	while (v.y < WINDOW_HEIGHT)
	{
		v.x = 0;
		while (v.x < WINDOW_WIDTH)
		{
			pixel = img->addr +((int)v.y * img->line_len + (int)v.x * (img->bpp / 8));
			*(unsigned int *)pixel = 0x000000;
			v.x++;
		}
		v.y++;
	}
}

void	clear_data(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_destroy_image(vars->mlx, vars->iarg->img);
	mlx_destroy_window(vars->mlx, vars->win);
	while (i < vars->data->hgt)
	{
		vars->data->map[i] = my_free(vars->data->map[i]);
		i++;
	}
	vars->data->map = my_free(vars->data->map);
	vars->data->wth = my_free(vars->data->wth);
	vars->data->txtpath = my_free(vars->data->txtpath);
	vars->iarg = my_free(vars->iarg);
	vars = my_free(vars);
	exit(0);
}
