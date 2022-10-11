/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:04:32 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/25 05:08:54 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_read_all(char *str, int fd)
{
	int			n;
	int			check;
	char		*buffer;

	n = 1;
	check = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	while (n && check)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (ft_free(buffer, str));
		buffer[n] = 0;
		str = ft_strjoin(str, buffer);
		if (!str)
			return (0);
		check = ft_strchr(buffer, '\n');
	}
	ft_free(buffer, 0);
	if (str[0] == 0)
		return (ft_free(str, 0));
	return (str);
}

char	*ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (0);
}

char	*ft_getline(char *str, int *i)
{
	char	*new;

	*i = 0;
	while (str[*i] && str[*i] != '\n')
		*i += 1;
	*i += (str[*i] == '\n');
	new = (char *)malloc(*i + 1);
	ft_strlcpy(new, str, *i + 1);
	new[*i] = '\0';
	return (new);
}

char	*ft_getrest(char *reminder, int *i)
{
	int		len;
	char	*rest;

	rest = NULL;
	if (reminder[*i])
	{
		len = ft_strlen(reminder + *i);
		rest = (char *)malloc(len + 1);
		if (!rest)
		{
			*i = -1;
			return (ft_free(reminder, 0));
		}
		ft_strlcpy(rest, reminder + *i, len + 1);
	}
	free(reminder);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*reminder;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reminder = ft_read_all(reminder, fd);
	if (!reminder)
		return (NULL);
	str = ft_getline(reminder, &i);
	if (!str)
		return (NULL);
	reminder = ft_getrest(reminder, &i);
	if (i == -1)
		return (ft_free(str, 0));
	return (str);
}
