/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ckeck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:32:36 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/05 17:37:55 by fech-cha         ###   ########.fr       */
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