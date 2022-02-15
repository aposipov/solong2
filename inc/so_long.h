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
//# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_size {
	int	x;
	int	y;
}	t_size;

typedef struct	s_chr{
	int P;
	int E;
	int C;
}	t_chr;

typedef struct s_data {
	char	**file_map;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		collect;
	t_chr	chr;
	t_size	win_draw;
}	t_data;

void	check_chr(char *path);
void	check_size_map(char *path, t_data **vars);
void	read_map(char *path,  t_data **vars);
void	map(char **file_map, t_data **vars);
int		movements(int keycode, t_data **vars);

#endif
