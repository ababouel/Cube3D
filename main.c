/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/08/03 03:02:05 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include <stdlib.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;
typedef struct	s_data {
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	rans(int max_number, int minimum_number)
{
	int number;

	number = rand() % (max_number + 1 - minimum_number) + minimum_number;
	return (number);
}
int	close(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
}
int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	if (vars.mlx != NULL)
    	vars.win = mlx_new_window(vars.mlx, 1280, 720, "cub3d");
	vars.img = mlx_new_image(vars.mlx, 1280, 720);
	img.addr = mlx_get_data_addr(vars.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int x = 1;
	while (x < 720)
	{
		int y = 1;
		while (y < 1280)
		{
			my_mlx_pixel_put(&img, y, x, create_trgb(128, rans(255, 0), rans(255, 0), rans(255, 0)));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win, ON_DESTROY, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
