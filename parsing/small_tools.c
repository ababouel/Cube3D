/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:37:04 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/23 05:53:38 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*my_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

int	ft_iscolor(char *c, int i)
{
	if ((c[i] >= '0' && c[i] <= '9') || (c[i] == ',' && c[i + 1] != ','))
		return (1);
	return (-1);
}

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_is_in_wall(char **map, int x, int y, int *lenx, int leny)
{
	if ((x == 0 || y == 0 || x == lenx[y] - 1 || y == leny - 1
			|| ft_is_space(map[y + 1][x]) || ft_is_space(map[y - 1][x])
			|| ft_is_space(map[y][x + 1])
			|| ft_is_space(map[y][x - 1])) || x > lenx[y - 1] - 1)
		return (1);
	return (0);
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
