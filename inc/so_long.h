/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:23:36 by lchristi          #+#    #+#             */
/*   Updated: 2022/02/06 16:15:11 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_size {
	int	x;
	int	y;
}	t_size;

typedef struct s_chr {
	int	player;
	int	exit;
	int	collect;
}	t_chr;

typedef struct s_data {
	char	**file_map;
	void	*mlx;
	void	*win;
	t_chr	chr;
	t_size	pos_player;
	t_size	win_draw;
	int		score;
}	t_data;

void	check_chr(char *path);
void	check_size_map(char *path, t_data **vars);
void	check_size_map2(char *line, int j, int fd, t_data **vars);
void	read_map(char *path, t_data **vars);
void	map(char **file_map, t_data **vars);
int		player_moves(int keycode, t_data **vars);
void	search_chr(t_data **vars);
int		fd_open(char *path);
void	check_pec(t_data **vars);
void	valid_wallh(t_data **vars);
void	valid_wallv(t_data **vars);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
char	*print_score(t_data **vars);
char	*ft_itoa(int n);

#endif
