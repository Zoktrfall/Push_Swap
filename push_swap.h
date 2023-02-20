#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_super {
	size_t				index;
	int					data;
}	t_super;

typedef struct s_stacks {
	struct s_stacks		*prev;
	size_t				index;
	int					value;
	struct s_stacks		*next;
}	t_stacks;

//Utilits
char		**ft_split(const char *s, char c);
int			ft_atoi(const char *str);
int			*f_cat(int **old_mas, int *new_mas, size_t len_new, size_t len_old);

//Correct Input
int			check_str(char **str);
int			correct_input(int arc, char **argv, int **old_mas, size_t *len_old);
int			str_number(char *str);
int			duplicate_check(int **old_mas, size_t len_old);

//Operators
void		push_swap(t_stacks **stack_one, t_stacks **stack_two);
t_stacks	*oper_sa_sb(t_stacks *stack);
t_stacks	*oper_ra_rb(t_stacks *stack);
t_stacks	*oper_rra_rrb(t_stacks *stack);

//Reproduce operation
void		do_pa(t_stacks **stack_b, t_stacks **stack_a);
void		do_pb(t_stacks **stack_a, t_stacks **stack_b);
void		do_ss(t_stacks **stack_a, t_stacks **stack_b);
void		do_sb(t_stacks **stack_b);
void		do_sa(t_stacks **stack_a);
void		do_rrr(t_stacks **stack_a, t_stacks **stack_b);
void		do_rrb(t_stacks **stack_b);
void		do_rra(t_stacks **stack_a);
void		do_rr(t_stacks **stack_a, t_stacks **stack_b);
void		do_rb(t_stacks **stack_b);
void		do_ra(t_stacks **stack_a);

//Creator
size_t		add_int(int **new_mas, char **str, int **old_mas);
t_stacks	*create_stack(int *old_mas, size_t len_old, t_stacks *stack_a);
t_stacks	*add_to_beg(t_stacks *stack, int value);
t_stacks	*add_to_end(t_stacks *stack, int value);
t_stacks	*add_to_empty(t_stacks *stack, int value);

//Super_mas
t_super		*create_super(t_super *str, t_stacks *stack_a);
t_super		*str_sort(t_super *str, size_t len_old);
t_super		*create_index(t_super *str, size_t len_old);
t_stacks	*search_add(t_super *str, t_stacks *stack_a, size_t len_old);
t_stacks	*add_index(t_stacks *stack_a, size_t len_old);

//Errors and Exits
void		emergency_exit(t_stacks **stack);
void		print_a_standard_error(void);
void		program_exit(int **old_mas);

//Frees
void		free_element(t_stacks **stack_one);
void		free_add_int(char **str, int **old_mas, int **new_mas);
void		free_old_new(int **old_mas, int *new_mas);
void		free_str(char **str);
t_stacks	*free_stack(t_stacks *stack);

#endif