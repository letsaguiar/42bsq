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
#include <stdio.h>

void	print_biggest_square(char **map, t_map *config, int max_i, int max_j, int size)
{
	int	i;
	int	j;

	i = max_i;
	while (i < max_i + size)
	{
		j = max_j;
		while (j < max_j + size)
		{
			map[i][j] = config->full_character;
			j++;
		}
		i++;
	}

	print_map(map);
}

void	generate_square_permutations(char **matrix, t_map *config)
{
	int max_size = 0;
	int	max_i;
	int	max_j;

	for (int size = 1; size <= config->line_counter && size <= config->line_length; size++) {
        for (int i = 0; i <= config->line_counter - size; i++) {
            for (int j = 0; j <= config->line_length - size; j++) {
                int isZeroSquare = 1;
                for (int x = i; x < i + size; x++) {
                    for (int y = j; y < j + size; y++) {
                        if (matrix[x][y] != config->empty_character) {
                            isZeroSquare = 0;
                            break;
                        }
                    }
                    if (!isZeroSquare) break;
                }
                if (isZeroSquare && size > max_size) {
                	max_size = size;
					max_i = i;
					max_j = j;
                }
            }
        }
    }

	print_biggest_square(matrix, config, max_i, max_j, max_size);
}

void	find_biggest_square(char **map, t_map *config)
{
	generate_square_permutations(map, config);
}
