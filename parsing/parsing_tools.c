/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 04:17:08 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/28 20:06:28 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strdup(const char *s)
{
	char	*new_s;
	char	*ptr;
	size_t	len;

	new_s = (char *)s;
	len = ft_strlen(new_s) + 1;
	ptr = (char *)malloc(len);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, new_s, len + 2);
	return (ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

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
		return (1);
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
