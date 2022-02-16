/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:48:12 by lchristi          #+#    #+#             */
/*   Updated: 2022/02/16 16:48:20 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	search_chr(t_data **vars)
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
				(*vars)->chr.player += 1;
			if ((*vars)->file_map[i][j] == 'E')
				(*vars)->chr.exit += 1;
			if ((*vars)->file_map[i][j] == 'C')
				(*vars)->chr.collect += 1;
			j++;
		}
		i++;
	}
	if ((*vars)->chr.player <= 0 || (*vars)->chr.exit <= 0 || \
	(*vars)->chr.collect <= 0)
	{
		write(1, "\ncheck you chr\n", 15);
		exit(0);
	}
}

void	valid_wall(t_data **vars)
{
	write(1, "1", 1);
}
