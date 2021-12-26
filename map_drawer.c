/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdragomi <vdragomi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:11:07 by vdragomi          #+#    #+#             */
/*   Updated: 2021/11/07 15:39:09 by vdragomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_ident(t_vars *vars, int i, int j)
{
	if (vars->arr[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->floor->img, j * 32, i * 32);
	else if (vars->arr[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->wall->img, j * 32, i * 32);
	else if (vars->arr[i][j] == 'P')
	{
		vars->kitty->x = j * 32;
		vars->kitty->y = i * 32;
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->kitty->img, j * 32, i * 32);
	}
	else if (vars->arr[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->collect->img, j * 32, i * 32);
	else if (vars->arr[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->exit->img, j * 32, i * 32);
	else if (vars->arr[i][j] == 'X')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->enemy->img, j * 32, i * 32);
}

int	put_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map_rows)
	{
		j = 0;
		while (j < vars->map_cols)
		{
			char_ident(vars, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
