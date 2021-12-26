/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdragomi <vdragomi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:16:06 by vdragomi          #+#    #+#             */
/*   Updated: 2021/11/07 14:16:06 by vdragomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PLAYERPATH "images/kitty.xpm"
# define FLOORPATH "images/floor.xpm"
# define EXITPATH "images/exit.xpm"
# define COLLPATH "images/collect.xpm"
# define WALLPATH "images/wall.xpm"
# define ENEMYPATH_L "images/enemy1.xpm"
# define ENEMYPATH_R "images/enemy2.xpm"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include "mlx/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	*kitty;
	t_data	*floor;
	t_data	*wall;
	t_data	*collect;
	t_data	*exit;
	t_data	*enemy;
	char	**arr;
	int		map_rows;
	int		map_cols;
	int		collect_nbr;
	int		move_nbr;
}			t_vars;

void	draw_enemy(t_vars *vars);
void	double_free_array(t_vars *vars);
void	memory_release2(t_vars *vars);
char	*ft_itoa(int n);
int		put_map(t_vars *vars);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	memory_release(t_vars *vars);
int		exit_game(t_vars *vars);
void	ft_error_printer(char *s, t_vars *vars);
size_t	ft_strlen(const char *s);
void	map_ending_check(char *str, t_vars *vars);
int		check_params(char *merger, char const *s1, char const *s2);
char	*ft_strjoin(char *s1, char *s2);
void	ft_get_maxis(char **argv, t_vars *vars);
void	character_check(char *res, t_vars *vars);
void	value_check(char *res, int counter, t_vars *vars);
void	wall_check(char *res, t_vars *vars);
void	rectangular_check(char *res, t_vars *vars);
void	rowsncols(char *res, int mapsize, t_vars *vars);
t_data	*init_tile(t_vars *vars, char *path);
char	**init_map(t_vars *vars, char **argv);
void	game_init(t_vars *vars, char **argv);
void	char_ident(t_vars *vars, int i, int j);
void	last_row_wall_check(char *res, t_vars *vars);
void	print_movement(t_vars *vars);
void	player_movement(t_vars *vars, int x_diff, int y_diff);
int		key_hook(int key_code, t_vars *vars);

#endif
