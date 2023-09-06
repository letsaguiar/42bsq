/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:46:04 by leticia-agu       #+#    #+#             */
/*   Updated: 2023/09/06 14:11:52 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_map/ft_map.h"
#include "ft_string/ft_string.h"

void	process_map(char *filename)
{
	t_map_config	*config;
	int				**heat_map;

	config = build_map_config(filename);
	if (!validate_map(filename, config))
	{
		ft_putstr("map error");
	}
	else {
		heat_map = build_heat_map(filename, config);
		print_heat_map(heat_map, config);
		destroy_heat_map(heat_map, config);
	}
	ft_putstr("\n");
	free(config);
}

void	process_maps_from_args(char **maps)
{
	int				i;

	i = 1;
	while (maps[i])
	{
		process_map(maps[i]);
		i++;
	}
}

void	process_maps_from_stdi(void)
{
	int		i;
	char	buffer;
	char	filename[1024];

	i = 0;
	while (read(0, &buffer, 1) > 0)
	{
		if (buffer != '\n')
			filename[i++] = buffer;
		else
		{
			filename[i++] = '\0';
			process_map(filename);
			exit(0);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		process_maps_from_args(argv);
	else
		process_maps_from_stdi();
	return (0);
}
