/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:46:04 by leticia-agu       #+#    #+#             */
/*   Updated: 2023/09/06 10:13:53 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_map/ft_map.h"
#include "ft_string/ft_string.h"

void	process_maps(char **maps)
{
	int				i;
	char			**map;
	t_map_config	*config;

	i = 1;
	while (maps[i])
	{
		config = load_map_config(maps[i]);
		if (!validate_map(maps[i], config))
		{
			ft_putstr("map error");
		}
		else
		{
			map = load_map(maps[i], config);
			print_biggest_square(map, config);
			destroy_map(map);
		}
		ft_putstr("\n");
		free(config);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		process_maps(argv);
	return (0);
}
