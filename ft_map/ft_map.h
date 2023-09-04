/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-aguiar <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:48:21 by leticia-aguia     #+#    #+#             */
/*   Updated: 2023/09/04 19:16:02 by leticia-aguia    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct s_map {
	int		line_counter;
	int		line_length;
	char	empty_character;
	char	obstacle_character;
	char	full_character;
}	t_map;

t_map	*load_map(char *filename);

#endif
