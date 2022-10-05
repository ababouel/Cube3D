/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:17:08 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/05 17:38:38 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_fd(int fd)
{
	if (fd < 0)
	{
		printf("Error opening the file\n");
		exit(FILE_ERROR);
	}
}

int	ft_invalid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S' 
			&& line[i] != 'W' && line[i] != 'E' && ft_is_space(line[i]) == 0)
			return (-1);
		i++;
	}
	return (i);
}

int ft_check_line(char *line)
{
	if (ft_check_whitespace(line) == 1 || ft_invalid_line(line) < 0)
		return (-1);
	return (0);
}

int	count_lines(char *path)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(path, O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_check_line(line) == 0)
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
