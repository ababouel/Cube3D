/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:37:04 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/23 23:04:21 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "data.h"

void	*my_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

void	ft_next_line(t_pars *pars)
{
	pars->line = my_free(pars->line);
	pars->line = get_next_line(pars->fd);
}

int	ft_iscolor(char *c, int i)
{
	if ((c[i] >= '0' && c[i] <= '9') || (c[i] == ',' && c[i + 1] != ','))
		return (1);
	return (-1);
}

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_is_in_wall(t_vars *vars, int x, int y)
{
	if ((x == 0 || y == 0 || x == vars->data->wth[y] - 1
			|| y == vars->data->hgt - 1
			|| ft_is_space(vars->data->map[y + 1][x])
		|| ft_is_space(vars->data->map[y - 1][x])
		|| ft_is_space(vars->data->map[y][x + 1])
		|| ft_is_space(vars->data->map[y][x - 1]))
		|| x > vars->data->wth[y - 1] - 1)
		return (1);
	return (0);
}
