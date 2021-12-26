/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdragomi <vdragomi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:51:40 by dzivanov          #+#    #+#             */
/*   Updated: 2021/11/08 23:10:56 by vdragomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	double_free_array(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map_rows)
	{
		if (vars->arr[i])
			free(vars->arr[i]);
		i++;
	}
}

void	draw_enemy(t_vars *vars)
{
	if (vars->enemy->img)
		mlx_destroy_image(vars->mlx, vars->enemy->img);
	if (vars->enemy)
		free(vars->enemy);
	if (vars->move_nbr % 2 == 0)
		vars->enemy = init_tile(vars, ENEMYPATH_L);
	else
		vars->enemy = init_tile(vars, ENEMYPATH_R);
}
