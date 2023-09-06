/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:36:40 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 11:44:14 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "../ft_math/ft_math.h"
#include <stdlib.h>

void	print_biggest_square(char **map, t_map_config *config)
{
	t_map_square	*biggest_square;

	biggest_square = get_warmest_square(map, config);
	print_map_square(map, config, biggest_square);
	free(biggest_square);
}
