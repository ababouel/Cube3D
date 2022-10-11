/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:38:54 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/05 17:39:03 by fech-cha         ###   ########.fr       */
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
	int i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] == s2[j] && s1[i])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
