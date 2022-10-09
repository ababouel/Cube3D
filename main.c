/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/09 20:21:25 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h" 
#include "events.h"
#include "tools.h"
#include "raycast.h"
#include<unistd.h>

char *map[10] = {
	"1111111111",
	"1000000001",
	"1000100001",
	"1000100001",
	"1000000001",
	"10000S0001",
	"1000000001",
	"1000100001",
	"1000100001",
	"1111111111"
};

int	ft_init_vars(t_vars *vars)
{	
	vars->ordr.dir1 = addvect(1, 1, add_color(255,0,0,0), 10);
	vars->ordr.minplane = addvect(cos(M_PI/6.0), sin(M_PI/6.0), add_color(255,0,0,0), 20);
	vars->ordr.maxplane = addvect(cos((M_PI/3.0)), sin((M_PI/3.0)), add_color(255,0,0,0), 20);	
	vars->ordr.dir1->angle = M_PI/50;
	vars->ordr.maxplane->angle = M_PI/50;
	vars->ordr.minplane->angle = M_PI/50;	
	vars->rect.color = add_color(0,0,255,0);
	vars->rect.x = 5;
	vars->rect.y = 5;
	vars->data = malloc(sizeof(t_data));
	vars->data->map = map;
	vars->data->hgt = 10;
	vars->data->wth = 10;
	vars->ceil = add_color(225, 30, 0, 0);
	vars->floor = add_color(220, 100, 0, 0);	
	return(0);
}

uint32_t	*generate_pixels(t_vars *vars, char *path)
{
	t_point		t;
	t_imgarg	ig;
	char		*ttc;
	uint32_t	*txtcolor;

	t.py = 0;
	ig = vars->txtre.ig;
	ig.img = mlx_xpm_file_to_image(vars->mlx, path, &vars->txtre.width, &vars->txtre.height);
	ig.addr = mlx_get_data_addr(ig.img, &ig.bpp, &ig.line_len, &ig.endian);
	txtcolor = malloc(sizeof(uint32_t) * (uint32_t)vars->txtre.width * (uint32_t) vars->txtre.height);
	while (t.py <= vars->txtre.height)
	{
		t.px = 0;
		while (t.px <= vars->txtre.width)
		{
			ttc = ig.addr + ((int) t.py * ig.line_len + (int) t.px * (ig.bpp / 8));
			txtcolor[(vars->txtre.width * t.py) + t.px] = ttc;
			t.px++;	
		}
		t.py++;
	}
	return (txtcolor);
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

int render_next_frame(void *vars)
{
	t_vars	*v;
	
	v = (t_vars *)vars;
	climg(v->iarg->img);
	draw_ceil_floor(vars);
	draw_map(v);
	camera(v);
	mlx_put_image_to_window( v->mlx, v->win, v->iarg->img, 0, 0);
	return (1);
}

int	main(void)
{
	t_vars		*vars;

	vars = allocate();
	ft_init_vars(vars);
	ft_init(vars);
	mlx_loop_hook(vars->mlx, render_next_frame, (void *)vars);	
	mlx_key_hook(vars->win, esc_key, vars);
	mlx_hook(vars->win, 17, 0, close_game, vars);
	mlx_do_sync(vars->mlx);
	mlx_loop(vars->mlx);
}