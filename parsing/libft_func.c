/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:38:54 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/23 22:32:51 by fech-cha         ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] == s2[j] && s1[i])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

char	*ft_getchr(char *s, int c)
{
	char	ch;

	ch = (char) c;
	if (ch == 0)
		return ((char *)s + ft_strlen(s));
	while (1)
	{
		if (*s == ch)
			return ((char *)s);
		if (*s == '\0')
			break ;
		++s;
	}
	return (NULL);
}

int	arr_len(char **arr)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (arr[index])
	{
		count++;
		index++;
	}
	return (count);
}
