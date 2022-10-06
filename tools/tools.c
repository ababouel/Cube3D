/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 02:43:28 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/06 16:42:02 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "raycast.h"

t_vector *addvect(double x, double y, t_color color, double mag)
{
	t_vector *v;

	v = malloc(sizeof(t_vector));
	if (v == NULL)
		return (NULL);
	v->x = x;
	v->y = y;
	v->color = color;
	v->mag = mag;	
	return (v);
}


t_color	add_color(int rd, int gr, int bl, int al)
{
	t_color color;

	color.rd = rd;
	color.bl = bl;
	color.gr = gr;
	color.al = al;
	return color;
}

t_vars	*allocate(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		return (NULL);
	vars->iarg = (t_imgarg *)malloc(sizeof(t_imgarg));
	if (vars->iarg == NULL)
		return (NULL);	
	return (vars);
}

void    rotation(t_vector *vf, double angle)
{
    double  v;

    v = vf->x;
    vf->x = vf->x * cos(angle) - vf->y * sin(angle);
    vf->y = vf->y * cos(angle) + v * sin(angle);
}