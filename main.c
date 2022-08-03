/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:34:40 by ababouel          #+#    #+#             */
/*   Updated: 2022/08/03 02:57:45 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
// #include "GLFW/glfw3.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_loop(mlx);
}
