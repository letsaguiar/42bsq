/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-aguiar <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:46:04 by leticia-aguia     #+#    #+#             */
/*   Updated: 2023/09/04 19:46:13 by leticia-aguia    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_map/ft_map.h"
#include "ft_string/ft_string.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc >  1)
	{
		map = load_map(argv[1]);
		if (!validate_map(argv[1], map))
		{
			ft_putstr("map error\n");
			return (1);
		}
		free(map);
	}
	return (0);
}
