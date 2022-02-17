/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:44:49 by lchristi          #+#    #+#             */
/*   Updated: 2022/02/14 20:44:56 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void	draw(char *path, t_data **vars)
{
	void	*chr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	chr = mlx_xpm_file_to_image((*vars)->mlx, path, &x, &y);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, \
	chr, (*vars)->win_draw.x, (*vars)->win_draw.y);
}

void	draw_box(char box, t_data **vars, int i, int j)
{
	if (box == '1')
		draw("./xpm/wall_50_50.xpm", vars);
	else if (box == '0')
		draw("./xpm/ground.xpm", vars);
	else if (box == 'C')
	{
		draw("./xpm/c_50_50.xpm", vars);
		(*vars)->chr.collect += 1;
	}
	else if (box == 'E')
	{
		draw("./xpm/close_50_50.xpm", vars);
	}
	else if (box == 'e')
		draw("./xpm/open_50_50.xpm", vars);
	else if (box == 'P')
	{
		(*vars)->pos_player.x = j;
		(*vars)->pos_player.y = i;
		draw("./xpm/p_50_50.xpm", vars);
	}
	else if (box == 'A')
		draw("./xpm/a_50_50.xpm", vars);
}

void	map(char **file_map, t_data **vars)
{
	int		i;
	int		j;
	char	*str;
	char	*score;

	str = NULL;
	i = 0;
	(*vars)->win_draw.y = 0;
	(*vars)->chr.collect = 0;
	while (file_map[i])
	{
		(*vars)->win_draw.x = 0;
		j = 0;
		while (file_map[i][j])
		{
			draw_box(file_map[i][j], vars, i, j);
			j++;
			(*vars)->win_draw.x += 50;
		}
		(*vars)->win_draw.y += 50;
		i++;
	}
	score = ft_itoa((*vars)->score);
	str = ft_strjoin2("moves: ", score);
	free(score);
	mlx_string_put((*vars)->mlx, (*vars)->win, 10, 10, 1, str);
	free(str);
	//free(print_score(vars));
}

//char *print_score(t_data **vars)
//{
//	char *score;
//	char *str;
//
//	str = NULL;
//	score = ft_itoa((*vars)->score);
//	str = ft_strjoin("moves: ", score);
//	free(score);