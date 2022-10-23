/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 01:56:21 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/23 01:56:40 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "draw.h" 
#include "events.h"
#include "tools.h"
#include "raycast.h"

void	ft_generate_texture(t_vars *vars, char *path, t_nswe ns)
{
	t_texture	*text;
	t_imgarg	*img;
	
	text = NULL;
	if (ns == WE)
		text = &vars->wall_txt.w_txt;
	else if (ns == NO)
		text = &vars->wall_txt.n_txt;
	else if (ns == SO)
		text = &vars->wall_txt.s_txt;
	else
		text = &vars->wall_txt.e_txt;
	text->txt_img.img = mlx_xpm_file_to_image(vars->mlx, path, &text->width, &text->height);
	img = &text->txt_img;
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
}

void	ft_set_nswe(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ft_generate_texture(vars, vars->data->txtpath[i].path, vars->data->txtpath[i].nswe);
		i++;
	}	
}