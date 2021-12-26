/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:23:49 by vdragomi          #+#    #+#             */
/*   Updated: 2021/11/07 17:59:54 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	map_ending_check(char *str, t_vars *vars)
{
	int	name_len;

	name_len = ft_strlen(str);
	if (str[name_len - 4] != '.' || str[name_len - 3] != 'b' || \
		str[name_len - 2] != 'e' || str[name_len - 1] != 'r')
		ft_error_printer("Wrong map extension (.ber)!\n", vars);
}

int	check_params(char *merger, char const *s1, char const *s2)
{
	if (!(s1 && s2))
		return (0);
	if (merger == NULL)
	{
		free(merger);
		return (0);
	}
	else
		return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*merger;

	merger = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (check_params(merger, s1, s2) == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		merger[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		merger[i + j] = s2[j];
		j++;
	}
	merger[i + j] = '\0';
	free(s1);
	return (merger);
}

void	ft_get_maxis(char **argv, t_vars *vars)
{
	int		fd;
	char	*str;
	char	*res;
	char	initializor;
	int		mapsize;

	mapsize = 0;
	initializor = 0;
	str = &initializor;
	res = (char *)ft_calloc(sizeof(char), 1);
	if (res == NULL)
		exit_game(vars);
	fd = open(argv[1], O_RDONLY);
	if (read(fd, NULL, 0))
		ft_error_printer("File doesn't exist!\n", vars);
	while (read(fd, str, 1))
	{
		res = ft_strjoin(res, str);
		if (res == NULL)
			exit_game(vars);
	}
	mapsize = ft_strlen(res);
	close(fd);
	rowsncols(res, mapsize, vars);
}
