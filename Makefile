FILES := main.c ft_map/*.c ft_string/*.c ft_math/*.c
FLAGS := -Wall -Wextra -Werror

bsq: $(FILES)
	cc $(FLAGS) $(FILES) -o bsq

fclean:
	rm bsq
