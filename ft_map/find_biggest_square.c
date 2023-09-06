/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:36:40 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 11:16:50 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "../ft_math/ft_math.h"
#include <stdlib.h>

void	print_biggest_square(char **map, t_map_config *config)
{
	int				i;
	int				j;
	int				**heat_map;
	t_map_square	*biggest_square;

	heat_map = build_heat_map(map, config);
	biggest_square = (t_map_square *) malloc(sizeof (t_map_square));
	biggest_square->size = 0;
	i = 0;
	while (i < config->m)
	{
		j = 0;
		while (j < config->n)
		{
			if (heat_map[i][j] > biggest_square->size)
				biggest_square = build_map_square(biggest_square, i, j, heat_map[i][j]);
			j++;
		}
		i++;
	}
	print_map_square(map, config, biggest_square);
	free(biggest_square);
}
