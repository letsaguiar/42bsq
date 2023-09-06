/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_heat_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:52:05 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 11:12:26 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "../ft_math/ft_math.h"
#include <stdio.h>
#include <stdlib.h>

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

int	**build_raw_heat_map(char **map, t_map_config *config)
{
	int	**heat_map;
	int	i;
	int	j;
	int	counter;

	heat_map = build_empty_heat_map(config);
	heat_map = populate_heat_map(heat_map, config);
	j = 0;
	while (j < config->n)
	{
		counter = 0;
		i = config->m - 1;
		while (i >= 0)
		{
			if (map[i][j] == config->empty_character)
				counter++;
			else
				counter = 0;
			heat_map[i][j] = counter;
			i--;
		}
		j++;
	}
	return (heat_map);
}

int	validate_heat_square(int **heat_map, t_map_square *square)
{
	int i;
	int j;

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

int	**build_heat_map(char **map, t_map_config *config)
{
	t_map_square	*current_square;
	int				**heat_map;
	int				i;
	int				j;

	current_square = (t_map_square *) malloc(sizeof (t_map_square));
	heat_map = build_raw_heat_map(map, config);
	i = 0;
	while (i < config->m)
	{
		j = 0;
		while (j < config->n)
		{
			current_square = build_map_square(current_square, i, j, 0);
			if (validate_heat_square(heat_map, current_square))
				j++;
			else
				heat_map[i][j] -= 1;
		}
		i++;
	}
	return (heat_map);
}
