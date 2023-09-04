/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-aguiar <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:50:55 by leticia-aguia     #+#    #+#             */
/*   Updated: 2023/09/04 19:30:28 by leticia-aguia    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_map.h"
#include "../ft_string/ft_string.h"

t_map	*build_empty_map()
{
	t_map	*map;

	map = (t_map *) malloc(sizeof (t_map));
	map->line_counter = 0;
	map->line_length = 0;
	map->empty_character = '\0';
	map->obstacle_character = '\0';
	map->full_character = '\0';
	return (map);
}

void	read_map_config(char *filename, t_map *map)
{
	int		fd;
	char	buffer;

	fd = open(filename, O_RDONLY);
	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
	{
		if (is_numeric_char(buffer))
			map->line_counter = map->line_counter * 10 + buffer - 48;
		else if (!map->empty_character)
			map->empty_character = buffer;
		else if (!map->obstacle_character)
			map->obstacle_character = buffer;
		else if (!map->full_character)
			map->full_character = buffer;
		else
			break ;
	}
}

void	read_map_line_length(char *filename, t_map *map)
{
	int		fd;
	int		counter;
	int		is_second_line;
	char	buffer;

	fd = open(filename, O_RDONLY);
	counter = 0;
	is_second_line = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (!is_second_line && buffer == '\n')
			is_second_line = 1;
		else if (is_second_line && buffer != '\n')
			counter++;
		else if (is_second_line && buffer == '\n')
			break ;
	}
	map->line_length = counter;
}

t_map	*load_map(char *filename)
{
	t_map	*map;
	
	map = build_empty_map();
	read_map_config(filename, map);
	read_map_line_length(filename, map);
	return (map);
}
