/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:41 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/25 06:03:47 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define FILE_ERROR 1
# define BUFFER_SIZE 1000

#include "data.h"

int	count_lines(char *path);
int ft_parse(char *path, t_vars *vars);
void	check_fd(int fd);
int	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_getline(char *str, int *i);
char	*ft_getrest(char *reminder, int *i);
char	*ft_read_all(char *str, int fd);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_free(char *str1, char *str2);
char	*ft_strjoin(char *str1, char *str2);
int	ft_strchr(char *str, int c);
#endif