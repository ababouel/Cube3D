/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:41 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/06 21:55:01 by ababouel         ###   ########.fr       */
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
    unsigned char rd;
    unsigned char gr;
    unsigned char bl;
    unsigned char al;
}   t_color;

typedef struct s_data
{
    int         wth;
    int         hgt;
    t_txtpath   *txtpath; 
    char        **map;
}   t_data;

#endif