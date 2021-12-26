/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:16:37 by vdragomi          #+#    #+#             */
/*   Updated: 2021/11/07 19:03:29 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*return_p;

	if (nmemb * size > 4294967295)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return_p = malloc (1);
	else
		return_p = malloc (nmemb * size);
	if (return_p == NULL)
		return (NULL);
	ft_memset(return_p, '\0', nmemb * size);
	return (return_p);
}

void	memory_release(t_vars *vars)
{
	if (vars->arr)
	{
		double_free_array(vars);
		if (vars->floor->img)
			mlx_destroy_image(vars->mlx, vars->floor->img);
		if (vars->wall->img)
			mlx_destroy_image(vars->mlx, vars->wall->img);
		if (vars->kitty->img)
			mlx_destroy_image(vars->mlx, vars->kitty->img);
		if (vars->collect->img)
			mlx_destroy_image(vars->mlx, vars->collect->img);
		if (vars->exit->img)
			mlx_destroy_image(vars->mlx, vars->exit->img);
		if (vars->enemy->img)
			mlx_destroy_image(vars->mlx, vars->enemy->img);
		memory_release2(vars);
	}
	free(vars);
}

int	exit_game(t_vars *vars)
{
	if (vars)
		memory_release(vars);
	exit(1);
}

void	ft_error_printer(char *s, t_vars *vars)
{
	write(2, "Error!\n", 7);
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
	exit_game(vars);
	exit(EXIT_FAILURE);
}
