/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_heat_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadantas <dadantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:52:05 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 15:42:04 by dadantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	**build_empty_heat_map(t_map_config *config)
{
	int	**heat_map;
	int	i;

	heat_map = malloc(config->m * sizeof (int *));
	i = 0;
	while (i < config->m)
	{
		heat_map[i] = malloc(config->n * sizeof (int));
		i++;
	}
	return (heat_map);
}

int	**populate_heat_map(int **heat_map, t_map_config *config)
{
	int	i;
	int	j;

	i = 0;
	while (i < config->m)
	{
		j = 0;
		while (j < config->n)
		{
			heat_map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (heat_map);
}

void	update_heat_map(int **heat_map, int i, int j)
{
	while (i >= 0 && heat_map[i][j] > 0)
	{
		heat_map[i][j]++;
		i--;
	}
}

int	**build_heat_map(char *filename, t_map_config *config)
{
	int		**heat_map;
	int		fd;
	int		i;
	int		j;
	int		is_first_line;
	char	buffer;

	heat_map = build_empty_heat_map(config);
	heat_map = populate_heat_map(heat_map, config);
	fd = open(filename, O_RDONLY);
	is_first_line = 1;
	i = 0;
	j = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (is_first_line && buffer == '\n')
			is_first_line = 0;
		else if (!is_first_line && buffer == config->empty_character)
		{
			heat_map[i][j] = 1;
			update_heat_map(heat_map, i - 1, j);
			j++;
		}
		else if (!is_first_line && buffer == config->obstacle_character)
		{
			j++;
		}
		else if (!is_first_line && buffer == '\n')
		{
			i++;
			j = 0;
		}
	}
	return (heat_map);
}

int	validate_heat_square(
		int **heat_map, t_map_config *config, t_map_square *square)
{
	int	i;
	int	j;

	if (heat_map[square->i][square->j] > config->n - square->j)
		return (0);
	i = square->i;
	j = square->j;
	while (j < square->j + heat_map[square->i][square->j] - 1)
	{
		if (heat_map[i][j] < heat_map[square->i][square->j])
			return (0);
		j++;
	}
	return (1);
}

t_map_square	*get_biggest_square(int **heat_map, t_map_config *config)
{
	t_map_square	*current_square;
	t_map_square	*biggest_square;
	int				i;
	int				j;

	biggest_square = (t_map_square *) malloc(sizeof (t_map_square));
	biggest_square->size = 0;
	current_square = (t_map_square *) malloc(sizeof (t_map_square));
	i = 0;
	while (i < config->m)
	{
		j = 0;
		while (j < config->n)
		{
			current_square = build_map_square(current_square, i, j, 0);
			if (validate_heat_square(heat_map, config, current_square))
			{
				if (heat_map[i][j] > biggest_square->size)
					biggest_square = build_map_square(
							biggest_square, i, j, heat_map[i][j]);
				j++;
			}
			else
				heat_map[i][j] -= 1;
		}
		i++;
	}
	free(current_square);
	return (biggest_square);
}
