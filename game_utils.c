/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdragomi <vdragomi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:23:36 by vdragomi          #+#    #+#             */
/*   Updated: 2021/11/08 23:09:36 by vdragomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	last_row_wall_check(char *res, t_vars *vars)
{
	int	i;

	i = 0;
	while (res[i])
	{
		while (res[i + 1] != '\0')
		{
			if (res[i] != '1')
				ft_error_printer("Map is not surrounded by walls!\n", vars);
			i++;
		}
		if (res[i + 1] == '\0')
		{
			if (res[i] != '1')
				ft_error_printer("Map is not surrounded by walls!\n", vars);
		}
		i++;
	}
}

void	print_movement(t_vars *vars)
{
	char	*moves;

	moves = ft_itoa(vars->move_nbr);
	put_map(vars);
	mlx_string_put(vars->mlx, vars->win, 30, 30, 123456, moves);
	free(moves);
}

void	player_movement(t_vars *vars, int x_diff, int y_diff)
{
	if ((vars->arr[(vars->kitty->y / 32) + x_diff] \
		[(vars->kitty->x / 32) + y_diff]) != '1')
	{
		if ((vars->arr[(vars->kitty->y / 32) + x_diff] \
		[(vars->kitty->x / 32) + y_diff]) == 'C')
			vars->collect_nbr--;
		if (((vars->arr[(vars->kitty->y / 32) + x_diff] \
		[(vars->kitty->x / 32) + y_diff]) == 'E') && vars->collect_nbr == 0)
			exit_game(vars);
		else if (((vars->arr[(vars->kitty->y / 32) + x_diff] \
		[(vars->kitty->x / 32) + y_diff]) == 'E') && vars->collect_nbr > 0)
			return ;
		if (((vars->arr[(vars->kitty->y / 32) + x_diff] \
		[(vars->kitty->x / 32) + y_diff]) == 'X'))
			exit_game(vars);
		vars->arr[(vars->kitty->y / 32)][(vars->kitty->x / 32)] = '0';
		vars->arr[(vars->kitty->y / 32) + x_diff] \
		[(vars->kitty->x / 32) + y_diff] = 'P';
		vars->move_nbr++;
		draw_enemy(vars);
		print_movement(vars);
	}
}

int	key_hook(int key_code, t_vars *vars)
{
	if (key_code == 65307)
		exit_game(vars);
	else if ((key_code == 119) || (key_code == 65362))
		player_movement(vars, -1, 0);
	else if (key_code == 97 || key_code == 65361)
		player_movement(vars, 0, -1);
	else if (key_code == 115 || key_code == 65364)
		player_movement(vars, 1, 0);
	else if (key_code == 100 || key_code == 65363)
		player_movement(vars, 0, 1);
	return (0);
}

void	memory_release2(t_vars *vars)
{
	if (vars->floor)
		free(vars->floor);
	if (vars->wall)
		free(vars->wall);
	if (vars->kitty)
		free(vars->kitty);
	if (vars->collect)
		free(vars->collect);
	if (vars->exit)
		free(vars->exit);
	if (vars->enemy)
		free(vars->enemy);
	if (vars->arr)
		free(vars->arr);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	if (vars->mlx)
		free(vars->mlx);
}
