CC = cc
FLAGS = -Wall -Wextra -Werror
FILES = \
	ft_map/build_map_square.o \
	ft_map/print_map_square.o \
	ft_map/validate_map.o \
	ft_map/build_heat_map.o \
	ft_map/destroy_heat_map.o \
	ft_map/build_map_config.o \
	ft_string/ft_putstr.o \
	ft_string/ft_putchar.o \
	ft_string/is_numeric_char.o \
	ft_string/ft_atoi.o \
	main.o
TARGET = bsq

all: $(TARGET)

$(TARGET): $(FILES)
	$(CC) $(FLAGS) -o $(TARGET) $(FILES)

fclean:
	rm -f $(FILES) $(TARGET)
