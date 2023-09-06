/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-agui <lde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:48:21 by leticia-agu       #+#    #+#             */
/*   Updated: 2023/09/06 11:43:51 by lde-agui         ###   ########.fr       */
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

t_map_square	*get_warmest_square(char **map, t_map_config *config);

t_map_square	*build_map_square(t_map_square *square, int i, int j, int size);

t_map_config	*load_map_config(char *filename);

char			**load_map(char *filename, t_map_config *config);

int				validate_map(char *filename, t_map_config *config);

void			print_map(char **map);

void			print_map_square(
					char **map,
					t_map_config *config,
					t_map_square *square
					);

void			print_biggest_square(char **map, t_map_config *config);

void			destroy_map(char **map);


#endif
