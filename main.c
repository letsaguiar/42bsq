/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:46:04 by leticia-agu       #+#    #+#             */
/*   Updated: 2023/09/06 09:07:33 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_map/ft_map.h"
#include "ft_string/ft_string.h"

int	main(int argc, char **argv)
{
	t_map_config	*config;
	char	**map;

	if (argc > 1)
	{
		config = load_map_config(argv[1]);
		if (!validate_map(argv[1], config))
		{
			ft_putstr("map error\n");
			return (1);
		}
		map = load_map(argv[1], config);
		find_biggest_square(map, config);
		destroy_map(map);
		free(config);
	}
	return (0);
}
