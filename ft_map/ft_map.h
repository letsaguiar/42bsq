/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticia-aguiar <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:48:21 by leticia-aguia     #+#    #+#             */
/*   Updated: 2023/09/05 10:46:39 by lde-agui         ###   ########.fr       */
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

typedef struct s_map_square {
	int	i;
	int	j;
	int	size;
}	t_map_square;

t_map	*load_map_config(char *filename);

char	**load_map(char *filename, t_map *config);

int		validate_map(char *filename, t_map *config);

void	find_biggest_square(char **map, t_map *config);

void	print_map(char **map);

void	destroy_map(char **map);

#endif
