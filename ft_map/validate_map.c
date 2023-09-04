/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-aguiar <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:29:25 by leticia-aguia     #+#    #+#             */
/*   Updated: 2023/09/04 19:41:53 by leticia-aguia    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_map.h"

int	validate_map_config(t_map *config)
{
	return (
		config->line_length > 0
		&& config->line_counter > 0
		&& config->empty_character
		&& config->obstacle_character
		&& config->full_character
	);
}

int	validate_map_line_length(char *filename, t_map *config)
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
			counter++;
		else if (is_second_line && buffer == '\n')
		{
			if (counter != config->line_length)
					return (0);
			counter = 0;
		}
	}
	return (1);
}

int	validate_map_characters(char *filename, t_map *config)
{
	int		fd;
	char	buffer;
	int		is_second_line;

	fd = open(filename, O_RDONLY);
	is_second_line = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (!is_second_line && buffer == '\n')
			is_second_line = 1;
		else if (is_second_line && buffer != '\n')
			if (
				buffer != config->empty_character
				&& buffer != config->obstacle_character
				&& buffer != config->full_character
			)
				return (0);
	}
	return (1);
}

int	validate_map(char *filename, t_map *config)
{
	return (
		validate_map_config(config)
		&& validate_map_line_length(filename, config)
		&& validate_map_characters(filename, config)
	);
}
