NAME = push_swap
LIBFT = ./libft/libft.a
CFILES = atoi_overflow1.c atoi_overflow2.c main.c parsing1.c parsing2.c create_stacks.c create_stacks2.c sorting.c sort_small.c operations_1.c operations_2.c operations_3.c useful_functions.c
OFILES = $(CFILES:%.c=%.o)
HEADER = ./push_swap.h
LHEADER = ./libft/libft.h
FLAGS = -Wall -Wextra -Werror


.PHONY : all clean fclean re libfclean makelibft

all : $(NAME)

$(NAME) : $(OFILES) $(LIBFT) Makefile ./libft/Makefile
	cc $(FLAGS) $(OFILES) $(LIBFT) -o $(NAME)

$(LIBFT) :
	make -C  ./libft

makelibft : 
	make -C ./libft

%.o : %.c $(HEADER) $(LHEADER) Makefile ./libft/Makefile
	cc $(FLAGS) -c $< -o $@

$(LHEADER) : makelibft


clean : libfclean
	rm -f *.o

fclean : clean
	rm -f $(NAME) 

libfclean : 
	cd ./libft && make fclean

	
re : fclean all