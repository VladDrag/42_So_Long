/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:57:22 by vdragomi          #+#    #+#             */
/*   Updated: 2021/11/07 18:32:20 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	character_check(char *res, t_vars *vars)
{
	int	i;

	i = 0;
	while (res[i] != '\0')
	{
		if (!((res[i] == '1') || (res[i] == '0') || (res[i] == 'P') || \
			(res[i] == 'C') || (res[i] == 'E') || (res[i] == 'X') || \
			(res[i] == '\n') || (res[i] == '\0')))
			ft_error_printer("Map must contain only valid characters!\n", vars);
		i++;
	}
	free(res);
}

void	value_check(char *res, int counter, t_vars *vars)
{
	int	count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (res[counter])
	{
		if (res[counter] == 'P')
			count[0]++;
		else if (res[counter] == 'C')
			count[1]++;
		else if (res[counter] == 'E')
			count[2]++;
		counter++;
	}
	vars->collect_nbr = count[1];
	if (count[0] <= 0)
		ft_error_printer("No Player Starting Position.\n", vars);
	else if (count[0] > 1)
		ft_error_printer("More then 1 starting position for player.\n", vars);
	if (count[1] <= 0)
		ft_error_printer("No Collectibles found on map.\n", vars);
	if (count[2] <= 0)
		ft_error_printer("No Exits found on map.\n", vars);
}

void	wall_check(char *res, t_vars *vars)
{
	int	i;
	int	row_count;

	i = 0;
	row_count = 1;
	while (res[i])
	{
		while (i < vars->map_cols)
		{
			if (res[i] != '1')
				ft_error_printer("Map is not surrounded by walls!\n", vars);
			i++;
		}
		if (res[i] == '\n')
		{
			row_count++;
			if ((res[i - 1] != '1') || (res[i + 1] != '1'))
				ft_error_printer("Map is not surrounded by walls!\n", vars);
		}
		else if (row_count == vars->map_rows)
			last_row_wall_check(&res[i], vars);
		i++;
	}
	value_check(res, 0, vars);
	character_check(res, vars);
}

void	rectangular_check(char *res, t_vars *vars)
{
	int	i;
	int	col_nb;

	i = 0;
	col_nb = 1;
	while (res[i])
	{
		if ((res[i] == '\n') || (res[i + 1] == '\0'))
		{
			if (res[i] == '\n' && col_nb - 1 == vars->map_cols)
				col_nb = 0;
			else if (res[i + 1] == '\0' && col_nb == vars->map_cols)
				col_nb = 0;
			else
				ft_error_printer("Incorrect map size!\n", vars);
		}
		col_nb++;
		i++;
	}
	wall_check(res, vars);
}

void	rowsncols(char *res, int mapsize, t_vars *vars)
{
	int	i;
	int	collen;
	int	rowlen;

	i = 0;
	collen = 0;
	rowlen = 1;
	while (i <= mapsize)
	{
		if (res[i] == '\n')
			rowlen++;
		i++;
	}
	i = 0;
	while (res[i] != '\n')
		i++;
	collen = i;
	vars->map_cols = collen;
	vars->map_rows = rowlen;
	rectangular_check(res, vars);
}
