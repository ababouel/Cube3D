/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:00:33 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/05 18:57:21 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void    ft_push_data(char *line, char *arr)
{
    int i;

    i = 0;
    while (line[i])
    {
        arr[i] = line[i];
        i++;
    }
    arr[i] = '\0';
}

int ft_assign_nswe(char *nswe, t_vars *vars, int i)
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

int ft_copy_colors(t_vars *vars, char **tmp, int index)
{
    char    **color;
    
    if (tmp[0][0] == 'F' || tmp[0][0] == 'C')
    {
        vars->data->color[index].type = tmp[0][0];
        if (ft_check_format(tmp[1]) == 1)
        {
            color = ft_split(tmp[1], ',', ',');
            vars->data->color[index].rd = ft_atoi(color[0]);
            vars->data->color[index].gr = ft_atoi(color[1]);
            vars->data->color[index].bl = ft_atoi(color[2]);
            color[0] = my_free(color[0]);
            color[1] = my_free(color[1]);
            color[2] = my_free(color[2]);
            color = my_free(color);
            return (1);
        }
        else
            return (-1);
    }
    else
        return (-1);
}

void    ft_init_pars(t_vars *vars, t_pars *pars, char *path)
{
    pars->i = 0; 
    pars->j = 0;
    pars->col = 0;
    pars->count = 6;
    pars->line = NULL;
    pars->tmp = NULL;
    vars->data = (t_data *)malloc(sizeof(t_data));
    vars->data->color = (t_color *)malloc(sizeof(t_color) * 2);
    vars->data->txtpath = (t_txtpath *)malloc(sizeof(t_txtpath) * 4);
    vars->data->txtpath->path = (char **)malloc(sizeof(char *) * 5);
    vars->data->hgt = count_lines(path);
    vars->data->wth = (int *)malloc(sizeof(int) * vars->data->hgt);
    vars->data->map = (char **)malloc(sizeof(int *) * (vars->data->hgt + 1));
}

int ft_parse_setups(t_vars *vars, t_pars *pars)
{
    if (pars->count > 0 && ft_check_whitespace(pars->line) == 0)
    {
        pars->tmp = ft_split(pars->line, ' ', '\t');
        if (ft_strlen(pars->tmp[0]) > 1)
        {
            if (ft_assign_nswe(pars->tmp[0], vars, pars->i) == 0)
                return (-1);
            vars->data->txtpath->path[pars->i] = ft_strdup(pars->tmp[1]);
            pars->i++;
        }
        else
        {
            if (ft_copy_colors(vars, pars->tmp, pars->col) == -1)
                return (-1);
            pars->col++;
        }
        pars->count--;
        pars->tmp[0] = my_free(pars->tmp[0]);
        pars->tmp[1] = my_free(pars->tmp[1]);
        pars->tmp = my_free(pars->tmp);
        return (1);
    }
    else
        return (2);
}

int ft_parse_map(t_vars *vars, t_pars *pars)
{
    vars->data->wth[pars->j] = ft_invalid_line(pars->line);
    if (vars->data->wth[pars->j] < 0)
        return (-1);
    vars->data->map[pars->j] = (char *)malloc(sizeof(char) * (vars->data->wth[pars->j] + 1));
    ft_push_data(pars->line, vars->data->map[pars->j]);
    pars->j++;
    return (1);
}

int ft_parse(char *path, t_vars *vars)
{  
    int     hold;
    t_pars  pars;
    
    ft_init_pars(vars, &pars, path);
    pars.fd = open(path, O_RDONLY);
    check_fd(pars.fd);
    pars.line = get_next_line(pars.fd);
    while (pars.line)
    {
        if (ft_check_whitespace(pars.line))
        {
            pars.line = my_free(pars.line);
            pars.line = get_next_line(pars.fd);
            continue;
        }
        hold = ft_parse_setups(vars, &pars);
        if (hold == 2)
        {
            if (ft_parse_map(vars, &pars) == -1)
                return (-1);
        }
        else
            return (hold);
        pars.line = my_free(pars.line);
        pars.line = get_next_line(pars.fd);
    }
    vars->data->map[pars.j] = NULL;
    return (ft_check_map(vars));
}