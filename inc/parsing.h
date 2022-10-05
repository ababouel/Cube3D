/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:41 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/05 21:20:14 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define IN 1
# define OUT 0
# define FILE_ERROR 1
# define BUFFER_SIZE 1000

#include "data.h"

int     ft_is_in_wall(char **map, int x, int y, int lenx, int leny);
int		ft_is_space(char c);
int     ft_iscolor(char *c, int i);
int     count_lines(char *path);
int     ft_parse(char *path, t_vars *vars);
void	check_fd(int fd);
int     ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_getline(char *str, int *i);
char	*ft_getrest(char *reminder, int *i);
char	*ft_read_all(char *str, int fd);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
int     ft_strchr(char *str, int c);
char	*ft_free(char *str1, char *str2);
void	*my_free(void *ptr);
char	*ft_strjoin(char *str1, char *str2);
char	**ft_split(char const *s, char c, char c2);
int     ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
int     ft_atoi(const char *str);
int		ft_is_space(char c);
int     ft_check_whitespace(char *str);
int     ft_invalid_line(char *line);
int     ft_is_in_wall(char **c, int x, int y, int lenx, int leny);
int     ft_check_whitespace(char *str);
int     ft_check_format(char *color);
int     ft_check_map(t_vars *vars);
int     ft_proccess_file(t_vars *vars, t_pars *pars);
int     ft_parse_setups(t_vars *vars, t_pars *pars);
int     ft_parse_map(t_vars *vars, t_pars *pars);
int     arr_len(char **arr);
int     ft_assign_nswe(char *nswe, t_vars *vars, int i);
int     ft_copy_colors(t_vars *vars, char **tmp, int index);

#endif