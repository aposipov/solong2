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

//int	movements(int keycode, t_data **vars)
//{
//	(void)vars;
//	if (keycode == 53)
//	{
//		mlx_destroy_window((*vars)->mlx, (*vars)->win);
//		exit(0);
//	}
//	else if (keycode == 13)
//		printf("W press\n");
//	else if (keycode == 1)
//		printf("S press\n");
//	else if (keycode == 0)
//		printf("A press\n");
//	else if (keycode == 2)
//		printf("D press\n");
//	return(0);
//}

void	movements(int keycode, t_data **vars)
{
	if (keycode == 13 || keycode == 126)
	{
		(*vars)->pos_player.y -= 1;
		//game->dir = "up";
	}
	if (keycode == 1 || keycode == 125)
	{
		(*vars)->pos_player.y += 1;
		printf("\nC = %d\n", (*vars)->chr.collect);
		//game->dir = "down";
	}
	if (keycode == 0 || keycode == 123)
	{
		(*vars)->pos_player.x -= 1;
		//game->dir = "left";
	}
	if (keycode == 2 || keycode == 124)
	{
		(*vars)->pos_player.x += 1;
		//->dir = "right";
	}
}

void	forstpdnomr(t_data **vars)
{
	if ((*vars)->file_map[(*vars)->pos_player.y][(*vars)->pos_player.x] == 'e')
	{
		write(1, "you won !\n", 10);
		exit(0);
	}
//	if ((*vars)->file_map[(*vars)->pos_player.y][(*vars)->pos_player.x] == 'A')
//	{
//		write(1, "WASTED !\n", 9);
//		exit(0);
//	}
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
			forstpdnomr(vars);
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