/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:19:03 by ababouel          #+#    #+#             */
/*   Updated: 2022/08/06 15:19:08 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}	t_vars;

typedef struct s_imgarg
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_imgarg;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

void	draw_pixel(t_imgarg *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

#endif