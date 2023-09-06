/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:03:03 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 09:07:47 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	**build_empty_map(t_map_config *config)
{
	int		i;
	char	**map;

	map = malloc((config->m + 1) * sizeof (char *));
	i = 0;
	while (i < config->m)
	{
		map[i] = malloc(config->n * sizeof (char));
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**populate_map(char *filename, char **map)
{
	unsigned int		fd;
	unsigned int		is_second_line;
	unsigned int		i;
	unsigned int		j;
	char				buffer;

	fd = open(filename, O_RDONLY);
	is_second_line = 0;
	i = 0;
	j = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (!is_second_line && buffer == '\n')
			is_second_line = 1;
		else if (is_second_line && buffer != '\n')
			map[i][j++] = buffer;
		else if (is_second_line && buffer == '\n')
		{
			i++;
			j = 0;
		}
	}
	return (map);
}

char	**load_map(char *filename, t_map_config *config)
{
	char	**map;

	map = build_empty_map(config);
	map = populate_map(filename, map);
	return (map);
}
