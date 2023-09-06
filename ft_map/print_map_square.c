/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:06:17 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 09:39:42 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	print_map_square(char **map, t_map_config *config, t_map_square *square)
{
	int	i;
	int	j;

	i = square->i;
	while (i < square->i + square->size)
	{
		j = square->j;
		while (j < square->j + square->size)
		{
			map[i][j] = config->full_character;
			j++;
		}
		i++;
	}
	print_map(map);
}
