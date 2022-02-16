

#include "../inc/so_long.h"

void	search_chr(t_data **vars)
{
	int i;
	int j;

	(*vars)->chr.player = 0;
	(*vars)->chr.exit = 0;
	i = 0;
	while ((*vars)->file_map[i])
	{
		j = 0;
		while ((*vars)->file_map[i][j])
		{
			write(1, &(*vars)->file_map[i][j], 1);
			if ((*vars)->file_map[i][j] == 'P')
				(*vars)->chr.player += 1;
			if ((*vars)->file_map[i][j] == 'E')
				(*vars)->chr.exit += 1;
			j++;
		}
		i++;

	}
}
// i 00 = 1
//i - y = 1
