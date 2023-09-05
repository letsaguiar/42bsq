/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-aguiar <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:46:04 by leticia-aguia     #+#    #+#             */
/*   Updated: 2023/09/05 10:32:28 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_map/ft_map.h"
#include "ft_string/ft_string.h"

int	main(int argc, char **argv)
{
	t_map	*config;
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
		print_map(map);
		destroy_map(map);
		free(config);
	}
	return (0);
}
