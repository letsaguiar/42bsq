/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:32:47 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 15:36:19 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "../ft_string/ft_string.h"
#include <fcntl.h>
#include <unistd.h>

void	print_map_square(char *filename, t_map_config *config, t_map_square *square)
{
	int		is_first_line;
	int		i;
	int		j;
	int		fd;
	char	buffer;

	fd = open(filename, O_RDONLY);
	is_first_line = 1;
	i = 0;
	j = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (is_first_line && buffer == '\n')
			is_first_line = 0;
		else if (
			!is_first_line
			&& i >= square->i
			&& i <= square->i + square->size
			&& j >= square->j
			&& j <= square->j + square->size - 1
		)
			ft_putchar(config->full_character);
		else if (!is_first_line)
			ft_putchar(buffer);
		if (!is_first_line && buffer == '\n')
		{
			i++;
			j = 0;
		}
		else if (!is_first_line)
			j++;
	}
}
