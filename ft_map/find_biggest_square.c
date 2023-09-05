/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:36:40 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/05 11:20:18 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdlib.h>

void	print_biggest_square(
	char **map,
	t_map *config,
	t_map_square *biggest_square
)
{
	int	i;
	int	j;

	i = biggest_square->i;
	while (i < biggest_square->i + biggest_square->size)
	{
		j = biggest_square->j;
		while (j < biggest_square->j + biggest_square->j)
		{
			map[i][j] = config->full_character;
			j++;
		}
		i++;
	}
	print_map(map);
}

int	is_empty_square(char **map, t_map *config, int i, int j, int size)
{
	int	x;
	int	y;

	x = i;
	while (x < i + size)
	{
		y = j;
		while (y < j + size)
		{
			if (map[x][y] != config->empty_character)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

t_map_square	*generate_square_permutations(char **matrix, t_map *config)
{
	t_map_square	*biggest_square;
	int				size;
	int				i;
	int				j;
	int				x;
	int				y;
	int				is_empty_square;

	biggest_square = (t_map_square *) malloc(sizeof (t_map_square));
	size = 1;
	while (size <= config->line_counter && size <= config->line_length)
	{
		i = 0;
		while (i <= config->line_counter - size)
		{
			j = 0;
			while (j <= config->line_length - size)
			{
				is_empty_square = 1;
				x = i;
				while (x < i + size)
				{
					y = j;
					while (y < j + size)
					{
						if (matrix[x][y] != config->empty_character)
						{
							is_empty_square = 0;
							break;
						}	
						y++;
					}
					if (!is_empty_square)
						break;
					x++;
				}
				if (is_empty_square && size > biggest_square->size)
				{
					biggest_square->size = size;
					biggest_square->i = i;
					biggest_square->j = j;
				}
				j++;
			}
			i++;
		}
		size++;
	}
	
	return (biggest_square);
}

void	find_biggest_square(char **map, t_map *config)
{
	t_map_square	*biggest_square;

	biggest_square = generate_square_permutations(map, config);
	print_biggest_square(map, config, biggest_square);
	free(biggest_square);
}

