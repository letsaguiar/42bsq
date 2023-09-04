/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-aguiar <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:00:41 by leticia-aguia     #+#    #+#             */
/*   Updated: 2023/09/04 19:03:08 by leticia-aguia    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + str[i] - 48;
		else
			break ;
		i++;
	}
	if (str[0] == '-')
		result *= -1;
	return (result);
}
