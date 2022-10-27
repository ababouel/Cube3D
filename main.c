/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/28 00:17:43 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "draw.h" 
#include "events.h"
#include "tools.h"
#include "raycast.h"

static int	ft_init_vars(t_vars *vars)
{
	vars->ordr.dir1 = addvect(cos(0), sin(0), add_color(255, 0, 0), 10);
	vars->ordr.minplane = addvect(cos(-M_PI / 6.0), sin(-M_PI / 6.0),
			add_color(255, 0, 0), 20);
	vars->ordr.maxplane = addvect(cos((M_PI / 6.0)), sin((M_PI / 6.0)),
			add_color(255, 0, 0), 20);
	vars->ordr.dir1->angle = M_PI / 50;
	vars->ordr.maxplane->angle = M_PI / 50;
	vars->ordr.minplane->angle = M_PI / 50;
	vars->rect.cwall = add_color(0, 0, 255);
	vars->rect.cfloo = add_color(255, 255, 255);
	vars->ray.top_x = 0;
	vars->rect.x = 10;
	vars->rect.y = 10;
	if (ft_set_nswe(vars) == -1)
		return (-1);
	return (0);
}

static int	ft_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (MLX_ERROR);
	vars->win = mlx_new_window(vars->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!vars->win)
	{
		free(vars);
		return (MLX_ERROR);
	}
	vars->iarg->img = mlx_new_image(vars->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->iarg->addr = mlx_get_data_addr(vars->iarg->img,
			&vars->iarg->bpp, &vars->iarg->line_len, &vars->iarg->endian);
	return (0);
}

static int	render_next_frame(void *vars)
{
	t_vars	*v;

	v = (t_vars *)vars;
	ft_check_keys(vars);
	climg(v->iarg->img);
	draw_ceil_floor(v);
	init_pos_player(v);
	camera(v);
	draw_minimap(v);
	mlx_put_image_to_window(v->mlx, v->win, v->iarg->img, 0, 0);
	return (1);
}

static int	start_drawing(t_vars *vars)
{
	ft_init(vars);
	if (ft_init_vars(vars) == -1)
	{
		ft_putstr_fd("Error.\n", 2);
		clear_data(vars);
		return (-1);
	}
	mlx_loop_hook(vars->mlx, render_next_frame, (void *)vars);
	mlx_hook(vars->win, 17, 0, close_game, vars);
	mlx_hook(vars->win, 02, 0, move_keys, vars);
	mlx_hook(vars->win, 03, 0, move_keys_release, vars);
	mlx_hook(vars->win, 06, 0, move_mouse, vars);
	mlx_mouse_hide();
	mlx_do_sync(vars->mlx);
	mlx_loop(vars->mlx);
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
			ft_putstr_fd("Error.\n", 2);
			return (1);
		}
		start_drawing(vars);
	}
	else
		ft_putstr_fd("Usage ./cub3d map_name \n", 2);
	return (0);
}
