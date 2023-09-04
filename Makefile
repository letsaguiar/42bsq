FILES := main.c
FLAGS := -Wall -Wextra -Werror

bsq: $(FILES)
	cc $(FLAGS) $(FILES) -o bsq

fclean:
	rm bsq
