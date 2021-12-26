/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdragomi <vdragomi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:16:00 by vdragomi          #+#    #+#             */
/*   Updated: 2021/11/07 14:16:00 by vdragomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** gcc -Wall -Wextra -Werror -g *.c so_long.h mlx/libmlx_Linux.a -L 
** /usr/include/X11/extensions/ -lXext -lX11 -lm
*/

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = ft_calloc(sizeof(t_vars), 1);
	if (vars == NULL)
		return (0);
	if (argc != 2)
		ft_error_printer("Incorrect number of arguments!\n", vars);
	else
		map_ending_check(argv[1], vars);
	ft_get_maxis(argv, vars);
	game_init(vars, argv);
	put_map(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 33, (1L << 17), exit_game, vars);
	mlx_hook(vars->win, 23, (1L << 15), put_map, vars);
	mlx_loop(vars->mlx);
	exit_game(vars);
	return (1);
}
