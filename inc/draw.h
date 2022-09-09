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

typedef struct s_color
{
	int	t;
	int r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

void	draw_pixel(t_imgarg *data, t_vector *v, int color);
int		create_trgb(t_color *color);
void	draw_line(t_vector *v1, t_vector *v2, t_imgarg *data, t_color *color);
void	draw_circle(t_imgarg *data,t_vector *v, int rad, int color);

#endif