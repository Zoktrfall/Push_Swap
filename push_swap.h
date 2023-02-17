#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks {
	struct s_stacks		*prev;
	int					value;
	struct s_stacks		*next;
}	t_stacks;

//Utilits
char		**ft_split(const char *s, char c);
int			ft_atoi(const char *str);
int			*f_cat(int **old_mas, int *new_mas, size_t len_new, size_t len_old);

//Correct Input
int			check_str(char **str);
int			correct_input(char **argv, int **old_mas, size_t *len_old);
int			str_number(char *str);
int			duplicate_check(int **old_mas, size_t len_old);

//Creator
size_t		add_int(int **new_mas, char **str, int **old_mas);
t_stacks	*create_stack(int *old_mas, size_t len_old, t_stacks *stack_a);
t_stacks	*add_to_end(t_stacks *stack_a, int value);
t_stacks	*add_to_empty(t_stacks *stack_a, int value);

//Errors and Exits
void		print_a_standard_error(void);
void		program_exit(int **old_mas);

//Frees
void		free_add_int(char **str, int **old_mas, int **new_mas);
void		free_old_new(int **old_mas, int *new_mas);
void		free_str(char **str);
t_stacks	*free_stack_a(t_stacks *stack_a);

#endif