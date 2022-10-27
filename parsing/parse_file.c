/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:34:08 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/27 16:39:13 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_proccess_file(t_vars *vars, t_pars *pars)
{
	if (pars->in_map == 1 && ft_check_whitespace(pars->line) == 1)
		return (-1);
	if (pars->count > 0 && ft_check_whitespace(pars->line) == 0)
	{
		if (ft_parse_setups(vars, pars) == -1)
			return (-1);
	}
	else
	{
		if (ft_parse_map(vars, pars) == -1)
			return (-1);
		pars->in_map = 1;
	}
	return (1);
}

void	free_line(char **tmp, int i)
{
	if (i == 1)
	{
		tmp[0] = my_free(tmp[0]);
		tmp[1] = my_free(tmp[1]);
		tmp = my_free(tmp);
	}
	else
	{
		tmp[0] = my_free(tmp[0]);
		tmp[1] = my_free(tmp[1]);
		tmp[2] = my_free(tmp[2]);
		tmp = my_free(tmp);
	}
}

void	ft_delete_nl(t_vars *vars, t_pars *pars)
{
	int	len;

	vars->data->txtpath[pars->i].path = ft_strdup(pars->tmp[1]);
	len = ft_strlen(vars->data->txtpath[pars->i].path);
	if (ft_strchr(vars->data->txtpath[pars->i].path, '\n') == 0)
		vars->data->txtpath[pars->i].path[len - 1] = '\0';
}

int	ft_parse_setups(t_vars *vars, t_pars *pars)
{
	int	len;

	pars->tmp = ft_split(pars->line, ' ', '\t');
	if (arr_len(pars->tmp) != 2)
		return (-1);
	if (ft_strlen(pars->tmp[0]) > 1)
	{
		if (ft_assign_nswe(pars->tmp[0], vars, pars->i) == 0)
			return (-1);
		ft_delete_nl(vars, pars);
		if (valid_path(vars->data->txtpath[pars->i].path) < 0)
			return (-1);
		pars->i++;
	}
	else
	{
		len = ft_strlen(pars->tmp[1]);
		pars->tmp[1][len - 1] = '\0';
		if (ft_copy_colors(vars, pars->tmp) == -1)
			return (-1);
	}
	pars->count--;
	free_line(pars->tmp, 1);
	return (1);
}
