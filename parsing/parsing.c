/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:00:33 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/25 06:12:02 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int ft_parse(char *path, t_vars *vars)
{
    int     line_count;
    int     fd;
    char    *line;

    (void)vars;
    line_count = count_lines(path);
    fd = open(path, O_RDONLY);
    check_fd(fd);
    while (line_count--)
    {
        line = get_next_line(fd);
        if (ft_strlen(line) == 0)
            free(line);
        // else
        // {
            
        // }
    }
    return (0);
}