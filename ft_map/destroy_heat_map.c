/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_heat_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:08:11 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 14:08:57 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdlib.h>

void	destroy_heat_map(int **heat_map, t_map_config *config)
{
	int i;

	i = 0;
	while (i < config->m)
	{
		free(heat_map[i]);
		i++;
	}
	free(heat_map);
}
