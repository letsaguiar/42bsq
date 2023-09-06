/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_heat_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:06:33 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 14:07:57 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdio.h>

void	print_heat_map(int **heat_map, t_map_config *config)
{
	int i;
	int j;

	i = 0;
	while (i < config->m)
	{
		j = 0;
		while (j < config->n)
		{
			printf("%d ", heat_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
