/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 04:38:25 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/23 23:12:01 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "data.h"

int	word_count(char *s, char c1, char c2)
{
	int	state;
	int	count;

	count = 0;
	state = OUT;
	while (*s)
	{
		if (*s == c1 || *s == c2)
			state = OUT;
		else if (state == OUT)
		{
			count++;
			state = IN;
		}
		s++;
	}
	return (count);
}

static int	count_length(char *s, char c, char c2, int i)
{
	int	counter;

	counter = 0;
	while (s[i] && s[i] != c && s[i] != c2)
	{
		counter++;
		i++;
	}
	return (counter);
}

static char	**free_arr(char **str, int j)
{
	while (j)
	{
		str[j] = my_free(str[j]);
		j--;
	}
	str = my_free(str);
	return (NULL);
}

char	*ft_start(int *i, int *j, int *k, const char *s)
{
	*i = 0;
	*j = 0;
	*k = 0;
	if (!s)
		return (0);
	return ((char *)s);
}

char	**ft_split(char const *s, char c, char c2)
{
	char	**new;
	t_split	sp;

	if (!ft_start(&sp.i, &sp.j, &sp.k, s))
		return (NULL);
	new = (char **)malloc((word_count((char *)s, c, c2) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (s[sp.i] && sp.j < word_count((char *)s, c, c2) && s[sp.i] != '\n')
	{
		if (s[sp.i] == c || s[sp.i] == c2)
		{
			sp.i++;
			continue ;
		}
		new[sp.j] = (char *)malloc(count_length((char *)s, c, c2, sp.i) + 1);
		if (!new[sp.j])
			return (free_arr(new, sp.j));
		while ((s[sp.i] != c && s[sp.i] != c2) && s[sp.i])
			new[sp.j][sp.k++] = s[sp.i++];
		new[sp.j++][sp.k] = '\0';
		sp.k = 0;
	}
	new[sp.j] = NULL;
	return (new);
}
