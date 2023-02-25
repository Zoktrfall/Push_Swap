NAME = push_swap
FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

#Colors
RESET  = \033[0
RED    = \033[31m
GREEN  = \033[32m

all : $(NAME)

$(NAME) : $(OBJ) Makefile push_swap.h
	@gcc $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Push_Swap Is Ready To Run!$(RESET)"

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

clean : 
	@echo "$(RED)Deleting all object files.. $(RESET)"
	@rm -rf $(OBJ)

fclean : clean
	@echo "$(RED)Deleting $(NAME)... $(RESET)"
	@rm -rf $(NAME)

re : fclean $(NAME)
	@echo "$(GREEN)Updated Push_Swap$(RESET)"

.PHONY : re fclean clean all

# test:			$(NAME)	
# 				$(eval ARG = $(shell jot -r 100 0 20000000))
# 				./push_swap $(ARG) | ./checker_Mac $(ARG)
# 				@echo -n "Instructions: "
# 				@./push_swap $(ARG) | wc -l

#test_my:		$(NAME)	$(BONUS_NAME)
#				$(eval ARG = $(shell jot -r 100 0 2000000))
#				./push_swap $(ARG) | ./checker $(ARG)
#				@echo -n "Instructions: "
#				@./push_swap $(ARG) | wc -l
#				./push_swap $(ARG)
