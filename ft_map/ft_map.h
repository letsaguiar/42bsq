/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadantas <dadantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:48:21 by leticia-agu       #+#    #+#             */
/*   Updated: 2023/09/06 15:42:23 by dadantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct s_map_config {
	int		m;
	int		n;
	char	empty_character;
	char	obstacle_character;
	char	full_character;
}	t_map_config;

typedef struct s_map_square {
	int	i;
	int	j;
	int	size;
}	t_map_square;

t_map_square	*build_map_square(t_map_square *square, int i, int j, int size);

t_map_config	*build_map_config(char *filename);

int				validate_map(char *filename, t_map_config *config);

int				**build_heat_map(char *filename, t_map_config *config);

void			print_map_square(
					char *filename, t_map_config *config, t_map_square *square);

void			destroy_heat_map(int **heat_map, t_map_config *config);

t_map_square	*get_biggest_square(int	**heat_map, t_map_config *config);

#endif
