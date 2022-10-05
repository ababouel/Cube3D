/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:01:01 by fech-cha          #+#    #+#             */
/*   Updated: 2022/09/25 05:17:00 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_strchr(char *str, int c)
{
	while (1)
	{
		if (*str == c)
			return (0);
		else if (*str == '\0')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	char	*new_str;
	int		len;

	len = 0;
	if (str1)
		len = ft_strlen(str1);
	i = len;
	len += ft_strlen(str2);
	new_str = (char *)malloc(len + 1);
	ft_strlcpy(new_str, str1, i + 1);
	ft_strlcpy(new_str + i, str2, len + 1);
	if (str1)
		free(str1);
	return (new_str);
}
