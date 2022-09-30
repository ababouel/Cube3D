/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:00:33 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/30 00:00:13 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*my_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

int		ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' ||
			c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

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

void    ft_copy_colors(t_vars *vars, char **tmp, int index)
{
    char    **color;
    
    vars->data->color[index].type = tmp[0][0];
    color = ft_split(tmp[1], ',', ',');
    vars->data->color[index].rd = ft_atoi(color[0]);
    vars->data->color[index].gr = ft_atoi(color[1]);
    vars->data->color[index].bl = ft_atoi(color[2]);
    color[0] = my_free(color[0]);
    color[1] = my_free(color[1]);
    color[2] = my_free(color[2]);
    color = my_free(color);
}

int ft_is_in_wall(char **map, int x, int y, int lenx, int leny)
{
    if ((x == 0 || y == 0 || x == lenx - 1 || y == leny - 1 
        || ft_is_space(map[y + 1][x]) || ft_is_space(map[y - 1][x]) || ft_is_space(map[y][x + 1]) 
        || ft_is_space(map[y][x  - 1])))
        return (1);
    return (0);
}

int ft_check_map(t_vars *vars)
{
    int x;
    int y;

    y = 0;
    while (y < vars->data->hgt)
    {
        x = 0;
        while (x < vars->data->wth)
        {
            if (ft_is_in_wall(vars->data->map, x, y, vars->data->wth, vars->data->hgt) == 1
                && vars->data->map[y][x] != '1' && ft_is_space(vars->data->map[y][x]) != 1)
            {
                // printf("%d\n", ft_is_in_wall(vars->data->map, x, y, vars->data->wth, vars->data->hgt));
                // printf("%c in %d,%d ----- lenx = %d,, leny = %d\n", vars->data->map[y][x], y, x, vars->data->wth, vars->data->hgt);
                // printf("%s", vars->data->map[y]);
                return (-1);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int ft_parse(char *path, t_vars *vars)
{
    int     i;
    int     j;
    int     fd;
    int     col;
    int     count;
    char    *line;
    char    **tmp;
  
    i = 0; 
    j = 0;
    col = 0;
    count = 6;
    line = NULL;
    tmp = NULL;
    vars->data = (t_data *)malloc(sizeof(t_data));
    vars->data->color = (t_color *)malloc(sizeof(t_color) * 2);
    vars->data->txtpath = (t_txtpath *)malloc(sizeof(t_txtpath) * 4);
    vars->data->txtpath->path = (char **)malloc(sizeof(char *) * 5);
    vars->data->hgt = count_lines(path);
    vars->data->map = (char **)malloc(sizeof(int *) * (vars->data->hgt + 1));
    fd = open(path, O_RDONLY);
    check_fd(fd);
    line = get_next_line(fd);
    while (line)
    {
        if (ft_check_whitespace(line))
        {
            line = my_free(line);
            line = get_next_line(fd);
            continue;
        }
        if (count > 0 && ft_check_whitespace(line) == 0)
        {
            tmp = ft_split(line, ' ', '\t');
            if (ft_strlen(tmp[0]) > 1)
            {
                ft_assign_nswe(tmp[0], vars, i);
                vars->data->txtpath->path[i] = ft_strdup(tmp[1]);
                i++;
            }
            else
            {
                ft_copy_colors(vars, tmp, col);
                col++;
            }
            count--;
            tmp[0] = my_free(tmp[0]);
            tmp[1] = my_free(tmp[1]);
            tmp = my_free(tmp);
        }
        else
        {
            vars->data->wth = ft_invalid_line(line);
           // printf("%d\n", vars->data->wth);
            if (vars->data->wth < 0)
                return (-1);
            vars->data->map[j] = (char *)malloc(sizeof(char) * (vars->data->wth + 1));
            ft_push_data(line, vars->data->map[j]);
            j++;
        }
        line = my_free(line);
        line = get_next_line(fd);
    }
    vars->data->map[j] = NULL;
    //free all splits
    return (ft_check_map(vars));
}