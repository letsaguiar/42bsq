/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:36:40 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 10:01:26 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "../ft_math/ft_math.h"
#include <stdlib.h>

t_map_square	*build_map_square(t_map_square *square, int i, int j, int size)
{
	square->i = i;
	square->j = j;
	square->size = size;
	return (square);
}

int	is_empty_square(char **map, t_map_config *config, t_map_square *square)
{
	int	i;
	int	j;

	i = square->i;
	while (i < square->i + square->size)
	{
		j = square->j;
		while (j < square->j + square->size)
		{
			if (map[i][j] != config->empty_character)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_map_square	*find_biggest_square(char **map, t_map_config *config, int size)
{
	t_map_square	*biggest_square;
	t_map_square	*current_square;
	int				i;
	int				j;

	biggest_square = (t_map_square *) malloc(sizeof (t_map_square));
	current_square = (t_map_square *) malloc(sizeof (t_map_square));
	i = -1;
	while (++i <= config->m - size)
	{
		j = -1;
		while (++j <= config->n - size)
		{
			current_square = build_map_square(current_square, i, j, size);
			if (is_empty_square(map, config, current_square))
			{
				biggest_square = build_map_square(biggest_square, i, j, size);
				break ;
			}
		}
		if (biggest_square->size > 0)
			break ;
	}
	free(current_square);
	return (biggest_square);
}

t_map_square	*generate_square_permutations(char **map, t_map_config *config)
{
	t_map_square	*biggest_square;
	int				size;

	size = min(config->m, config->n);
	while (size >= 1)
	{
		biggest_square = find_biggest_square(map, config, size);
		if (biggest_square->size > 0)
			return (biggest_square);
		size--;
	}
	free(biggest_square);
	return (NULL);
}

void	print_biggest_square(char **map, t_map_config *config)
{
	t_map_square	*biggest_square;

	biggest_square = generate_square_permutations(map, config);
	print_map_square(map, config, biggest_square);
	free(biggest_square);
}
