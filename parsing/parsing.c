/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:00:33 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/23 23:00:46 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_push_data(char *line, char *arr)
{
	int	i;

	i = 0;
	while (line[i])
	{
		arr[i] = line[i];
		i++;
	}
	arr[i] = '\0';
}

int	ft_assign_nswe(char *nswe, t_vars *vars, int i)
{
	if (ft_strcmp(nswe, "NO") == 0)
		vars->data->txtpath[i].nswe = NO;
	else if (ft_strcmp(nswe, "SO") == 0)
		vars->data->txtpath[i].nswe = SO;
	else if (ft_strcmp(nswe, "WE") == 0)
		vars->data->txtpath[i].nswe = WE;
	else if (ft_strcmp(nswe, "EA") == 0)
		vars->data->txtpath[i].nswe = EA;
	else
		return (0);
	return (1);
}

void	ft_init_pars(t_vars *vars, t_pars *pars, char *path)
{
	pars->i = 0;
	pars->j = 0;
	pars->col = 0;
	pars->count = 6;
	pars->flag = 0;
	pars->line = NULL;
	pars->tmp = NULL;
	vars->data = (t_data *)malloc(sizeof(t_data));
	if (vars->data == NULL)
		return ;
	vars->data->txtpath = (t_txtpath *)malloc(sizeof(t_txtpath) * 4);
	if (vars->data->txtpath == NULL)
		return ;
	vars->data->hgt = count_lines(path);
	vars->data->wth = (int *)malloc(sizeof(int) * vars->data->hgt);
	if (vars->data->wth == NULL)
		return ;
	vars->data->map = (char **)malloc(sizeof(int *) * (vars->data->hgt + 1));
	if (vars->data->map == NULL)
		return ;
}

int	ft_parse_map(t_vars *vars, t_pars *pars)
{
	vars->data->wth[pars->j] = ft_invalid_line(pars->line);
	if (vars->data->wth[pars->j] < 0)
		return (-1);
	vars->data->map[pars->j] = (char *)malloc(sizeof(char)
			* (vars->data->wth[pars->j] + 1));
	if (vars->data->map[pars->j] == NULL)
		return (-1);
	ft_push_data(pars->line, vars->data->map[pars->j]);
	pars->j++;
	return (1);
}

int	ft_parse(char *path, t_vars *vars)
{
	t_pars	*pars;

	pars = (t_pars *)malloc(sizeof(t_pars));
	if (pars == NULL || ft_strcmp(ft_getchr(path, '.'), ".cub") != 0)
		return (-1);
	ft_init_pars(vars, pars, path);
	pars->fd = open(path, O_RDONLY);
	check_fd(pars->fd);
	pars->line = get_next_line(pars->fd);
	while (pars->line)
	{
		if (ft_check_whitespace(pars->line))
		{
			ft_next_line(pars);
			continue ;
		}
		if (ft_proccess_file(vars, pars) == -1)
		{
			pars = my_free(pars);
			return (-1);
		}
		ft_next_line(pars);
	}
	vars->data->map[pars->j] = NULL;
	return (ft_check_map(vars, pars));
}
