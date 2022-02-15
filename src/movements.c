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

int	movements(int keycode, t_data **vars)
{
	(void)vars;
	if (keycode == 53)
	{
		mlx_destroy_window((*vars)->mlx, (*vars)->win);
		exit(0);
	}
	else if (keycode == 13)
		printf("W press\n");
	else if (keycode == 1)
		printf("S press\n");
	else if (keycode == 0)
		printf("A press\n");
	else if (keycode == 2)
		printf("D press\n");
	return(0);
}

