FILES := \
	ft_map/build_map_square.c \
	ft_map/print_map_square.c \
	ft_map/ft_map.h \
	ft_map/print_heat_map.c \
	ft_map/validate_map.c \
	ft_map/build_heat_map.c \
	ft_map/destroy_heat_map.c \
	ft_map/build_map_config.c \
	ft_string/ft_string.h \
	ft_string/ft_putstr.c \
	ft_string/ft_putchar.c \
	ft_string/is_numeric_char.c \
	ft_string/ft_atoi.c \
	main.c
FLAGS := -Wall -Wextra -Werror

bsq: $(FILES)
	cc $(FLAGS) $(FILES) -o bsq

fclean:
	rm bsq
