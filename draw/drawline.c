/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:35 by ababouel          #+#    #+#             */
/*   Updated: 2022/08/07 00:37:20 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_pixel(t_imgarg *data,int x, int y,int color)
{
	char	*dst;

	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	draw_line(int x )