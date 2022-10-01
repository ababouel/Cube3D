/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/01 21:28:50 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"
#include "draw.h" 
#include <assert.h>
#include "events.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>

t_vars	*allocate(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		return (NULL);
	vars->iarg = (t_imgarg *)malloc(sizeof(t_imgarg));
	if (vars->iarg == NULL)
		return (NULL);
	return (vars);
}

int    ft_init(t_vars *vars)
{
    vars->mlx = mlx_init();
	if (!vars->mlx)
		return (MLX_ERROR);
	vars->win = mlx_new_window(vars->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "vars");
	if (!vars->win)
	{
		free(vars);
		return (MLX_ERROR);
	}
	vars->iarg->img= mlx_new_image(vars->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->iarg->addr = mlx_get_data_addr(vars->iarg->img,
			&vars->iarg->bpp, &vars->iarg->line_len, &vars->iarg->endian);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	int		check;
	if (argc == 2)
	{
		vars = allocate();
		check = ft_parse(argv[1], vars);
		if (check < 0)
		{
			printf("Error.\n");
			return (1);
		}
		else
			printf("Valid map.\n");
		// ft_init(vars);
		// mlx_put_image_to_window( vars->mlx, vars->win, vars->iarg->img, 0,0);
		// mlx_key_hook(vars->win, esc_key, vars);
		// mlx_hook(vars->win, 17, 0, close_game, vars);
		// mlx_loop(vars->mlx);
	}
	else
		printf("Usage ./cub3d map_name \n");
	return (0);
}	