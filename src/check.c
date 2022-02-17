/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:44:24 by lchristi          #+#    #+#             */
/*   Updated: 2022/02/14 20:44:38 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/get_next_line.h"

void	check_size_map2(char *line, int j, int fd, t_data **vars)
{
	int	length;

	while (line)
	{
		if (line != NULL)
		{
			if (line[ft_strlen(line) - 1] == '\n')
				length = ft_strlen(line) - 1;
			else
				length = ft_strlen(line);
			if ((*vars)->win_draw.x != length)
			{
				write(1, "check line length!\n", 19);
				exit(0);
			}
			line = get_next_line(fd);
			free(line);
		}
		j++;
	}
	(*vars)->win_draw.y = j;
}

void	check_chr(char *path)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	fd = fd_open(path);
	while (fd > 0)
	{
		i = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[i] && line[i] != '\n')
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] \
			!= 'E' && line[i] != 'C' && line[i] != 'A')
			{
				write(1, "check character! \n", 17);
				exit (0);
			}
			i++;
		}
		free(line);
	}
}

void	check_size_map(char *path, t_data **vars)
{
	int		fd;
	char	*line;
	int		j;

	*vars = malloc(sizeof(t_data));
	line = NULL;
	fd = fd_open(path);
	j = 0;
	line = get_next_line(fd);
	(*vars)->win_draw.x = ft_strlen(line) - 1;
	check_size_map2(line, j, fd, vars);
	free(line);
}

void	read_map(char *path, t_data **vars)
{
	int	fd;
	int	i;

	i = 0;
	(*vars)->file_map = NULL;
	(*vars)->file_map = malloc(sizeof(t_data) * (*vars)->win_draw.y);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(0);
	(*vars)->file_map[i] = get_next_line(fd);
	while ((*vars)->file_map[i])
	{
		i++;
		(*vars)->file_map[i] = get_next_line(fd);
	}
	(*vars)->chr.player = 0;
	(*vars)->chr.exit = 0;
	search_chr(vars);
}
