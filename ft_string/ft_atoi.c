/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-aguiar <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:00:41 by leticia-aguia     #+#    #+#             */
/*   Updated: 2023/09/04 19:09:31 by leticia-aguia    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_atoi(char *str)
{
	unsigned int	i;
	int				result;

	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	result = 0;
	while (str[i])
	{
		if (is_numeric_char(str[i]))
			result = result * 10 + str[i] - 48;
		else
			break ;
		i++;
	}
	if (str[0] == '-')
		result *= -1;
	return (result);
}
