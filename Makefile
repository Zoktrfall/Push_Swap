NAME = push_swap
FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ);

test:			$(NAME)	
				$(eval ARG = $(shell jot -r 500 0 2000000))
				./push_swap $(ARG) | ./checker_Mac $(ARG)
				@echo -n "Instructions: "
				@./push_swap $(ARG) | wc -l

#test_my:		$(NAME)	$(BONUS_NAME)
#				$(eval ARG = $(shell jot -r 100 0 2000000))
#				./push_swap $(ARG) | ./checker $(ARG)
#				@echo -n "Instructions: "
#				@./push_swap $(ARG) | wc -l
#				./push_swap $(ARG)
