/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:32:36 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/05 21:16:32 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"


int ft_check_whitespace(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        if (ft_is_space(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

int ft_check_format(char *color)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (color[i] && color[i] != '\n')
    {
        if (ft_iscolor(color, i) == 1 && count <= 2)
        {
            if (color[i] == ',')
                count++;
            i++;
        }
        else
            return (-1);
    }
    return (1);
}

int ft_check_map(t_vars *vars)
{
    int x;
    int y;

    y = 0;
    while (y < vars->data->hgt)
    {
        x = 0;
        while (x < vars->data->wth[y])
        {
            if (ft_is_in_wall(vars->data->map, x, y, vars->data->wth[x], vars->data->hgt) == 1
                && vars->data->map[y][x] != '1' && ft_is_space(vars->data->map[y][x]) != 1)
            {
                return (-1);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int ft_proccess_file(t_vars *vars, t_pars *pars)
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

int ft_parse_setups(t_vars *vars, t_pars *pars)
{
    pars->tmp = ft_split(pars->line, ' ', '\t');
    if (arr_len(pars->tmp) > 2)
        return (-1);
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
