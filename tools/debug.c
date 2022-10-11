/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:00:33 by ababouel          #+#    #+#             */
/*   Updated: 2022/10/01 11:01:38 by ababouel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void debug(t_vector *v, int x, double angle)
{
    if (x)
        printf("origin =>\n");
    else
        printf("dir =>\n");
	printf("vector x => %f\n", v->x);
	printf("vector y => %f\n", v->y);	
	printf("vector angle => %f\n", angle);	
}