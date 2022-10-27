/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:19:48 by fech-cha          #+#    #+#             */
/*   Updated: 2022/10/28 00:23:18 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "tools.h"
#include "raycast.h"
#include "parsing.h"

void	ft_check_keys(t_vars *vars)
{
	if (vars->keys.arr_right == 1)
		ft_rotate(vars, 1);
	if (vars->keys.arr_left == 1)
		ft_rotate(vars, -1);
	if (vars->keys.arr_up == 1)
		vect_add(vars, 20);
	if (vars->keys.arr_down == 1)
		vect_add(vars, -20);
	if (vars->keys.rot_left == 1)
		move_dir(vars, -20);
	if (vars->keys.rot_right)
		move_dir(vars, 20);
}
