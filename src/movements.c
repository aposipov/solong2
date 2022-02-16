/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:38:16 by lchristi          #+#    #+#             */
/*   Updated: 2022/02/08 15:38:18 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	movements(int keycode, t_data **vars)
{
	if (keycode == 13 || keycode == 126)
	{
		(*vars)->pos_player.y -= 1;
		(*vars)->score += 1;
	}
	if (keycode == 1 || keycode == 125)
	{
		(*vars)->pos_player.y += 1;
		(*vars)->score += 1;
	}
	if (keycode == 0 || keycode == 123)
	{
		(*vars)->pos_player.x -= 1;
		(*vars)->score += 1;
	}
	if (keycode == 2 || keycode == 124)
	{
		(*vars)->pos_player.x += 1;
		(*vars)->score += 1;
	}
	printf("\n score = %d", (*vars)->score);
}

void	finish_game(t_data **vars)
{
	if ((*vars)->file_map[(*vars)->pos_player.y][(*vars)->pos_player.x] == 'e')
	{
		write(1, "you won !\n", 10);
		exit(0);
	}
}

void	redraw(t_data **vars)
{
	int	i;
	int	j;

	i = 0;
	while ((*vars)->file_map[i])
	{
		j = 0;
		while ((*vars)->file_map[i][j])
		{
			if ((*vars)->file_map[i][j] == 'P')
				(*vars)->file_map[i][j] = '0';
			if (i == (*vars)->pos_player.y && j == (*vars)->pos_player.x)
				(*vars)->file_map[i][j] = 'P';
			if ((*vars)->chr.collect == 0 && (*vars)->file_map[i][j] == 'E')
				(*vars)->file_map[i][j] = 'e';
			finish_game(vars);
			j++;
		}
		i++;
	}
}

int	player_moves(int keycode, t_data **vars)
{
	if (keycode == 53)
		exit(0);
	movements(keycode, vars);
	if ((*vars)->file_map[(*vars)->pos_player.y][(*vars)->pos_player.x] !=
	'1' &&
			(*vars)->file_map[(*vars)->pos_player.y][(*vars)->pos_player.x] !=
			'E')
		redraw(vars);
	map((*vars)->file_map, vars);
	return (0);
}
