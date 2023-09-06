/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:50:55 by leticia-agu       #+#    #+#             */
/*   Updated: 2023/09/06 09:07:47 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_map.h"
#include "../ft_string/ft_string.h"

t_map_config	*build_empty_map_config(void)
{
	t_map_config	*map;

	map = (t_map_config *) malloc(sizeof (t_map_config));
	map->m = 0;
	map->n = 0;
	map->empty_character = '\0';
	map->obstacle_character = '\0';
	map->full_character = '\0';
	return (map);
}

void	extract_map_config(char *filename, t_map_config *map)
{
	int		fd;
	char	buffer;
	int		counter;

	fd = open(filename, O_RDONLY);
	while (read(fd, &buffer, 1) > 0 && is_numeric_char(buffer))
		map->m = map->m * 10 + buffer - 48;
	map->empty_character = buffer;
	read(fd, &buffer, 1);
	map->obstacle_character = buffer;
	read(fd, &buffer, 1);
	map->full_character = buffer;
	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
		continue ;
	counter = 0;
	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
		counter++;
	map->n = counter;
}

t_map_config	*build_map_config(char *filename)
{
	t_map_config	*map;

	map = build_empty_map_config();
	extract_map_config(filename, map);
	return (map);
}
