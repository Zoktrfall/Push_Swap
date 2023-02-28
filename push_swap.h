#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks {
	struct s_stacks		*prev;
	size_t				index;
	int					value;
	struct s_stacks		*next;
}	t_stacks;

//Utilities
char		**ft_split(const char *s, char c);
long long	ft_atoi(const char *str);
size_t		ft_strlen(char *str);
int			*ft_strcat(int **old_mas, int *new_mas, \
						size_t len_new, size_t len_old);

//Correct Input
int			fatal_mistake(t_stacks **stack_a);
int			consistently_check(t_stacks *stack_a, size_t len_old);
int			check_str(char **str);
int			correct_input(int arc, char **argv, int **old_mas, size_t *len_old);
int			str_number(char *str);
int			duplicate_check(int **old_mas, size_t len_old);
int			overflow_or_not(char *str);

//Sorting List
size_t		max(t_stacks **stack);
void		sorting_three(t_stacks **stack_a);
void		sorting_ten(t_stacks **stack_a, t_stacks **stack_b, size_t len_old);
void		more(t_stacks **stack_a, t_stacks **stack_b, size_t count);
void		less(t_stacks **stack_a, t_stacks **stack_b, size_t count);
t_stacks	*butterfly(size_t len_old, t_stacks **stack_a, t_stacks *stack_b);
void		less_b(t_stacks **stack_b, t_stacks **stack_a, size_t count);
void		more_b(t_stacks **stack_b, t_stacks **stack_a, size_t count);
void		sort_stack(t_stacks **stack_b, t_stacks **stack_a, size_t len_old);
t_stacks	*final_sort(t_stacks *stack_a, t_stacks **stack_b, size_t len_old);

//Operators
void		push_swap(t_stacks **stack1, t_stacks **stack2);
t_stacks	*oper_sa_sb(t_stacks *stack);
t_stacks	*oper_ra_rb(t_stacks *stack);
t_stacks	*oper_rra_rrb(t_stacks *stack);

//Find propriate 'n'
int			ideal_n(size_t len_old);
size_t		ft_ln(size_t nb);
size_t		ft_sqrt(size_t nb);

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
t_stacks	*add_to_beg(t_stacks *stack, int value, size_t index);
t_stacks	*add_to_end(t_stacks *stack, int value);
t_stacks	*add_to_empty(t_stacks *stack, int value, size_t index);

//Super_mas
int			*create_super(int *str, t_stacks *stack_a);
int			*str_sort(int *str, size_t len_old);
t_stacks	*add_index(t_stacks *stack_a, size_t len_old);
t_stacks	*search_add(int *str, t_stacks *stack_a, size_t len_old);

//Errors and Exits
void		emergency_exit(t_stacks **stack);
void		print_a_standard_error(void);
void		program_exit(int **old_mas);
void		overflow_error(int **old_mas, int **new_mas, char **str);

//Frees
void		free_element(t_stacks **stack_one);
void		free_add_int(char **str, int **old_mas, int **new_mas);
void		free_old_new(int **old_mas, int *new_mas);
void		free_str(char **str);
t_stacks	*free_stack(t_stacks *stack);

#endif