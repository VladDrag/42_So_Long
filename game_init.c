/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdragomi <vdragomi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:02:06 by vdragomi          #+#    #+#             */
/*   Updated: 2021/11/08 23:09:07 by vdragomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*init_tile(t_vars *vars, char *path)
{
	t_data	*tile;
	int		height;
	int		width;

	height = 32;
	width = 32;
	tile = ft_calloc(sizeof(t_data), 1);
	if (tile == NULL)
		exit_game(vars);
	tile->bits_per_pixel = 0;
	tile->line_length = 0;
	tile->endian = 0;
	tile->x = 0;
	tile->y = 0;
	tile->img = mlx_xpm_file_to_image(vars->mlx, path, &height, &width);
	tile->addr = mlx_get_data_addr(tile->img, &tile->bits_per_pixel + 1, \
	&tile->line_length, &tile->endian);
	return (tile);
}

char	**init_map(t_vars *vars, char **argv)
{
	int		i;
	int		j;
	int		fd1;
	char	**arr;

	i = 0;
	arr = malloc(vars->map_rows * sizeof(char *));
	if (arr == NULL)
		exit_game(vars);
	fd1 = open(argv[1], O_RDONLY);
	while (i < vars->map_rows)
	{
		arr[i] = ft_calloc(vars->map_cols * sizeof(char), 1);
		if (arr[i] == NULL)
			exit_game(vars);
		j = 0;
		while (j < vars->map_cols)
		{
			read(fd1, &arr[i][j], 1);
			j++;
		}
		i++;
	}
	close(fd1);
	return (arr);
}

void	game_init(t_vars *vars, char **argv)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (vars->map_cols) * 32,
			vars->map_rows * 32, "So_long");
	vars->map_cols = vars->map_cols + 1;
	vars->move_nbr = 0;
	vars->floor = init_tile(vars, FLOORPATH);
	vars->kitty = init_tile(vars, PLAYERPATH);
	vars->wall = init_tile(vars, WALLPATH);
	vars->collect = init_tile(vars, COLLPATH);
	vars->exit = init_tile(vars, EXITPATH);
	vars->enemy = init_tile(vars, ENEMYPATH_L);
	vars->arr = init_map(vars, argv);
	if (!vars->mlx || !vars->win || !vars->floor || !vars->kitty \
	|| !vars->wall || !vars->collect || !vars->exit || !vars->enemy \
	|| !vars->arr)
		exit_game(vars);
}
