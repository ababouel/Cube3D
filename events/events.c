/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:35:59 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/25 06:17:39 by ababouel         ###   ########.fr       */
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
	if (keynum == ARROWLEFT)
	{
		if (vars->rect->x < WINDOW_WIDTH)
			vars->rect->x += 10;
		draw_rect(vars);
	}
	else if (keynum == ARROWRIGHT)
	{
		if (vars->rect->x >= 0)
			vars->rect->x -= 10;
		draw_rect(vars);
	}
	mlx_put_image_to_window(vars->mlx,vars->win,vars->iarg->img, 0, 0);
	printf("=>%d\n", keynum);
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