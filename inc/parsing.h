/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:41 by ababouel          #+#    #+#             */
/*   Updated: 2022/08/06 19:25:13 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef enum e_NSWE
{
    NONE,
    NO,
    SO,
    WE,
    EA
}   t_nswe;

typedef struct s_txtpath
{
    char    *path;
    t_nswe  nswe; 
}   t_txtpath

typedef struct s_color
{
    int red;
    int green;
    int blue;
}   t_color;

typedef struct s_data
{
    t_txtpath   *txtpath;
    t_color     *color;  
    char        **map;
}   t_data;

#endif