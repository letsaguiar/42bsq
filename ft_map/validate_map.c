/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadantas <dadantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:29:25 by leticia-agu       #+#    #+#             */
/*   Updated: 2023/09/06 16:45:14 by dadantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_map.h"

int	validate_map_config(t_map_config *config)
{
	return (
		config->n > 0
		&& config->m > 0
		&& config->empty_character
		&& config->obstacle_character
		&& config->full_character
	);
}

int	is_valid_character(int buffer, t_map_config *config)
{
	return ((buffer != config->empty_character
			&& buffer != config->obstacle_character
			&& buffer != config->full_character));
}

int	validate_map_characters(char *filename, t_map_config *config)
{
	int		fd;
	char	buffer;
	int		counter;
	int		is_second_line;

	fd = open(filename, O_RDONLY);
	is_second_line = 0;
	counter = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (!is_second_line && buffer == '\n')
			is_second_line = 1;
		else if (is_second_line && buffer != '\n')
		{
			return (!is_valid_character(buffer, config));
			counter++;
		}
		else if (is_second_line && buffer == '\n')
		{
			if (counter != config->n)
				return (0);
			counter = 0;
		}
	}
	return (1);
}

int	validate_map(char *filename, t_map_config *config)
{
	return (
		validate_map_config(config)
		&& validate_map_characters(filename, config)
	);
}
