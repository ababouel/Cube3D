/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:34:08 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/23 22:55:15 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_proccess_file(t_vars *vars, t_pars *pars)
{
	if (pars->count > 0 && ft_check_whitespace(pars->line) == 0)
	{
		if (ft_parse_setups(vars, pars) == -1)
			return (-1);
	}
	else
	{
		if (ft_parse_map(vars, pars) == -1)
			return (-1);
	}
	return (1);
}

int	valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	return (fd);
}

void	free_line(t_pars *pars)
{
	pars->tmp[0] = my_free(pars->tmp[0]);
	pars->tmp[1] = my_free(pars->tmp[1]);
	pars->tmp = my_free(pars->tmp);
}

int	ft_parse_setups(t_vars *vars, t_pars *pars)
{
	int	len;

	pars->tmp = ft_split(pars->line, ' ', '\t');
	if (arr_len(pars->tmp) > 2)
		return (-1);
	if (ft_strlen(pars->tmp[0]) > 1)
	{
		if (ft_assign_nswe(pars->tmp[0], vars, pars->i) == 0)
			return (-1);
		vars->data->txtpath[pars->i].path = ft_strdup(pars->tmp[1]);
		len = ft_strlen(vars->data->txtpath[pars->i].path);
		if (ft_strchr(vars->data->txtpath[pars->i].path, '\n') == 0)
			vars->data->txtpath[pars->i].path[len - 1] = '\0';
		if (valid_path(vars->data->txtpath[pars->i].path) < 0)
			return (-1);
		pars->i++;
	}
	else
	{
		if (ft_copy_colors(vars, pars->tmp) == -1)
			return (-1);
	}
	pars->count--;
	free_line(pars);
	return (1);
}
