/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:32:20 by lchristi          #+#    #+#             */
/*   Updated: 2022/02/06 16:43:21 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

int	ft_close(int key)
{
	(void)key;
	exit(0);
}

void	arg_read(char *map)
{
	while (*map)
		write(1, map++, 1);
	write(1, "\n", 1);
}

void	ft_extension(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (!(path[i - 1] == 'r' && path[i - 2] == 'e' && path[i - 3] == 'b' && \
	path[i - 4] == '.' && path[i -5] >= 48))
	{
		write(1, "check you path! -> ", 19);
		arg_read(path);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	*vars;
	int		i;

	i = 0;
	if (argc == 2)
	{
		ft_extension(argv[1]);
		check_chr(argv[1]);
		check_size_map(argv[1], &vars);
		read_map(argv[1], &vars);
		search_chr(&vars);
		// check wall 1?
		// check P E C
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx, vars->win_draw.x * 50, \
		vars->win_draw.y * 50, "so_long");
		mlx_hook(vars->win, 17, 0, ft_close, 0);
		map(vars->file_map, &vars);
		mlx_key_hook(vars->win, player_moves, &vars);
		mlx_loop(vars->mlx);
	}
	else
		write(1, "check your arguments!\n", 22);
	return (0);
}
