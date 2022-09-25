/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:17:08 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/25 06:09:41 by fech-cha         ###   ########.fr       */
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
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
