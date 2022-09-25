/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:41 by ababouel          #+#    #+#             */
/*   Updated: 2022/09/25 02:02:58 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef enum e_NSWE
{
    NO,
    SO,
    WE,
    EA
}   t_nswe;

typedef struct s_txtpath
{
    char    *path;
    t_nswe  nswe; 
}   t_txtpath;

typedef struct s_color
{
    int rd;
    int gr;
    int bl;
    int al;
}   t_color;

typedef struct s_data
{
    int         wth;
    int         hgt;
    t_txtpath   *txtpath; 
    char        **map;
}   t_data;

#endif