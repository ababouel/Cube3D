/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:35:59 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/25 02:56:15 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

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

void	clear_data(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_destroy_image(vars->mlx, vars->iarg->img);
	mlx_destroy_window(vars->mlx, vars->win);
	//free array of map
	// while (i < vars->line_count)
	// {
	// 	free(vars->map_colors[i]);
	// 	free(vars->map_values[i]);
	// 	i++;
	// }
	// free(vars->map_colors);
	// free(vars->map_values);
	free(vars->iarg);
	free(vars);
	exit(0);
}