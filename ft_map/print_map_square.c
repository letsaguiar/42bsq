/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadantas <dadantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:32:47 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 16:43:24 by dadantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "../ft_string/ft_string.h"
#include <fcntl.h>
#include <unistd.h>

int	is_valid_square(int i, int j, t_map_square *square, t_map_config *config)
{
	return ((i >= square->i
			&& i <= square->i + square->size
			&& j >= square->j
			&& j <= square->j + square->size - 1));
}

void	print_map_square(
		char *filename, t_map_config *config, t_map_square *square)
{
	int		i;
	int		j;
	int		fd;
	char	buffer;

	fd = open(filename, O_RDONLY);
	i = 0;
	j = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (i != 0 && is_valid_square(i, j, square, config))
			ft_putchar(config->full_character);
		else if (i != 0)
			ft_putchar(buffer);
		if (i == 0 && buffer == '\n')
		{
			i++;
			j = 0;
		}
		else if (i != 0)
			j++;
	}
}
