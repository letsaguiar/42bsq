/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_heat_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:52:05 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 13:57:16 by lde-agui         ###   ########.fr       */
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
