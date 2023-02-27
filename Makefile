NAME = push_swap
BONUS_NAME = checker
FLAGS = -Wall -Wextra -Werror

SRC = butterfly.c correct_input.c creator.c \
		errors_and_exits.c free_all.c ft_atoi.c \
		ft_split.c ft_strcat.c ft_strlen.c ideal_n.c \
		index_list.c operators.c pa_pb_operations.c push_swap.c \
		ra_rb_rr_operations.c rra_rrb_rrr_operations.c \
		sa_sb_ss_operations.c sequence_control.c three_to_twelve.c

SRC_BONUS = checker.c command_sorting.c correct_input.c creator.c errors_and_exits.c \
			free_all.c ft_atoi.c ft_split.c ft_strcat.c ft_strcmp.c \
			ft_strlen.c get_next_line.c get_next_line_utils.c index_list.c \
			operators.c reproduce_part1.c reproduce_part2.c reproduce_part3.c \
			reproduce_push.c sequence_control.c
 
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_BONUS = $(patsubst %.c, %.o, $(SRC_BONUS))

#Colors
RESET  = \033[0
RED    = \033[31m
GREEN  = \033[32m

all : $(NAME)

$(NAME) : $(OBJ) Makefile push_swap.h
	@gcc $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Push_Swap Is Ready To Run!$(RESET)"

bonus : $(BONUS_NAME) 

$(BONUS_NAME) : $(OBJ_BONUS) Makefile checker.h
	gcc $(FLAGS) $(OBJ_BONUS) -o $(BONUS_NAME)

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

clean : 
	@echo "$(RED)Deleting all object files.. $(RESET)"
	@rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	@echo "$(RED)Deleting $(NAME).. $(RESET)"
	@rm -rf $(NAME) $(BONUS_NAME)

re : fclean $(NAME)
	@echo "$(GREEN)Updated Push_Swap!$(RESET)"

.PHONY : re fclean clean all

test:			$(NAME)	
				$(eval ARG = $(shell jot -r 500 0 20000000))
				./push_swap $(ARG) | ./checker_Mac $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

test_my:		$(NAME)	$(BONUS_NAME)
				$(eval ARG = $(shell jot -r 500 0 2000000))
				./push_swap $(ARG) | ./checker $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l
#				./push_swap $(ARG)
