/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:32:36 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/24 23:06:30 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_check_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_is_space(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_format(char *color)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (color[i])
	{
		if (ft_iscolor(color, i) == -1)
			return (-1);
		if (color[i] == ',')
				count++;
		i++;
	}
	if (count != 2)
		return (-1);
	return (1);
}

int	ft_check_members(t_vars *vars, t_pars *pars, int *x, int *y)
{
	if (ft_is_in_wall(vars, *x, *y) == 1 && vars->data->map[*y][*x] != '1'
		&& ft_is_space(vars->data->map[*y][*x]) != 1)
	{
		pars = my_free(pars);
		return (-1);
	}
	if (vars->data->map[*y][*x] == 'N' || vars->data->map[*y][*x] == 'S'
		|| vars->data->map[*y][*x] == 'W' || vars->data->map[*y][*x] == 'E')
	{
		if (pars->flag == 1)
		{
			pars = my_free(pars);
			return (-1);
		}
		pars->flag = 1;
	}
	return (1);
}

int	ft_check_map(t_vars *vars, t_pars *pars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->data->hgt)
	{
		x = 0;
		while (x < vars->data->wth[y])
		{
			if (ft_check_members(vars, pars, &x, &y) == -1)
				return (-1);
			x++;
		}
		y++;
	}
	if (pars->flag == 0)
	{
		pars = my_free(pars);
		return (-1);
	}
	return (0);
}
