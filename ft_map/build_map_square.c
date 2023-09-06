/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:06:38 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 11:06:47 by lde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

t_map_square	*build_map_square(t_map_square *square, int i, int j, int size)
{
	square->i = i;
	square->j = j;
	square->size = size;
	return (square);
}
